
#ifndef __INS_HELPER_H__
#define __INS_HELPER_H__

#include "debug.h"
#include "pin.H"

#include "branch_pred.h"
#include "libdft_api.h"
#include "tagmap.h"

#define OP_0 0 /* 0th (1st) operand index */
#define OP_1 1 /* 1st (2nd) operand index */
#define OP_2 2 /* 2nd (3rd) operand index */
#define OP_3 3 /* 3rd (4th) operand index */
#define OP_4 4 /* 4th (5th) operand index */
#define MEM_64BIT_LEN 64
#define MEM_LONG_LEN 32            /* long size (32-bit) */
#define MEM_WORD_LEN 16            /* word size (16-bit) */
#define MEM_BYTE_LEN 8             /* byte size (8-bit) */
#define BIT2BYTE(len) ((len) >> 3) /* scale change; macro */
#define EFLAGS_DF(eflags) ((eflags & 0x0400))

extern thread_ctx_t *threads_ctx;
#define RTAG threads_ctx[tid].vcpu.gpr

#define R8TAG(RIDX)                                                                                                    \
    { RTAG[(RIDX)][0] }
#define R16TAG(RIDX)                                                                                                   \
    { RTAG[(RIDX)][0], RTAG[(RIDX)][1] }
#define R32TAG(RIDX)                                                                                                   \
    { RTAG[(RIDX)][0], RTAG[(RIDX)][1], RTAG[(RIDX)][2], RTAG[(RIDX)][3] }
#define R64TAG(RIDX)                                                                                                   \
    {                                                                                                                  \
        RTAG[(RIDX)][0], RTAG[(RIDX)][1], RTAG[(RIDX)][2], RTAG[(RIDX)][3], RTAG[(RIDX)][4], RTAG[(RIDX)][5],          \
            RTAG[(RIDX)][6], RTAG[(RIDX)][7]                                                                           \
    }
#define R128TAG(RIDX)                                                                                                  \
    {                                                                                                                  \
        RTAG[(RIDX)][0], RTAG[(RIDX)][1], RTAG[(RIDX)][2], RTAG[(RIDX)][3], RTAG[(RIDX)][4], RTAG[(RIDX)][5],          \
            RTAG[(RIDX)][6], RTAG[(RIDX)][7], RTAG[(RIDX)][8], RTAG[(RIDX)][9], RTAG[(RIDX)][10], RTAG[(RIDX)][11],    \
            RTAG[(RIDX)][12], RTAG[(RIDX)][13], RTAG[(RIDX)][14], RTAG[(RIDX)][15]                                     \
    }
#define R256TAG(RIDX)                                                                                                  \
    {                                                                                                                  \
        RTAG[(RIDX)][0], RTAG[(RIDX)][1], RTAG[(RIDX)][2], RTAG[(RIDX)][3], RTAG[(RIDX)][4], RTAG[(RIDX)][5],          \
            RTAG[(RIDX)][6], RTAG[(RIDX)][7], RTAG[(RIDX)][8], RTAG[(RIDX)][9], RTAG[(RIDX)][10], RTAG[(RIDX)][11],    \
            RTAG[(RIDX)][12], RTAG[(RIDX)][13], RTAG[(RIDX)][14], RTAG[(RIDX)][15], RTAG[(RIDX)][16],                  \
            RTAG[(RIDX)][17], RTAG[(RIDX)][18], RTAG[(RIDX)][19], RTAG[(RIDX)][20], RTAG[(RIDX)][21],                  \
            RTAG[(RIDX)][22], RTAG[(RIDX)][23], RTAG[(RIDX)][24], RTAG[(RIDX)][25], RTAG[(RIDX)][26],                  \
            RTAG[(RIDX)][27], RTAG[(RIDX)][28], RTAG[(RIDX)][29], RTAG[(RIDX)][30], RTAG[(RIDX)][31]                   \
    }

#define MTAG(ADDR) tagmap_getb((ADDR))
#define M8TAG(ADDR)                                                                                                    \
    { tagmap_getb((ADDR)) }
#define M16TAG(ADDR)                                                                                                   \
    { MTAG(ADDR), MTAG(ADDR + 1) }
#define M32TAG(ADDR)                                                                                                   \
    { MTAG(ADDR), MTAG(ADDR + 1), MTAG(ADDR + 2), MTAG(ADDR + 3) }
