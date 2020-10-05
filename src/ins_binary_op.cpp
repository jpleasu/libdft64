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

    // mix all input bytes int every output byte
    template <char scode, char dcode, size_t sz>
    void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
    binary_op(THREADID tid, typename Tagset<dcode>::arg_type dst, typename Tagset<scode>::arg_type src) {
        Tagset<scode> src_tags(tid, src);
        Tagset<dcode> dst_tags(tid, dst);

        tag_t t = tag_combine(dst_tags.get(0), src_tags.get(0));
        for (size_t i = 1; i < sz; i++)
            t = tag_combine(t, dst_tags.get(i), src_tags.get(i));
        for (size_t i = 0; i < sz; i++)
            dst_tags.set(i, t);

        dst_tags.template zext<sz>();
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
            R2R_CALL((binary_op<'r', 'r', 8>), reg_dst, reg_src);
        } else if (REG_is_gr32(reg_dst)) {
            R2R_CALL((binary_op<'r', 'r', 4>), reg_dst, reg_src);
        } else if (REG_is_gr16(reg_dst)) {
            R2R_CALL((binary_op<'r', 'r', 2>), reg_dst, reg_src);
        } else if (REG_is_xmm(reg_dst)) {
            R2R_CALL((binary_op<'r', 'r', 16>), reg_dst, reg_src);
        } else if (REG_is_ymm(reg_dst)) {
            R2R_CALL((binary_op<'r', 'r', 32>), reg_dst, reg_src);
        } else if (REG_is_mm(reg_dst)) {
            R2R_CALL((binary_op<'r', 'r', 8>), reg_dst, reg_src);
        } else {
            if (REG_is_Lower8(reg_dst) && REG_is_Lower8(reg_src)) {
                R2R_CALL((binary_op<'r', 'r', 1>), reg_dst, reg_src);
            } else if (REG_is_Upper8(reg_dst) && REG_is_Upper8(reg_src)) {
                R2R_CALL((binary_op<'R', 'R', 1>), reg_dst, reg_src);
            } else if (REG_is_Lower8(reg_dst)) {
                R2R_CALL((binary_op<'R', 'r', 1>), reg_dst, reg_src);
            } else {
                R2R_CALL((binary_op<'r', 'R', 1>), reg_dst, reg_src);
            }
        }
    } else if (INS_OperandIsMemory(ins, OP_1)) {
        reg_dst = INS_OperandReg(ins, OP_0);
        if (REG_is_gr64(reg_dst)) {
            M2R_CALL((binary_op<'m', 'r', 8>), reg_dst);
        } else if (REG_is_gr32(reg_dst)) {
            M2R_CALL((binary_op<'m', 'r', 4>), reg_dst);
        } else if (REG_is_gr16(reg_dst)) {
            M2R_CALL((binary_op<'m', 'r', 2>), reg_dst);
        } else if (REG_is_xmm(reg_dst)) {
            M2R_CALL((binary_op<'m', 'r', 16>), reg_dst);
        } else if (REG_is_ymm(reg_dst)) {
            M2R_CALL((binary_op<'m', 'r', 32>), reg_dst);
        } else if (REG_is_mm(reg_dst)) {
            M2R_CALL((binary_op<'m', 'r', 8>), reg_dst);
        } else if (REG_is_Upper8(reg_dst)) {
            M2R_CALL((binary_op<'m', 'R', 1>), reg_dst);
        } else {
            M2R_CALL((binary_op<'m', 'r', 1>), reg_dst);
        }
    } else {
        reg_src = INS_OperandReg(ins, OP_1);
        if (REG_is_gr64(reg_src)) {
            R2M_CALL((binary_op<'r', 'm', 8>), reg_src);
        } else if (REG_is_gr32(reg_src)) {
            R2M_CALL((binary_op<'r', 'm', 4>), reg_src);
        } else if (REG_is_gr16(reg_src)) {
            R2M_CALL((binary_op<'r', 'm', 2>), reg_src);
        } else if (REG_is_xmm(reg_src)) {
            R2M_CALL((binary_op<'r', 'm', 16>), reg_src);
        } else if (REG_is_ymm(reg_src)) {
            R2M_CALL((binary_op<'r', 'm', 32>), reg_src);
        } else if (REG_is_mm(reg_src)) {
            R2M_CALL((binary_op<'r', 'm', 8>), reg_src);
        } else if (REG_is_Upper8(reg_src)) {
            R2M_CALL((binary_op<'R', 'm', 1>), reg_src);
        } else {
            R2M_CALL((binary_op<'r', 'm', 1>), reg_src);
        }
    }
}
