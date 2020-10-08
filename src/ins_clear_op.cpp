#include "ins_clear_op.h"
#include "ins_helper.h"

namespace {
    struct clear_instrumentation : public instrumentation_base<clear_instrumentation> {
        template <char code0, size_t sz>
        static void HOOK_DECL unary(THREADID tid, typename Tagset<code0>::arg_type op0) {
            Tagset<code0> tags0(tid, op0);
            for (size_t i = 0; i < sz; ++i)
                tags0.set(i, tag_traits<tag_t>::cleared_val);
            tags0.template zext<sz>();
        }
    };
} // namespace

static void PIN_FAST_ANALYSIS_CALL r_clrl4(THREADID tid) {
    for (size_t i = 0; i < 8; i++) {
        RTAG[DFT_REG_RDX][i] = tag_traits<tag_t>::cleared_val;
        RTAG[DFT_REG_RCX][i] = tag_traits<tag_t>::cleared_val;
        RTAG[DFT_REG_RBX][i] = tag_traits<tag_t>::cleared_val;
        RTAG[DFT_REG_RAX][i] = tag_traits<tag_t>::cleared_val;
    }
}

static void PIN_FAST_ANALYSIS_CALL r_clrl2(THREADID tid) {
    for (size_t i = 0; i < 8; i++) {
        RTAG[DFT_REG_RDX][i] = tag_traits<tag_t>::cleared_val;
        RTAG[DFT_REG_RAX][i] = tag_traits<tag_t>::cleared_val;
    }
}

void ins_clear_op(INS ins) {
    clear_instrumentation::ins_unary_op(ins);
}

void ins_clear_op_predicated(INS ins) {
    // one byte
    if (INS_MemoryOperandCount(ins) == 0) {
        REG reg_dst = INS_OperandReg(ins, OP_0);

        if (REG_is_Upper8(reg_dst))
            INS_InsertPredicatedCall(ins, IPOINT_BEFORE, (AFUNPTR)clear_instrumentation::unary<'R', 1>,
                                     IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32, REG_INDX(reg_dst), IARG_END);
        else
            INS_InsertPredicatedCall(ins, IPOINT_BEFORE, (AFUNPTR)clear_instrumentation::unary<'r', 1>,
                                     IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_UINT32, REG_INDX(reg_dst), IARG_END);
    } else
        INS_InsertPredicatedCall(ins, IPOINT_BEFORE, (AFUNPTR)clear_instrumentation::unary<'m', 1>,
                                 IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_MEMORYWRITE_EA, IARG_END);
}

void ins_clear_op_l2(INS ins) {
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)r_clrl2, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_END);
}

void ins_clear_op_l4(INS ins) {
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)r_clrl4, IARG_FAST_ANALYSIS_CALL, IARG_THREAD_ID, IARG_END);
}