#define M64TAG(ADDR)                                                                                                   \
    {                                                                                                                  \
        MTAG(ADDR), MTAG(ADDR + 1), MTAG(ADDR + 2), MTAG(ADDR + 3), MTAG(ADDR + 4), MTAG(ADDR + 5), MTAG(ADDR + 6),    \
            MTAG(ADDR + 7)                                                                                             \
    }
#define M128TAG(ADDR)                                                                                                  \
    {                                                                                                                  \
        MTAG(ADDR), MTAG(ADDR + 1), MTAG(ADDR + 2), MTAG(ADDR + 3), MTAG(ADDR + 4), MTAG(ADDR + 5), MTAG(ADDR + 6),    \
            MTAG(ADDR + 7), MTAG(ADDR + 8), MTAG(ADDR + 9), MTAG(ADDR + 10), MTAG(ADDR + 11), MTAG(ADDR + 12),         \
            MTAG(ADDR + 13), MTAG(ADDR + 14), MTAG(ADDR + 15)                                                          \
    }

#define M256TAG(ADDR)                                                                                                  \
    {                                                                                                                  \
        MTAG(ADDR), MTAG(ADDR + 1), MTAG(ADDR + 2), MTAG(ADDR + 3), MTAG(ADDR + 4), MTAG(ADDR + 5), MTAG(ADDR + 6),    \
            MTAG(ADDR + 7), MTAG(ADDR + 8), MTAG(ADDR + 9), MTAG(ADDR + 10), MTAG(ADDR + 11), MTAG(ADDR + 12),         \
            MTAG(ADDR + 13), MTAG(ADDR + 14), MTAG(ADDR + 15), MTAG(ADDR + 16), MTAG(ADDR + 17), MTAG(ADDR + 18),      \
            MTAG(ADDR + 19), MTAG(ADDR + 20), MTAG(ADDR + 21), MTAG(ADDR + 22), MTAG(ADDR + 23), MTAG(ADDR + 24),      \
            MTAG(ADDR + 25), MTAG(ADDR + 26), MTAG(ADDR + 27), MTAG(ADDR + 28), MTAG(ADDR + 29), MTAG(ADDR + 30),      \
            MTAG(ADDR + 31),                                                                                           \
    }

