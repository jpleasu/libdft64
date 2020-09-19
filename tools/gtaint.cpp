/**
 */

#include "pin.H"
#include "instlib.H"

#include "branch_pred.h"
#include "debug.h"
#include "libdft_api.h"
#include "syscall_hook.h"

#include <iostream>
#include <cstdio>
#include "ins_helper.h"

INSTLIB::FILTER filter;

// handle partial registers
inline size_t REG_OFFSET(REG reg) {
	switch (static_cast<int>(reg)) {
	case REG_AH:
	case REG_BH:
	case REG_CH:
	case REG_DH:
		return 1;
	}
	return 0;
}

// convert from REG to reg_index used by libdft
tag_t tagmap_getn_reg(THREADID tid, REG reg) {
	size_t reg_idx = REG_INDX(reg);
	size_t n = REG_Size(reg);
	size_t o = REG_OFFSET(reg);

	tag_t ts = tag_traits<tag_t>::cleared_val;
	for (size_t i = o; i < n; i++) {
		const tag_t t = tagmap_getb_reg(tid, reg_idx, i);
		if (tag_is_empty(t))
			continue;
		ts = tag_combine(ts, t);
	}
	return ts;
}

// generic sink handlers
enum struct ht {
	reg, memaddr, memsize
};

// minimal traits, convert ht enum to type
template<ht h>
struct ht_tr;

template<>
struct ht_tr<ht::reg> {
	using type = REG;
};

template<>
struct ht_tr<ht::memsize> {
	using type = uint32_t;
};

template<>
struct ht_tr<ht::memaddr> {
	using type = ADDRINT;
};

template<ht...>
struct handler;

template<>
struct handler<ht::reg> {
	static inline void handle(THREADID tid, void *ins_addr, REG reg) {
		UINT32 regsz = REG_Size(static_cast<REG>(reg));
		tag_t t = tagmap_getn_reg(tid, reg);
		if (!tag_is_empty(t)) {
			printf("%p reg: %d/%d, lb: %d, taint: %s\n", ins_addr, reg, regsz,
					t, tag_sprint(t).c_str());
			fflush(stdout); // @suppress("Ambiguous problem")
		}
	}
};

template<>
struct handler<ht::memaddr, ht::memsize> {
	static inline void handle(THREADID tid, void *ins_addr, ADDRINT addr,
			uint32_t memsz) {
		tag_t t = tagmap_getn(addr, memsz);
		if (!tag_is_empty(t)) {
			printf("%p addr: %p/%d, lb: %d, taint: %s\n", ins_addr,
					(void*) addr, memsz, t, tag_sprint(t).c_str());
			fflush(stdout); // @suppress("Ambiguous problem")
		}
	}
};

template<ht ... hts>
struct handler<ht::reg, hts...> {
	static inline void handle(THREADID tid, void *ins_addr, REG reg,
			typename ht_tr<hts>::type ... rest) {
		handler<ht::reg>::handle(tid, ins_addr, reg);
		handler<hts...>::handle(tid, ins_addr, rest...);
	}
};

template<ht ... hts>
struct handler<ht::memaddr, ht::memsize, hts...> {
	static inline void handle(THREADID tid, void *ins_addr, ADDRINT addr,
			uint32_t memsz, typename ht_tr<hts>::type ... rest) {
		handler<ht::memaddr, ht::memsize>::handle(tid, ins_addr, addr, memsz);
		handler<hts...>::handle(tid, ins_addr, rest...);
	}
};

// @formatter:off
static void instrument_ret(INS ins) {
	INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR) handler<ht::reg>::handle,
			IARG_THREAD_ID,
			IARG_INST_PTR,
			IARG_UINT32, X64_RET_REG,
			IARG_END);
}


