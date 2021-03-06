/**
 */

#include <cstdio>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

#include "branch_pred.h"
#include "debug.h"
#include "ins_helper.h"
#include "instlib.H"
#include "libdft_api.h"
#include "pin.H"
#include "syscall_hook.h"

INSTLIB::FILTER filter;

FILE *_gtlog = stdout;

void gtlog(const char *fmt, ...) {
    static char buff[1024];
    size_t written;

    va_list args;
    va_start(args, fmt);
    written = vsnprintf(buff, sizeof(buff), fmt, args);
    va_end(args);

    if (written >= sizeof(buff)) {
        buff[sizeof(buff) - 1] = 0;
    }
    const char *e = buff + strlen(buff);
    char *p = buff;
    char *lf = nullptr;
    while (p < e) {
        for (lf = p; *lf != '\n' && *lf != 0; ++lf)
            ;
        if (*lf != 0)
            ++lf;
        fprintf(_gtlog, "__ ");
        fwrite(p, 1, lf - p, _gtlog);
        p = lf;
    }

    fflush(_gtlog); // @suppress("Ambiguous problem")
}

KNOB<bool> KnobDumpStubs(KNOB_MODE_WRITEONCE, "pintool", "dump_stubs", "",
                         "dump stubs to control gtaint from the target");

std::list<std::string> image_filters;

KNOB<std::string> KnobFilterImages(KNOB_MODE_APPEND, "pintool", "filter_img", "",
                                   "Images to instrument (images containing these substrings)");

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
enum struct ht { reg, memaddr, memsize };

// minimal traits, convert ht enum to type
template <ht h>
struct ht_tr;

template <>
struct ht_tr<ht::reg> {
    using type = REG;
};

template <>
struct ht_tr<ht::memsize> {
    using type = uint32_t;
};

template <>
struct ht_tr<ht::memaddr> {
    using type = ADDRINT;
};

template <ht...>
struct handler;

template <>
struct handler<ht::reg> {
    static inline void handle(THREADID tid, void *ins_addr, REG reg) {
        UINT32 regsz = REG_Size(static_cast<REG>(reg));
        tag_t t = tagmap_getn_reg(tid, reg);
        if (!tag_is_empty(t)) {
            gtlog("%p reg: %d/%d, lb: %d, taint: %s\n", ins_addr, reg, regsz, t, tag_sprint(t).c_str());
        }
    }
};

template <>
struct handler<ht::memaddr, ht::memsize> {
    static inline void handle(THREADID tid, void *ins_addr, ADDRINT addr, uint32_t memsz) {
        tag_t t = tagmap_getn(addr, memsz);
        if (!tag_is_empty(t)) {
            gtlog("%p addr: %p/%d, lb: %d, taint: %s\n", ins_addr, (void *)addr, memsz, t, tag_sprint(t).c_str());
        }
    }
};

template <ht... hts>
struct handler<ht::reg, hts...> {
    static inline void handle(THREADID tid, void *ins_addr, REG reg, typename ht_tr<hts>::type... rest) {
        handler<ht::reg>::handle(tid, ins_addr, reg);
        handler<hts...>::handle(tid, ins_addr, rest...);
    }
};

template <ht... hts>
struct handler<ht::memaddr, ht::memsize, hts...> {
    static inline void handle(THREADID tid, void *ins_addr, ADDRINT addr, uint32_t memsz,
                              typename ht_tr<hts>::type... rest) {
        handler<ht::memaddr, ht::memsize>::handle(tid, ins_addr, addr, memsz);
        handler<hts...>::handle(tid, ins_addr, rest...);
    }
};

static unsigned int last_tainted = 0;
extern tag_dir_t tag_dir;
static void on_gtaint_reset() {
    gtlog("taint reset\n");

    last_tainted = 0;
    for (tag_table_t *table : tag_dir.table) {
        if (table != nullptr) {
            for (tag_page_t *page : table->page) {
                if (page != nullptr) {
                    std::fill(page->tag, page->tag + PAGE_SIZE, tag_traits<tag_t>::cleared_val);
                }
            }
        }
    }
}

static void on_gtaint_setb(void *p) {
    tagmap_setb((ADDRINT)p, tag_alloc<tag_t>(last_tainted));
    gtlog("set taint at %p to %d\n", p, last_tainted);
    ++last_tainted;
}

