#include "ins_shift_op.h"
#include "ins_clear_op.h"
#include "ins_helper.h"

#define CASE(N)
#define SWITCH8(x)                                                                                                     \
    switch (x) {                                                                                                       \
        CASE(0);                                                                                                       \
        CASE(1);                                                                                                       \
        CASE(2);                                                                                                       \
        CASE(3);                                                                                                       \
        CASE(4);                                                                                                       \
        CASE(5);                                                                                                       \
        CASE(6);                                                                                                       \
        CASE(7);                                                                                                       \
        CASE(8);                                                                                                       \
    }

namespace {

    template <int byte_shift, bool slop>
    struct lshift_const : public instrumentation_base<lshift_const<byte_shift, slop>> {
        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift < sz)>::type HOOK_DECL unary(THREADID tid,
                                                                           typename Tagset<dcode>::arg_type dst) {
            Tagset<dcode> dst_tags(tid, dst);
            for (int i = sz - 1; i - byte_shift >= 0; --i)
                dst_tags.set(i, dst_tags.get(i - byte_shift));
            for (int i = 0; i < byte_shift; ++i)
                dst_tags.set(i, tag_traits<tag_t>::cleared_val);
            if (slop) {
                for (int i = sz - 1; i - byte_shift - 1 >= 0; --i)
                    dst_tags.add(i, dst_tags.get(i - 1));
            }
            dst_tags.template zext<sz>();
        }
        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift >= sz)>::type HOOK_DECL unary(THREADID tid,
                                                                            typename Tagset<dcode>::arg_type dst) {
            // placeholder for switch
        }

        template <char dcode, char scode, size_t sz>
        static typename enable_if<(byte_shift < sz)>::type HOOK_DECL binary(THREADID tid,
                                                                            typename Tagset<dcode>::arg_type dst,
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

        template <char dcode, char scode, size_t sz>
        static typename enable_if<(byte_shift >= sz)>::type HOOK_DECL binary(THREADID tid,
                                                                             typename Tagset<dcode>::arg_type dst,
                                                                             typename Tagset<scode>::arg_type src) {
            // placeholder
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
            UINT32 w = INS_OperandWidth(ins, OP_0);
            if (val >= w) {
                ins_clear_op(ins);
                return;
            }
            int shft = val % w;
            bool slop = shft % 8 != 0;
#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case (SHIFT):                                                                                                      \
        if (slop)                                                                                                      \
            lshift_const<SHIFT, true>::ins_unary_op(ins);                                                              \
        else                                                                                                           \
            lshift_const<SHIFT, false>::ins_unary_op(ins);                                                             \
        break;

            SWITCH8(shft / 8);
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
            UINT32 w = INS_OperandWidth(ins, OP_0);
            if (val >= w) {
                ins_clear_op(ins);
                return;
            }
            int shft = val % w;
            bool slop = shft % 8 != 0;

#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case (SHIFT):                                                                                                      \
        if (slop)                                                                                                      \
            lshift_const<SHIFT, true>::ins_binary_op(ins);                                                             \
        else                                                                                                           \
            lshift_const<SHIFT, false>::ins_binary_op(ins);                                                            \
        break;

            SWITCH8(shft / 8);
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

    // right rotation in byte_shift bytes,
    template <int byte_shift, bool lslop, bool rslop>
    struct rotate_const : public instrumentation_base<rotate_const<byte_shift, lslop, rslop>> {
        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift <= sz)>::type HOOK_DECL unary(THREADID tid,
                                                                            typename Tagset<dcode>::arg_type dst) {
            Tagset<dcode> dst_tags(tid, dst);
            TagsetCopy<sz> src_tags(dst_tags);

            size_t h = sz - byte_shift;
            for (size_t i = 0; i < sz; ++i)
                dst_tags.set(i, src_tags.get((i + byte_shift) % sz));

            if (rslop) {
                for (size_t i = 0; i < h - 1; ++i)
                    dst_tags.add(i, src_tags.get((i + byte_shift + 1) % sz));
                if (lslop)
                    for (size_t i = h - 1; i < sz; ++i)
                        dst_tags.add(i, src_tags.get((i + byte_shift + 1) % sz));
            } else if (lslop) {
                for (size_t i = h + 1; i < sz; ++i) {
                    dst_tags.add(i, src_tags.get((i + byte_shift + sz - 1) % sz));
                }
            }

            dst_tags.template zext<sz>();
        }

        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift > sz)>::type HOOK_DECL unary(THREADID tid,
                                                                           typename Tagset<dcode>::arg_type dst) {
            // placeholder
        }
    };

    template <bool left, bool carry>
    struct rotate_instrumentation : public instrumentation_base<rotate_instrumentation<left, carry>> {
        using typename instrumentation_base<rotate_instrumentation<left, carry>>::instrumentation_t;

        static void ins_unary_imm(INS ins) {
            uninstrumented(ins, "rotate unary imm");
        }
        static void ins_unary_op(INS ins) {
            if (INS_OperandIsImmediate(ins, OP_1))
                instrumentation_t::ins_binary_imm(ins);
            else if (INS_OperandIsReg(ins, OP_1))
                instrumentation_t::ins_binary_op(ins);
            else {
                uninstrumented(ins, "rotate unary");
                dump_instruction(ins);
            }
        }

        static void ins_binary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_1);
            UINT32 w = INS_OperandWidth(ins, OP_0);
            if (w >= 32) {
                val %= w;
            }
            int m = w + carry;
            int rshft = left ? (m - 1 - (val + m - 1) % m) : val % m;

            bool rslop = (rshft % 8) != 0;
            bool lslop = ((rshft + 8 - carry) % 8) != 0;
#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case (SHIFT):                                                                                                      \
        if (lslop) {                                                                                                   \
            if (rslop)                                                                                                 \
                rotate_const<SHIFT, true, true>::ins_unary_op(ins);                                                    \
            else                                                                                                       \
                rotate_const<SHIFT, true, false>::ins_unary_op(ins);                                                   \
        } else {                                                                                                       \
            if (rslop)                                                                                                 \
                rotate_const<SHIFT, false, true>::ins_unary_op(ins);                                                   \
            else                                                                                                       \
                rotate_const<SHIFT, false, false>::ins_unary_op(ins);                                                  \
        }                                                                                                              \
        break;

            SWITCH8(rshft / 8);
        }

        template <char dcode, char scode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<scode>::arg_type shft) {
            Tagset<dcode> dst_tags(tid, dst);
            Tagset<scode> shft_tags(tid, shft);

            // blender + the rotate op
            tag_t t = tag_combine(shft_tags.get(0), dst_tags.get(0));
            for (size_t i = 1; i < sz; ++i)
                t = tag_combine(t, dst_tags.get(i));
            for (size_t i = 0; i < sz; ++i)
                dst_tags.set(i, t);

            dst_tags.template zext<sz>();
        }

        // rorx?
        static void ins_ternary_imm(INS ins) {
            uninstrumented(ins, "rotate ternary imm");
        }
        static void ins_ternary_op(INS ins) {
            uninstrumented(ins, "rotate ternary");
        }
    };

} // namespace

void ins_lshift_op(INS ins) {
    lshift_instrumentation::ins_op(ins);
}
void ins_rotate_op(INS ins, bool left, bool carry) {
    if (left) {
        if (carry)
            rotate_instrumentation<true, true>::ins_op(ins);
        else
            rotate_instrumentation<true, false>::ins_op(ins);
    } else {
        if (carry)
            rotate_instrumentation<false, true>::ins_op(ins);
        else
            rotate_instrumentation<false, false>::ins_op(ins);
    }
}
