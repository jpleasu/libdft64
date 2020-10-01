#include "ins_binary_op.h"
#include "ins_helper.h"

/* threads context */
extern thread_ctx_t *threads_ctx;

namespace {

    void PIN_FAST_ANALYSIS_CALL r_clrq_zext(THREADID tid, uint32_t reg) {
        maybe_zext<4>(RTAG[reg]);
    }

    template <int ind>
    void PIN_FAST_ANALYSIS_CALL r_clrb(THREADID tid, uint32_t reg) {
        RTAG[reg][ind] = tag_traits<tag_t>::cleared_val;
    }

    template <int dst_ind, int src_ind>
    void PIN_FAST_ANALYSIS_CALL r2r_binary_opb(THREADID tid, uint32_t dst, uint32_t src) {
        tag_t dst_tag = RTAG[dst][dst_ind];
        tag_t src_tag = RTAG[src][src_ind];

        RTAG[dst][dst_ind] = tag_combine(dst_tag, src_tag);
    }

    template <int dst_ind>
    void PIN_FAST_ANALYSIS_CALL m2r_binary_opb(THREADID tid, uint32_t dst, ADDRINT src) {
        tag_t src_tag = MTAG(src);
        tag_t dst_tag = RTAG[dst][dst_ind];

        RTAG[dst][dst_ind] = tag_combine(src_tag, dst_tag);
    }
    template <int src_ind>
    void PIN_FAST_ANALYSIS_CALL r2m_binary_opb(THREADID tid, ADDRINT dst, uint32_t src) {
        tag_t src_tag = RTAG[src][src_ind];
        tag_t dst_tag = MTAG(dst);

        tag_t res_tag = tag_combine(dst_tag, src_tag);
        tagmap_setb(dst, res_tag);
    }

    template <size_t sz>
    void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
    r2r_binary_op(THREADID tid, uint32_t dst, uint32_t src) {
        tag_t *src_tags = RTAG[src];
        tag_t *dst_tags = RTAG[dst];
        for (size_t i = 0; i < sz; i++)
            dst_tags[i] = tag_combine(dst_tags[i], src_tags[i]);
        maybe_zext<sz>(dst_tags);
    }

    template <size_t sz>
    void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
    m2r_binary_op(THREADID tid, uint32_t dst, ADDRINT src) {
        tag_t *dst_tags = RTAG[dst];
        for (size_t i = 0; i < sz; i++)
            dst_tags[i] = tag_combine(dst_tags[i], MTAG(src + i));
        maybe_zext<sz>(dst_tags);
    }

    template <size_t sz>
    void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
    r2m_binary_op(THREADID tid, ADDRINT dst, uint32_t src) {
        tag_t *src_tags = RTAG[src];
        for (size_t i = 0; i < sz; i++)
            tagmap_setb(dst + i, tag_combine(MTAG(dst + i), src_tags[i]));
    }

} // namespace

void ins_binary_bytemask_op(INS ins, uint8_t maskval) {
    REG reg_dst;
    if (INS_OperandIsImmediate(ins, OP_1)) {
        reg_dst = INS_OperandReg(ins, OP_0);

        if (!(REG_valid(reg_dst)))
            return;

        if (REG_is_gr32(reg_dst))
            R_CALL(r_clrq_zext, reg_dst);

        UINT64 val = INS_OperandImmediate(ins, OP_1);
        UINT32 sz = REG_Size(reg_dst);

        if ((val & 0xff) == maskval)
            R_CALL((r_clrb<0>), reg_dst);
        if (sz <= 1)
            return;
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<1>), reg_dst);
        if (sz <= 2)
            return;
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<2>), reg_dst);
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<3>), reg_dst);
        if (sz <= 4)
            return;
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<4>), reg_dst);
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<5>), reg_dst);
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<6>), reg_dst);
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<7>), reg_dst);

        return;
    }
    ins_binary_op(ins);
}

