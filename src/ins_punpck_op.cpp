#include "ins_punpck_op.h"
#include "ins_helper.h"

extern thread_ctx_t *threads_ctx;

namespace {
    template <int blocksize, size_t sz>
    void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
    r2r_punpckl_op(THREADID tid, uint32_t dst, uint32_t src) {
        tag_t *src_tags = RTAG[src];
        tag_t *dst_tags = RTAG[dst];
        const long nblocks = sz / (2 * blocksize);
        for (long b = nblocks - 1; b >= 0; --b) {
            for (int i = blocksize - 1; i >= 0; --i) {
                dst_tags[2 * b * blocksize + i] = dst_tags[b * blocksize + i];
                dst_tags[(2 * b + 1) * blocksize + i] = src_tags[b * blocksize + i];
            }
        }
    }

    // impossible
    template <>
    void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
    r2r_punpckl_op<8, 8>(THREADID tid, uint32_t dst, uint32_t src) {
        fprintf(stderr, "unexpected instruction! punpackl 8 8\n");
    }
} // namespace

template <int blocksize>
void ins_punpckl_op(INS ins) {
    REG reg_dst, reg_src;
    if (INS_MemoryOperandCount(ins) == 0 || INS_OperandCount(ins) == 2) {
        reg_dst = INS_OperandReg(ins, OP_0);
        reg_src = INS_OperandReg(ins, OP_1);
        switch (REG_Size(reg_dst)) {
        case 8:
            RR_CALL((r2r_punpckl_op<blocksize, 8>), reg_dst, reg_src);
            break;
        case 16:
            RR_CALL((r2r_punpckl_op<blocksize, 16>), reg_dst, reg_src);
            break;
        case 32:
            RR_CALL((r2r_punpckl_op<blocksize, 32>), reg_dst, reg_src);
            break;
        default:
            uninstrumented(ins, "punpckl regsize");
            break;
        }
    } else {
        uninstrumented(ins, "punpckl operand types");
    }
}

// instantiate what will be used.
template void ins_punpckl_op<1>(INS);
template void ins_punpckl_op<2>(INS);
template void ins_punpckl_op<4>(INS);
template void ins_punpckl_op<8>(INS);