// https://software.intel.com/sites/landingpage/pintool/docs/97619/Pin/html/group__REG__CPU__IA32.html
inline size_t REG_INDX(REG reg) {
    if (reg == REG_INVALID())
        return GRP_NUM;
    switch (reg) {
    case REG_RDI:
    case REG_EDI:
    case REG_DI:
    case REG_DIL:
        return DFT_REG_RDI;
        break;
    case REG_RSI:
    case REG_ESI:
    case REG_SI:
    case REG_SIL:
        return DFT_REG_RSI;
        break;
    case REG_RBP:
    case REG_EBP:
    case REG_BP:
    case REG_BPL:
        return DFT_REG_RBP;
        break;
    case REG_RSP:
    case REG_ESP:
    case REG_SP:
    case REG_SPL:
        return DFT_REG_RSP;
        break;
    case REG_RAX:
    case REG_EAX:
    case REG_AX:
    case REG_AH:
    case REG_AL:
        return DFT_REG_RAX;
        break;
    case REG_RBX:
    case REG_EBX:
    case REG_BX:
    case REG_BH:
    case REG_BL:
        return DFT_REG_RBX;
        break;
    case REG_RCX:
    case REG_ECX:
    case REG_CX:
    case REG_CH:
    case REG_CL:
        return DFT_REG_RCX;
        break;
    case REG_RDX:
    case REG_EDX:
    case REG_DX:
    case REG_DH:
    case REG_DL:
        return DFT_REG_RDX;
        break;
    case REG_R8:
    case REG_R8D:
    case REG_R8W:
    case REG_R8B:
        return DFT_REG_R8;
        break;
    case REG_R9:
    case REG_R9D:
    case REG_R9W:
    case REG_R9B:
        return DFT_REG_R9;
        break;
    case REG_R10:
    case REG_R10D:
    case REG_R10W:
    case REG_R10B:
        return DFT_REG_R10;
        break;
    case REG_R11:
    case REG_R11D:
    case REG_R11W:
    case REG_R11B:
        return DFT_REG_R11;
        break;
    case REG_R12:
    case REG_R12D:
    case REG_R12W:
    case REG_R12B:
        return DFT_REG_R12;
        break;
    case REG_R13:
    case REG_R13D:
    case REG_R13W:
    case REG_R13B:
        return DFT_REG_R13;
        break;
    case REG_R14:
    case REG_R14D:
    case REG_R14W:
    case REG_R14B:
        return DFT_REG_R14;
        break;
    case REG_R15:
    case REG_R15D:
    case REG_R15W:
    case REG_R15B:
        return DFT_REG_R15;
        break;
    case REG_XMM0:
    case REG_YMM0:
        return DFT_REG_XMM0;
        break;
    case REG_XMM1:
    case REG_YMM1:
        return DFT_REG_XMM1;
        break;
    case REG_XMM2:
    case REG_YMM2:
        return DFT_REG_XMM2;
        break;
    case REG_XMM3:
    case REG_YMM3:
        return DFT_REG_XMM3;
        break;
    case REG_XMM4:
    case REG_YMM4:
        return DFT_REG_XMM4;
        break;
    case REG_XMM5:
    case REG_YMM5:
        return DFT_REG_XMM5;
        break;
    case REG_XMM6:
    case REG_YMM6:
        return DFT_REG_XMM6;
        break;
    case REG_XMM7:
    case REG_YMM7:
        return DFT_REG_XMM7;
        break;
    case REG_XMM8:
    case REG_YMM8:
        return DFT_REG_XMM8;
        break;
    case REG_XMM9:
    case REG_YMM9:
        return DFT_REG_XMM9;
        break;
    case REG_XMM10:
    case REG_YMM10:
        return DFT_REG_XMM10;
        break;
    case REG_XMM11:
    case REG_YMM11:
        return DFT_REG_XMM11;
        break;
    case REG_XMM12:
    case REG_YMM12:
        return DFT_REG_XMM12;
        break;
    case REG_XMM13:
    case REG_YMM13:
        return DFT_REG_XMM13;
        break;
    case REG_XMM14:
    case REG_YMM14:
        return DFT_REG_XMM14;
        break;
    case REG_XMM15:
    case REG_YMM15:
        return DFT_REG_XMM15;
        break;
    case REG_MM0:
    case REG_ST0:
        return DFT_REG_ST0;
        break;
    case REG_MM1:
    case REG_ST1:
        return DFT_REG_ST1;
        break;
    case REG_MM2:
    case REG_ST2:
        return DFT_REG_ST2;
        break;
    case REG_MM3:
    case REG_ST3:
        return DFT_REG_ST3;
        break;
    case REG_MM4:
    case REG_ST4:
        return DFT_REG_ST4;
        break;
    case REG_MM5:
    case REG_ST5:
        return DFT_REG_ST5;
        break;
    case REG_MM6:
    case REG_ST6:
        return DFT_REG_ST6;
        break;
    case REG_MM7:
    case REG_ST7:
        return DFT_REG_ST7;
        break;
    case REG_ZMM0:
    case REG_ZMM1:
    case REG_ZMM2:
    case REG_ZMM3:
    case REG_ZMM4:
    case REG_ZMM5:
    case REG_ZMM6:
    case REG_ZMM7:
        LOGD("found zxmm!\n");
        break;
    default:
        break;
    }
    /* nothing */
    return GRP_NUM;
}

#define CALL(fn) INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_END)

#define R_CALL(fn, reg0)                                                                                               \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32,              \
                   REG_INDX(reg0), IARG_END)

#define M_CALL(is_read, fn)                                                                                            \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID,                           \
                   (is_read) ? IARG_MEMORYREAD_EA : IARG_MEMORYWRITE_EA, IARG_END)
#define M_CALL_W(fn)                                                                                                   \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_MEMORYWRITE_EA,      \
                   IARG_END)
#define M_CALL_R(fn)                                                                                                   \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_MEMORYREAD_EA,       \
                   IARG_END)

#define RR_CALL(fn, reg0, reg1)                                                                                        \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32,              \
                   REG_INDX(reg0), IARG_UINT32, REG_INDX(reg1), IARG_END)

#define RR_CALL_P(fn, reg0, reg1)                                                                                      \
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32,    \
                             REG_INDX(reg0), IARG_UINT32, REG_INDX(reg1), IARG_END)

#define M2R_CALL(fn, dst)                                                                                              \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32,              \
                   REG_INDX(dst), IARG_MEMORYREAD_EA, IARG_END);

#define M2R_CALL_P(fn, dst)                                                                                            \
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32,    \
                             REG_INDX(dst), IARG_MEMORYREAD_EA, IARG_END);

