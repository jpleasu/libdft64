#include "ins_generic_op.h"

#include "ins_helper.h"

/* threads context */
extern thread_ctx_t *threads_ctx;

namespace {
    void HOOK_DECL r_zextq(THREADID tid, uint32_t reg) {
        maybe_zext<4>(RTAG[reg]);
    }

    template <int ind>
    void HOOK_DECL r_clrb(THREADID tid, uint32_t reg) {
        RTAG[reg][ind] = tag_traits<tag_t>::cleared_val;
    }

    // mix all input bytes int every output byte
    struct blender_instrumentation : public instrumentation_base<blender_instrumentation> {
        // ignore the constants
        static void ins_binary_imm(INS ins) {
            instrumentation_t::ins_unary_op(ins);
        }
        static void ins_ternary_imm(INS ins) {
            instrumentation_t::ins_binary_op(ins);
        }
        static void ins_ternary_op(INS ins) {
            uninstrumented(ins, "generic ternary");
        }

        template <char dcode, size_t sz>
        static void HOOK_DECL unary(THREADID tid, typename Tagset<dcode>::arg_type dst) {
            Tagset<dcode> dst_tags(tid, dst);
            tag_t t = dst_tags.get(0);
            for (size_t i = 1; i < sz; i++)
                t = tag_combine(t, dst_tags.get(i));
            for (size_t i = 0; i < sz; i++)
                dst_tags.set(i, t);
            dst_tags.template zext<sz>();
        }
        template <char scode, char dcode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<scode>::arg_type src) {
            Tagset<scode> src_tags(tid, src);
            Tagset<dcode> dst_tags(tid, dst);

            tag_t t = tag_combine(dst_tags.get(0), src_tags.get(0));
            for (size_t i = 1; i < sz; i++)
                t = tag_combine(t, dst_tags.get(i), src_tags.get(i));
            for (size_t i = 0; i < sz; i++)
                dst_tags.set(i, t);

            dst_tags.template zext<sz>();
        }
    };

    // byte levels correspond
    struct bytevec_instrumentation : public instrumentation_base<bytevec_instrumentation> {

        static void ins_unary_op(INS ins) {
            uninstrumented(ins, "bytevec unary");
        }

        static void ins_ternary_imm(INS ins) {
            instrumentation_t::ins_binary_op(ins);
        }

        template <char scode, char dcode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<scode>::arg_type src) {
            Tagset<scode> src_tags(tid, src);
            Tagset<dcode> dst_tags(tid, dst);

            for (size_t i = 0; i < sz; i++)
                dst_tags.set(i, tag_combine(dst_tags.get(i), src_tags.get(i)));

            dst_tags.template zext<sz>();
        }
        template <char scode1, char scode2, char dcode, size_t sz>
        static void HOOK_DECL ternary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                      typename Tagset<scode1>::arg_type src1, typename Tagset<scode2>::arg_type src2) {
            Tagset<scode1> src1_tags(tid, src1);
            Tagset<scode2> src2_tags(tid, src2);
            Tagset<dcode> dst_tags(tid, dst);

            for (size_t i = 0; i < sz; i++)
                dst_tags.set(i, tag_combine(src1_tags.get(i), src2_tags.get(i)));

            dst_tags.template zext<sz>();
        }
    };

    struct bytecasc_instrumentation : public instrumentation_base<bytecasc_instrumentation> {
        static void ins_binary_imm(INS ins) {
            instrumentation_t::ins_unary_op(ins);
        }
        static void ins_ternary_imm(INS ins) {
            instrumentation_t::ins_binary_op(ins);
        }
        static void ins_ternary_op(INS ins) {
            uninstrumented(ins, "bytecasc ternary");
        }

        template <char dcode, size_t sz>
        static void HOOK_DECL unary(THREADID tid, typename Tagset<dcode>::arg_type dst) {
            Tagset<dcode> dst_tags(tid, dst);
            tag_t t = dst_tags.get(0);
            for (size_t i = 1; i < sz; i++) {
                t = tag_combine(t, dst_tags.get(i));
                dst_tags.set(i, t);
            }
            dst_tags.template zext<sz>();
        }
        template <char scode, char dcode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<scode>::arg_type src) {
            Tagset<scode> src_tags(tid, src);
            Tagset<dcode> dst_tags(tid, dst);

            tag_t t = tag_combine(dst_tags.get(0), src_tags.get(0));
            dst_tags.set(0, t);
            for (size_t i = 1; i < sz; i++) {
                t = tag_combine(t, dst_tags.get(i), src_tags.get(i));
                dst_tags.set(i, t);
            }

            dst_tags.template zext<sz>();
        }
    };

} // namespace

void ins_bytecasc_op(INS ins) {
    bytecasc_instrumentation::ins_op(ins);
}

void ins_bytecasc_op(INS ins, UINT64 nopval) {
    if (INS_ExplicitOperandCount(ins) == 2 && INS_OperandIsImmediate(ins, OP_1)) {
        if (INS_OperandImmediate(ins, OP_1) == nopval)
            return;
    }
    bytecasc_instrumentation::ins_op(ins);
}

void ins_bytevec_op(INS ins) {
    bytevec_instrumentation::ins_op(ins);
}

void ins_bytevec_op(INS ins, uint8_t maskval) {
    REG reg_dst;
    if (INS_OperandIsImmediate(ins, OP_1)) {
        reg_dst = INS_OperandReg(ins, OP_0);

        if (!(REG_valid(reg_dst)))
            return;

        UINT64 val = INS_OperandImmediate(ins, OP_1);
        UINT32 sz = REG_Size(reg_dst);

        if ((val & 0xff) == maskval) {
            if (REG_is_Upper8(reg_dst))
                R_CALL((r_clrb<1>), reg_dst);
            else
                R_CALL((r_clrb<0>), reg_dst);
        }
        if (sz == 1)
            return;
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<1>), reg_dst);
        if (sz == 2)
            return;
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<2>), reg_dst);
        if (((val >>= 8) & 0xff) == maskval)
            R_CALL((r_clrb<3>), reg_dst);
        if (sz == 4) {
            R_CALL((r_zextq), reg_dst);
            return;
        }
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
    ins_bytevec_op(ins);
}

void ins_blender_op(INS ins) {
    blender_instrumentation::ins_op(ins);
}