// general operand sink
static void instrument_reads(INS ins) {
	int memind=-1;
	int reg1ind=-1;
	int reg2ind=-1;
	for(UINT32 i=0;i<INS_OperandCount(ins);++i) {
		if(!INS_OperandRead(ins, i))
			continue;
		if(INS_OperandIsMemory(ins, i))
			memind=i;
		else if(INS_OperandIsReg(ins, i)) {
			if(reg1ind==-1)
				reg1ind=i;
			else
				reg2ind=i;
		}
	}
	// printf("reader %d %d %d: %p %s\n", memind, reg1ind, reg2ind, (void*) INS_Address(ins), INS_Disassemble(ins).c_str());
	if(reg1ind>=0 && memind>=0) {
		INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR) handler<ht::reg, ht::memaddr, ht::memsize>::handle,
				IARG_THREAD_ID,
				IARG_INST_PTR,
				IARG_UINT32, INS_OperandReg(ins, reg1ind),
				IARG_MEMORYREAD_EA,
				IARG_MEMORYREAD_SIZE,
				IARG_END);
	} else if(reg1ind>=0 && reg2ind>=0 && reg1ind!=reg2ind) {
		INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR) handler<ht::reg, ht::reg>::handle,
				IARG_THREAD_ID,
				IARG_INST_PTR,
				IARG_UINT32, INS_OperandReg(ins, reg1ind),
				IARG_UINT32, INS_OperandReg(ins, reg2ind),
				IARG_END);
	} else if(reg1ind>=0) {
		INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR) handler<ht::reg>::handle,
				IARG_THREAD_ID,
				IARG_INST_PTR,
				IARG_UINT32, INS_OperandReg(ins, reg1ind),
				IARG_END);
	} else if (memind>=0) {
		INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR) handler<ht::memaddr, ht::memsize>::handle,
				IARG_THREAD_ID,
				IARG_INST_PTR,
				IARG_MEMORYREAD_EA,
				IARG_MEMORYREAD_SIZE,
				IARG_END);
	}
}
// @formatter:on

static void instrument_instruction(INS ins, void *v) {
	switch (INS_Opcode(ins)) {
	case XED_ICLASS_TEST:
	case XED_ICLASS_CMP:
		instrument_reads(ins);
		break;
	case XED_ICLASS_RET_NEAR:
		instrument_ret(ins);
		break;
	default:
		// instrument (valid) instruction before each branch
		if (INS_IsBranch(ins) && INS_HasFallThrough(ins)) {
			// printf("branch: %p %s\n", (void*) INS_Address(ins), INS_Disassemble(ins).c_str());
			INS prev_ins = INS_Prev(ins);
			if (INS_Valid(prev_ins)) {
				switch (INS_Opcode(prev_ins)) {
				case XED_ICLASS_CMP:
				case XED_ICLASS_TEST:
					break;
				default:
					instrument_reads(prev_ins);
					// printf("pre-branch: %p %s\n", (void*) INS_Address(pins), INS_Disassemble(pins).c_str());
					fflush(stdout); // @suppress("Ambiguous problem")
					break;
				}

			}
		}
		break;
	}
}

static void instrument_trace(TRACE trace, void *v) {
	if (!filter.SelectTrace(trace))
		return;

	for (BBL bbl = TRACE_BblHead(trace); BBL_Valid(bbl); bbl = BBL_Next(bbl)) {
		for (INS ins = BBL_InsHead(bbl); INS_Valid(ins); ins = INS_Next(ins)) {
			instrument_instruction(ins, 0);
		}
	}
}

int main(int argc, char *argv[]) {
	PIN_InitSymbols();

	if (unlikely(PIN_Init(argc, argv))) {
		std::cerr << KNOB_BASE::StringKnobSummary() << std::endl;
		return -1;
	}

	if (unlikely(libdft_init() != 0)) {
		std::cerr << "error in libdft_init." << std::endl;
		return -1;
	}

	TRACE_AddInstrumentFunction(instrument_trace, 0);

	filter.Activate();
	hook_file_syscall();

	PIN_StartProgram();

	return 0;
}