static void on_gtaint_setn(void *p, unsigned int n) {
    for (unsigned int i = 0; i < n; ++i) {
        tagmap_setb((ADDRINT)p + i, tag_alloc<tag_t>(last_tainted + i));
    }
    gtlog("set taint of %d bytes at %p to %d-%d\n", n, p, last_tainted, last_tainted + n - 1);
    last_tainted += n;
}

static void on_gtaint_assert(void *addr, unsigned int memsz, char *assertion, int *result) {
    gtlog("assert %d bytes at %p tainted as %s\n", memsz, addr, assertion);
    tag_t t = tagmap_getn((ADDRINT)addr, memsz);

    std::string actual = tag_sprint(t);
    if (actual.compare(assertion) == 0) {
        *result = 1;
    } else {
        gtlog("  failed!  actual: \"%s\"\n", actual.c_str());
        *result = 0;
    }
}

static int gtaint_equals(void *addr, size_t memsz, uint32_t *ordered_list, size_t n) {
    tag_t t = tagmap_getn((ADDRINT)addr, memsz);
    std::vector<tag_seg> s = tag_get(t);
    std::vector<tag_seg>::iterator seg = s.begin();
    size_t i = 0;
    while (i < n) {
        if (seg == s.end())
            return 0;
        for (tag_off x = seg->begin; x < seg->end; ++x) {
            if (i >= n || ordered_list[i++] != x) {
                return 0;
            }
        }
        ++seg;
    }
    return seg == s.end();
}
const char *gtaint_getb_str(volatile void *addr) {
    static char buffs[10][1024];
    static int lastbuff = -1;
    tag_t t = tagmap_getb((ADDRINT)addr);
    std::vector<tag_seg> s = tag_get(t);

    lastbuff = (lastbuff + 1) % 10;

    char *buff = buffs[lastbuff];
    strncpy(buff, tag_sprint(t).c_str(), 1024);
    return buff;
}

// @formatter:off
// clang-format off

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
    // gtlog( "reader %d %d %d: %p %s\n", memind, reg1ind, reg2ind, (void*) INS_Address(ins), INS_Disassemble(ins).c_str());
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

