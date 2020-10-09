#include "ins_shift_op.h"
#include "ins_helper.h"

#define CASE(type, slop, SHIFT)                                                                                        \
    case (SHIFT):                                                                                                      \
        if (slop)                                                                                                      \
            lshift_const<SHIFT, true>::ins_##type##_op(ins);                                                           \
        else                                                                                                           \
            lshift_const<SHIFT, false>::ins_##type##_op(ins);                                                          \
        break;

#define SWITCH(type, val, slop)                                                                                        \
    switch ((val / 8) & 0x1f) {                                                                                        \
        CASE(type, slop, 0);                                                                                           \
        CASE(type, slop, 1);                                                                                           \
        CASE(type, slop, 2);                                                                                           \
        CASE(type, slop, 3);                                                                                           \
        CASE(type, slop, 4);                                                                                           \
        CASE(type, slop, 5);                                                                                           \
        CASE(type, slop, 6);                                                                                           \
        CASE(type, slop, 7);                                                                                           \
    }

namespace {
    template <int byte_shift, bool slop>
    struct lshift_const : public instrumentation_base<lshift_const<byte_shift, slop>> {
        template <char dcode, size_t sz>
        static void HOOK_DECL unary(THREADID tid, typename Tagset<dcode>::arg_type dst) {
            Tagset<dcode> dst_tags(tid, dst);
            for (int i = sz - 1; i - byte_shift >= 0; --i)
                dst_tags.set(i, dst_tags.get(i - byte_shift));
            for (int i = 0; i < byte_shift; ++i)
                dst_tags.set(i, tag_traits<tag_t>::cleared_val);
            if (slop) {
                for (int i = sz - 1; i - byte_shift - 1 >= 0; --i)
                    dst_tags.add(i, dst_tags.get(i - 1));
            }
        }

        template <char dcode, char scode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<scode>::arg_type src) {
            Tagset<dcode> dst_tags(tid, dst);
            TagsetCopy<sz> src_tags(Tagset<scode>(tid, src));

            for (int i = sz - 1; i - byte_shift >= 0; --i)
                dst_tags.set(i, dst_tags.get(i - byte_shift));
            for (int i = byte_shift - 1; i >= 0; --i)
                dst_tags.set(i, src_tags.get(sz - byte_shift + i));

            if (slop) {
                for (int i = sz - 1; i > 0; --i)
                    dst_tags.add(i, dst_tags.get(i - 1));
                dst_tags.add(0, src_tags.get(static_cast<int>(sz) - byte_shift - 1));
            }
        }
    };

    struct lshift_instrumentation : public instrumentation_base<lshift_instrumentation> {
        static void ins_unary_imm(INS ins) {
            uninstrumented(ins, "shift unary imm");
        }
        static void ins_unary_op(INS ins) {
            // shl op1 is implicit
            if (INS_OperandIsImmediate(ins, OP_1))
                instrumentation_t::ins_binary_imm(ins);
            else if (INS_OperandIsReg(ins, OP_1))
                instrumentation_t::ins_binary_op(ins);
            else {
                uninstrumented(ins, "shift unary");
                dump_instruction(ins);
            }
        }

        static void ins_binary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_1);
            bool slop = val % 8 != 0;
            SWITCH(unary, val, slop);
        }

        // shl
        template <char dcode, char shftcode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<shftcode>::arg_type shft) {
            Tagset<dcode> dst_tags(tid, dst);
            Tagset<shftcode> shft_tags(tid, shft);
            tag_t t = tag_combine(dst_tags.get(0), shft_tags.get(0));
            dst_tags.set(0, t);
            for (size_t i = 0; i < sz; ++i) {
                t = tag_combine(t, dst_tags.get(i));
                dst_tags.set(i, t);
            }
            dst_tags.template zext<sz>();
        }

        // shld
        static void ins_ternary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_2);
            bool slop = val % 8 != 0;
            SWITCH(binary, val, slop);
        }

        // shlx
        template <char dcode, char scode, char shftcode, size_t sz>
        static void HOOK_DECL ternary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                      typename Tagset<scode>::arg_type src, typename Tagset<shftcode>::arg_type shft) {
            Tagset<dcode> dst_tags(tid, dst);
            Tagset<scode> src_tags(tid, src);
            Tagset<shftcode> shft_tags(tid, shft);

            tag_t t = tag_combine(src_tags.get(0), shft_tags.get(0));
            dst_tags.set(0, t);
            for (size_t i = 0; i < sz; ++i) {
                t = tag_combine(t, src_tags.get(i));
                dst_tags.set(i, t);
            }
            dst_tags.template zext<sz>();
        }
    };
} // namespace

#undef CASE
#undef SWITCH

void ins_lshift_op(INS ins) {
    lshift_instrumentation::ins_op(ins);
}