#define R2M_CALL(fn, src)                                                                                              \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_MEMORYWRITE_EA,      \
                   IARG_UINT32, REG_INDX(src), IARG_END);

#define M2M_CALL(fn)                                                                                                   \
    INS_InsertPredicatedCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_MEMORYWRITE_EA,            \
                             IARG_MEMORYREAD_EA, IARG_END);

#define M_CLEAR_N(n)                                                                                                   \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)tagmap_clrn, IARG_FAST_ANALYSIS_CALL, IARG_MEMORYWRITE_EA,             \
                   IARG_UINT32, n, IARG_END);

#define RRR_CALL(fn, reg0, reg1, reg2)                                                                                 \
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)fn, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32,              \
                   REG_INDX(reg0), IARG_UINT32, REG_INDX(reg1), IARG_UINT32, REG_INDX(reg2), IARG_END)

#define HOOK_DECL PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))

namespace {

    inline UINT32 INS_ExplicitOperandCount(INS ins) {
        UINT32 operand_cnt = INS_OperandCount(ins);
        while (operand_cnt > 0 && INS_OperandIsImplicit(ins, operand_cnt - 1))
            --operand_cnt;
        return operand_cnt;
    }

    template <size_t sz>
    inline void maybe_zext(tag_t *dst) {
    }

    template <>
    inline void maybe_zext<4>(tag_t *dst) {
        for (size_t i = 4; i < 8; i++)
            dst[i] = tag_traits<tag_t>::cleared_val;
    }

    template <char code>
    struct Tagset;

    // register
    template <>
    struct Tagset<'r'> {
        using arg_type = uint32_t;
        tag_t *const tags;
        Tagset(THREADID tid, arg_type reg) : tags(RTAG[reg]) {
        }
        tag_t get(int i) const {
            return tags[i];
        }
        void set(int i, tag_t v) {
            tags[i] = v;
        }
        void add(int i, tag_t v) {
            tags[i] = tag_combine(tags[i], v);
        }
        void swap(int i, int j) {
            tags[i] ^= tags[j];
            tags[j] ^= tags[i];
            tags[i] ^= tags[j];
        }
        template <size_t sz>
        void zext() {
            maybe_zext<sz>(tags);
        }

      protected:
        Tagset(tag_t *tags) : tags(tags) {
        }
    };

    // high, 1 byte registers (offset by 1)
    template <>
    struct Tagset<'R'> : public Tagset<'r'> {
        Tagset(THREADID tid, arg_type reg) : Tagset<'r'>(&RTAG[reg][0] + 1) {
        }
    };

    // memory
    template <>
    struct Tagset<'m'> {
        using arg_type = ADDRINT;
        const ADDRINT addr;
        Tagset(THREADID tid, arg_type addr) : addr(addr) {
        }
        tag_t get(int i) const {
            return tagmap_getb(addr + i);
        }
        void set(int i, tag_t v) {
            tagmap_setb(addr + i, v);
        }
        void add(int i, tag_t v) {
            set(i, tag_combine(get(i), v));
        }
        void swap(int i, int j) {
            tag_t tmp = get(i);
            set(i, get(j));
            set(j, tmp);
        }

        template <size_t sz>
        void zext() {
        }
    };

    template <size_t sz>
    struct TagsetCopy : public Tagset<'r'> {
        tag_t tags_copy[sz];

        template <typename TS>
        TagsetCopy(const TS &ts) : Tagset<'r'>(&tags_copy[0]) {
            for (size_t i = 0; i < sz; ++i)
                tags_copy[i] = ts.get(i);
        }
    };

    template <typename T>
    struct instrumentation_base {
        using base_t = instrumentation_base<T>;
        using instrumentation_t = T;

        //// instrumentation - where instructions are parsed and hooks are inserted
        // entry point for instrumentation
        static void ins_op(INS ins) {
            UINT32 operand_cnt = INS_ExplicitOperandCount(ins);

            if (operand_cnt == 1) {
                if (INS_OperandIsImmediate(ins, OP_0))
                    instrumentation_t::ins_unary_imm(ins);
                else
                    instrumentation_t::ins_unary_op(ins);
            } else if (operand_cnt == 2) {
                if (INS_OperandIsImmediate(ins, OP_1))
                    instrumentation_t::ins_binary_imm(ins);
                else
                    instrumentation_t::ins_binary_op(ins);
            } else if (operand_cnt == 3) {
                if (INS_OperandIsImmediate(ins, OP_2))
                    instrumentation_t::ins_ternary_imm(ins);
                else
                    instrumentation_t::ins_ternary_op(ins);
            } else {
                uninstrumented(ins, "operand count");
            }
        }