static void instrument_ret(INS ins) {
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR) handler<ht::reg>::handle,
        IARG_THREAD_ID,
        IARG_INST_PTR,
        IARG_UINT32, X64_RET_REG,
        IARG_END);
}

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
            // gtlog( "branch: %p %s\n", (void*) INS_Address(ins), INS_Disassemble(ins).c_str());
            INS prev_ins = INS_Prev(ins);
            if (INS_Valid(prev_ins)) {
                switch (INS_Opcode(prev_ins)) {
                case XED_ICLASS_CMP:
                case XED_ICLASS_TEST:
                    break;
                default:
                    instrument_reads(prev_ins);
                    // gtlog( "pre-branch: %p %s\n", (void*) INS_Address(pins), INS_Disassemble(pins).c_str());
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

    if (KnobFilterImages.NumberOfValues() > 0) {
        RTN rtn = TRACE_Rtn(trace);
        if (!RTN_Valid(rtn))
            return;
        SEC sec = RTN_Sec(rtn);
        if (!SEC_Valid(sec))
            return;
        IMG img = SEC_Img(sec);
        if (!IMG_Valid(img))
            return;
        bool ok = false;
        std::string img_name = IMG_Name(img);
        for (unsigned int i = 0; i < KnobFilterImages.NumberOfValues(); ++i) {
            if (img_name.find(KnobFilterImages.Value(i)) != std::string::npos) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            return;
        }
    }

    for (BBL bbl = TRACE_BblHead(trace); BBL_Valid(bbl); bbl = BBL_Next(bbl)) {
        for (INS ins = BBL_InsHead(bbl); INS_Valid(ins); ins = INS_Next(ins)) {
            instrument_instruction(ins, 0);
        }
    }
}

static void on_application_start(void *v) {
    RTN rtn;
    for (IMG img = APP_ImgHead(); IMG_Valid(img); img = IMG_Next(img)) {
        rtn = RTN_FindByName(img, "__gtaint_reset");
        if (RTN_Valid(rtn)) {
            gtlog( "Found __gtaint_reset\n");
            RTN_Open(rtn);
            RTN_InsertCall(rtn, IPOINT_BEFORE,
                    (AFUNPTR) on_gtaint_reset,
                    IARG_END);
            RTN_Close(rtn);
        }

        rtn = RTN_FindByName(img, "__gtaint_setb");
        if (RTN_Valid(rtn)) {
            gtlog( "Found __gtaint_setb\n");
            RTN_Open(rtn);
            RTN_InsertCall(rtn, IPOINT_BEFORE,
                    (AFUNPTR) on_gtaint_setb,
                    IARG_FUNCARG_ENTRYPOINT_VALUE, 0,
                    IARG_END);
            RTN_Close(rtn);
        }

        rtn = RTN_FindByName(img, "__gtaint_setn");
        if (RTN_Valid(rtn)) {
            gtlog("Found __gtaint_setb\n");
            RTN_Open(rtn);
            RTN_InsertCall(rtn, IPOINT_BEFORE,
                    (AFUNPTR) on_gtaint_setn,
                    IARG_FUNCARG_ENTRYPOINT_VALUE, 0,
                    IARG_FUNCARG_ENTRYPOINT_VALUE, 1,
                    IARG_END);
            RTN_Close(rtn);
        }
        rtn = RTN_FindByName(img, "__gtaint_assert");
        if (RTN_Valid(rtn)) {
            gtlog("Found __gtaint_assert\n");
            RTN_Open(rtn);
            RTN_InsertCall(rtn, IPOINT_BEFORE,
                    (AFUNPTR) on_gtaint_assert,
                    IARG_FUNCARG_ENTRYPOINT_VALUE, 0,
                    IARG_FUNCARG_ENTRYPOINT_VALUE, 1,
                    IARG_FUNCARG_ENTRYPOINT_VALUE, 2,
                    IARG_FUNCARG_ENTRYPOINT_VALUE, 3,
                    IARG_END);
            RTN_Close(rtn);
        }
        rtn = RTN_FindByName(img, "__gtaint_equals");
        if (RTN_Valid(rtn)) {
            gtlog("Found __gtaint_equals\n");
            RTN_Open(rtn);
            RTN_Replace(rtn, (AFUNPTR)gtaint_equals);
            RTN_Close(rtn);
        }

        rtn = RTN_FindByName(img, "__gtaint_getb_str");
        if (RTN_Valid(rtn)) {
            gtlog("Found __gtaint_getb_str\n");
            RTN_Open(rtn);
            RTN_Replace(rtn, (AFUNPTR)gtaint_getb_str);
            RTN_Close(rtn);
        }

    }
}
// @formatter:on
// clang-format on

static void instrument_load(IMG img, void *v) {
    gtlog("loaded: %s  offset %p\n", IMG_Name(img).c_str(), (void *)IMG_LoadOffset(img));
    for (UINT32 n = 0; n < IMG_NumRegions(img); ++n) {
        gtlog("  region %d %p-%p\n", n, IMG_RegionLowAddress(img, n), IMG_RegionHighAddress(img, n));
    }
}
static void instrument_unload(IMG img, void *v) {
    gtlog("unloaded: %s\n", IMG_Name(img).c_str());
}

int main(int argc, char *argv[]) {
    if (unlikely(PIN_Init(argc, argv))) {
        std::cout << KNOB_BASE::StringKnobSummary() << std::endl;
        return -1;
    }

    if (KnobDumpStubs.Value()) {
        std::cout << R"EOT(
extern "C" {

// reset tagmap
void *__attribute__((optimize("O0"))) __gtaint_reset() {
    return nullptr; // clear rax
}

// set a new tag at the given address
void __attribute__((optimize("O0"))) __gtaint_setb(const void *addr) {
}

// set n new tags starting at the given address
void __attribute__((optimize("O0"))) __gtaint_setn(const void *addr, unsigned int n) {
}



// get the tag set at the given address
const char *__attribute__((optimize("O0"))) __gtaint_getb_str(volatile void *addr) {
	return nullptr;
}

// return 1 if the sets of tags on [addr, addr+memsz) equals the tages in the ordered list of length n
int __attribute__((optimize("O0"))) __gtaint_equals(void *addr, size_t memsz, uint32_t *ordered_list, size_t n) {
	return 0;
}

}
)EOT";
        return 0;
    }

    PIN_InitSymbols();

    if (unlikely(libdft_init() != 0)) {
        std::cerr << "error in libdft_init." << std::endl;
        return -1;
    }

    IMG_AddInstrumentFunction(instrument_load, 0);
    IMG_AddUnloadFunction(instrument_unload, 0);

    PIN_AddApplicationStartFunction(on_application_start, 0);
    TRACE_AddInstrumentFunction(instrument_trace, 0);

    filter.Activate();
    hook_file_syscall();

    PIN_StartProgram();

    return 0;
}