void ins_binary_op(INS ins) {
    REG reg_dst, reg_src;
    if (INS_OperandIsImmediate(ins, OP_1)) {
        reg_dst = INS_OperandReg(ins, OP_0);
        if (REG_is_gr32(reg_dst)) {
            R_CALL(r_clrq_zext, reg_dst);
        }
        return;
    }
    if (INS_MemoryOperandCount(ins) == 0) {
        reg_dst = INS_OperandReg(ins, OP_0);
        reg_src = INS_OperandReg(ins, OP_1);
        if (REG_is_gr64(reg_dst)) {
            R2R_CALL(r2r_binary_op<8>, reg_dst, reg_src);
        } else if (REG_is_gr32(reg_dst)) {
            R2R_CALL(r2r_binary_op<4>, reg_dst, reg_src);
        } else if (REG_is_gr16(reg_dst)) {
            R2R_CALL(r2r_binary_op<2>, reg_dst, reg_src);
        } else if (REG_is_xmm(reg_dst)) {
            R2R_CALL(r2r_binary_op<16>, reg_dst, reg_src);
        } else if (REG_is_ymm(reg_dst)) {
            R2R_CALL(r2r_binary_op<32>, reg_dst, reg_src);
        } else if (REG_is_mm(reg_dst)) {
            R2R_CALL(r2r_binary_op<8>, reg_dst, reg_src);
        } else {
            if (REG_is_Lower8(reg_dst) && REG_is_Lower8(reg_src))
                R2R_CALL((r2r_binary_opb<0, 0>), reg_dst, reg_src);
            else if (REG_is_Upper8(reg_dst) && REG_is_Upper8(reg_src))
                R2R_CALL((r2r_binary_opb<1, 1>), reg_dst, reg_src);
            else if (REG_is_Lower8(reg_dst))
                R2R_CALL((r2r_binary_opb<0, 1>), reg_dst, reg_src);
            else
                R2R_CALL((r2r_binary_opb<1, 0>), reg_dst, reg_src);
        }
    } else if (INS_OperandIsMemory(ins, OP_1)) {
        reg_dst = INS_OperandReg(ins, OP_0);
        if (REG_is_gr64(reg_dst)) {
            M2R_CALL((m2r_binary_op<8>), reg_dst);
        } else if (REG_is_gr32(reg_dst)) {
            M2R_CALL((m2r_binary_op<4>), reg_dst);
        } else if (REG_is_gr16(reg_dst)) {
            M2R_CALL((m2r_binary_op<2>), reg_dst);
        } else if (REG_is_xmm(reg_dst)) {
            M2R_CALL((m2r_binary_op<16>), reg_dst);
        } else if (REG_is_ymm(reg_dst)) {
            M2R_CALL((m2r_binary_op<32>), reg_dst);
        } else if (REG_is_mm(reg_dst)) {
            M2R_CALL((m2r_binary_op<8>), reg_dst);
        } else if (REG_is_Upper8(reg_dst)) {
            M2R_CALL((m2r_binary_opb<1>), reg_dst);
        } else {
            M2R_CALL((m2r_binary_opb<0>), reg_dst);
        }
    } else {
        reg_src = INS_OperandReg(ins, OP_1);
        if (REG_is_gr64(reg_src)) {
            R2M_CALL((r2m_binary_op<8>), reg_src);
        } else if (REG_is_gr32(reg_src)) {
            R2M_CALL((r2m_binary_op<4>), reg_src);
        } else if (REG_is_gr16(reg_src)) {
            R2M_CALL((r2m_binary_op<2>), reg_src);
        } else if (REG_is_xmm(reg_src)) {
            R2M_CALL((r2m_binary_op<16>), reg_src);
        } else if (REG_is_ymm(reg_src)) {
            R2M_CALL((r2m_binary_op<32>), reg_src);
        } else if (REG_is_mm(reg_src)) {
            R2M_CALL((r2m_binary_op<8>), reg_src);
        } else if (REG_is_Upper8(reg_src)) {
            R2M_CALL((r2m_binary_opb<1>), reg_src);
        } else {
            R2M_CALL((r2m_binary_opb<0>), reg_src);
        }
    }
}