        static void ins_unary_imm(INS ins) {
        }

        static void ins_unary_op(INS ins) {
            if (INS_OperandIsReg(ins, OP_0)) {
                REG reg_dst = INS_OperandReg(ins, OP_0);
                if (REG_is_gr64(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'r', 8>), reg_dst);
                } else if (REG_is_gr32(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'r', 4>), reg_dst);
                } else if (REG_is_gr16(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'r', 2>), reg_dst);
                } else if (REG_is_xmm(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'r', 16>), reg_dst);
                } else if (REG_is_ymm(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'r', 32>), reg_dst);
                } else if (REG_is_mm(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'r', 8>), reg_dst);
                } else if (REG_is_Lower8(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'r', 1>), reg_dst);
                } else if (REG_is_Upper8(reg_dst)) {
                    R_CALL((instrumentation_t::template unary<'R', 1>), reg_dst);
                } else {
                    uninstrumented(ins, "unary reg type");
                }

                return;
            }

            bool is_read = INS_MemoryOperandIsRead(ins, OP_0);
            switch (INS_OperandWidth(ins, OP_0) / 8) {
            case 1:
                M_CALL(is_read, (instrumentation_t::template unary<'m', 1>));
                break;
            case 2:
                M_CALL(is_read, (instrumentation_t::template unary<'m', 2>));
                break;
            case 4:
                M_CALL(is_read, (instrumentation_t::template unary<'m', 4>));
                break;
            case 8:
                M_CALL(is_read, (instrumentation_t::template unary<'m', 8>));
                break;
            case 16:
                M_CALL(is_read, (instrumentation_t::template unary<'m', 16>));
                break;
            case 32:
                M_CALL(is_read, (instrumentation_t::template unary<'m', 32>));
                break;
            }
        }

        static void ins_binary_imm(INS ins) {
        }

        static void ins_binary_op(INS ins) {
            REG reg0, reg1;
            if (INS_MemoryOperandCount(ins) == 0) {
                reg0 = INS_OperandReg(ins, OP_0);
                reg1 = INS_OperandReg(ins, OP_1);
                if (REG_is_gr64(reg0)) {
                    RR_CALL((instrumentation_t::template binary<'r', 'r', 8>), reg0, reg1);
                } else if (REG_is_gr32(reg0)) {
                    RR_CALL((instrumentation_t::template binary<'r', 'r', 4>), reg0, reg1);
                } else if (REG_is_gr16(reg0)) {
                    RR_CALL((instrumentation_t::template binary<'r', 'r', 2>), reg0, reg1);
                } else if (REG_is_xmm(reg0)) {
                    RR_CALL((instrumentation_t::template binary<'r', 'r', 16>), reg0, reg1);
                } else if (REG_is_ymm(reg0)) {
                    RR_CALL((instrumentation_t::template binary<'r', 'r', 32>), reg0, reg1);
                } else if (REG_is_mm(reg0)) {
                    RR_CALL((instrumentation_t::template binary<'r', 'r', 8>), reg0, reg1);
                } else {
                    if (REG_is_Lower8(reg0) && REG_is_Lower8(reg1)) {
                        RR_CALL((instrumentation_t::template binary<'r', 'r', 1>), reg0, reg1);
                    } else if (REG_is_Upper8(reg0) && REG_is_Upper8(reg1)) {
                        RR_CALL((instrumentation_t::template binary<'R', 'R', 1>), reg0, reg1);
                    } else if (REG_is_Lower8(reg0)) {
                        RR_CALL((instrumentation_t::template binary<'r', 'R', 1>), reg0, reg1);
                    } else {
                        RR_CALL((instrumentation_t::template binary<'R', 'r', 1>), reg0, reg1);
                    }
                }
            } else if (INS_OperandIsMemory(ins, OP_1)) {
                reg0 = INS_OperandReg(ins, OP_0);
                if (REG_is_gr64(reg0)) {
                    M2R_CALL((instrumentation_t::template binary<'r', 'm', 8>), reg0);
                } else if (REG_is_gr32(reg0)) {
                    M2R_CALL((instrumentation_t::template binary<'r', 'm', 4>), reg0);
                } else if (REG_is_gr16(reg0)) {
                    M2R_CALL((instrumentation_t::template binary<'r', 'm', 2>), reg0);
                } else if (REG_is_xmm(reg0)) {
                    M2R_CALL((instrumentation_t::template binary<'r', 'm', 16>), reg0);
                } else if (REG_is_ymm(reg0)) {
                    M2R_CALL((instrumentation_t::template binary<'r', 'm', 32>), reg0);
                } else if (REG_is_mm(reg0)) {
                    M2R_CALL((instrumentation_t::template binary<'r', 'm', 8>), reg0);
                } else if (REG_is_Upper8(reg0)) {
                    M2R_CALL((instrumentation_t::template binary<'R', 'm', 1>), reg0);
                } else {
                    M2R_CALL((instrumentation_t::template binary<'r', 'm', 1>), reg0);
                }
            } else {
                reg1 = INS_OperandReg(ins, OP_1);
                if (REG_is_gr64(reg1)) {
                    R2M_CALL((instrumentation_t::template binary<'m', 'r', 8>), reg1);
                } else if (REG_is_gr32(reg1)) {
                    R2M_CALL((instrumentation_t::template binary<'m', 'r', 4>), reg1);
                } else if (REG_is_gr16(reg1)) {
                    R2M_CALL((instrumentation_t::template binary<'m', 'r', 2>), reg1);
                } else if (REG_is_xmm(reg1)) {
                    R2M_CALL((instrumentation_t::template binary<'m', 'r', 16>), reg1);
                } else if (REG_is_ymm(reg1)) {
                    R2M_CALL((instrumentation_t::template binary<'m', 'r', 32>), reg1);
                } else if (REG_is_mm(reg1)) {
                    R2M_CALL((instrumentation_t::template binary<'m', 'r', 8>), reg1);
                } else if (REG_is_Upper8(reg1)) {
                    R2M_CALL((instrumentation_t::template binary<'m', 'R', 1>), reg1);
                } else {
                    R2M_CALL((instrumentation_t::template binary<'m', 'r', 1>), reg1);
                }
            }
        }

        static void ins_ternary_imm(INS ins) {
        }

        static void ins_ternary_op(INS ins) {
            if (INS_OperandIsReg(ins, OP_0)) {
                REG reg0 = INS_OperandReg(ins, OP_0);
                if (INS_OperandIsReg(ins, OP_1)) {
                    REG reg1 = INS_OperandReg(ins, OP_1);
                    if (INS_OperandIsReg(ins, OP_2)) {
                        REG reg2 = INS_OperandReg(ins, OP_2);
                        switch (REG_Size(reg0)) {
                        case 1:
                            RRR_CALL((instrumentation_t::template ternary<'r', 'r', 'r', 1>), reg0, reg1, reg2);
                            break;
                        case 2:
                            RRR_CALL((instrumentation_t::template ternary<'r', 'r', 'r', 2>), reg0, reg1, reg2);
                            break;
                        case 4:
                            RRR_CALL((instrumentation_t::template ternary<'r', 'r', 'r', 4>), reg0, reg1, reg2);
                            break;
                        case 8:
                            RRR_CALL((instrumentation_t::template ternary<'r', 'r', 'r', 8>), reg0, reg1, reg2);
                            break;
                        case 16:
                            RRR_CALL((instrumentation_t::template ternary<'r', 'r', 'r', 16>), reg0, reg1, reg2);
                            break;
                        case 32:
                            RRR_CALL((instrumentation_t::template ternary<'r', 'r', 'r', 32>), reg0, reg1, reg2);
                            break;
                        default:
                            uninstrumented(ins, "ternary rrr");
                        }
                        return;
                    }
                }
            }
            uninstrumented(ins, "ternary");
        }

        //// hook functions
        template <char code0, size_t sz>
        static void HOOK_DECL unary(THREADID tid, typename Tagset<code0>::arg_type op0);

        template <char code0, char code1, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<code0>::arg_type op0,
                                     typename Tagset<code1>::arg_type op1);

        template <char code0, char code1, char code2, size_t sz>
        static void HOOK_DECL ternary(THREADID tid, typename Tagset<code0>::arg_type op0,
                                      typename Tagset<code1>::arg_type op1, typename Tagset<code2>::arg_type op2);
    };

    template <bool b, typename T = void>
    struct enable_if;

    template <typename T>
    struct enable_if<true, T> {
        using type = T;
    };

} // namespace

#endif
