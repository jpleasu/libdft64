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

    struct lshift_shld : public instrumentation_base<lshift_shld> {
        template <char dcode, char scode, char shftcode, size_t sz>
        static void HOOK_DECL ternary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                      typename Tagset<scode>::arg_type src, typename Tagset<shftcode>::arg_type shft) {
            Tagset<dcode> dst_tags(tid, dst);
            TagsetCopy<sz> src_tags(Tagset<scode>(tid, src));
            Tagset<shftcode> shft_tags(tid, shft);

            tag_t t = shft_tags.get(0);
            for (size_t i = 0; i < sz; ++i)
                t = tag_combine(t, src_tags.get(i));
            for (size_t i = 0; i < sz; ++i) {
                t = tag_combine(t, dst_tags.get(i));
                dst_tags.set(i, t);
            }
        }
    };

    template <int byte_shift, bool slop>
    struct lshift_imm : public instrumentation_base<lshift_imm<byte_shift, slop>> {

        // shl
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
            // stub for switch
        }

        // shld
        template <char dcode, char scode, size_t sz>
        static typename enable_if<(byte_shift < (sz < 32 ? sz * 2 : sz))>::type HOOK_DECL
        binary(THREADID tid, typename Tagset<dcode>::arg_type dst, typename Tagset<scode>::arg_type src) {
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
        static typename enable_if<(byte_shift >= (sz < 32 ? sz * 2 : sz))>::type HOOK_DECL
        binary(THREADID tid, typename Tagset<dcode>::arg_type dst, typename Tagset<scode>::arg_type src) {
            // stub for switch
        }
    };

    struct lshift_instrumentation : public instrumentation_base<lshift_instrumentation> {
        static void ins_unary_imm(INS ins) {
            uninstrumented(ins, "lshift unary imm");
        }
        static void ins_unary_op(INS ins) {
            // shl OP_1 is implicit when it's CL or 0x1
            if (INS_OperandIsImplicit(ins, OP_1)) {
                if (INS_OperandIsImmediate(ins, OP_1))
                    ins_binary_imm(ins);
                else if (INS_OperandIsReg(ins, OP_1)) {
                    base_t::ins_binary_op(ins);
                } else {
                    uninstrumented(ins, "lshift unary impl");
                    dump_instruction(ins);
                }
            } else {
                uninstrumented(ins, "lshift unary");
                dump_instruction(ins);
            }
        }

        // shl
        static void ins_binary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_1);
            UINT32 w = INS_OperandWidth(ins, OP_0);

            if ((val & 0x1f) >= w) {
                ins_clear_op(ins);
                return;
            }
            int shft = val % w;
            bool slop = shft % 8 != 0;
#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case (SHIFT):                                                                                                      \
        if (slop)                                                                                                      \
            lshift_imm<SHIFT, true>::ins_unary_op(ins);                                                                \
        else                                                                                                           \
            lshift_imm<SHIFT, false>::ins_unary_op(ins);                                                               \
        break;

            SWITCH8(shft / 8);
        }

        static void ins_binary_op(INS ins) {
            // shld OP_2 is implicit if it's CL
            if (INS_OperandIsImplicit(ins, OP_2)) {
                if (INS_OperandIsReg(ins, OP_2))
                    lshift_shld::ins_ternary_op(ins);
                else {
                    uninstrumented(ins, "lshift binary impl");
                    dump_instruction(ins);
                }
            } else {
                base_t::ins_binary_op(ins);
            }
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
            if (w <= 32)
                val &= 0x1f;
            val &= 0x3f;

            int shft = val;
            bool slop = shft % 8 != 0;

#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case (SHIFT):                                                                                                      \
        if (slop)                                                                                                      \
            lshift_imm<SHIFT, true>::ins_binary_op(ins);                                                               \
        else                                                                                                           \
            lshift_imm<SHIFT, false>::ins_binary_op(ins);                                                              \
        break;

            SWITCH8(shft / 8);
        }

        // shlx only (shld's OP_2 is implicit)
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

    struct rshift_shrd : public instrumentation_base<rshift_shrd> {
        template <char dcode, char scode, char shftcode, size_t sz>
        static void HOOK_DECL ternary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                      typename Tagset<scode>::arg_type src, typename Tagset<shftcode>::arg_type shft) {
            Tagset<dcode> dst_tags(tid, dst);
            TagsetCopy<sz> src_tags(Tagset<scode>(tid, src));
            Tagset<shftcode> shft_tags(tid, shft);

            // XXX
            tag_t t = shft_tags.get(0);
            for (size_t i = 0; i < sz; ++i)
                t = tag_combine(t, src_tags.get(i));
            for (size_t i = 0; i < sz; ++i) {
                t = tag_combine(t, dst_tags.get(i));
                dst_tags.set(i, t);
            }
        }
    };

    template <bool is_signed, int byte_shift, bool slop>
    struct rshift_imm : public instrumentation_base<rshift_imm<is_signed, byte_shift, slop>> {
        // shr
        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift < sz)>::type HOOK_DECL unary(THREADID tid,
                                                                           typename Tagset<dcode>::arg_type dst) {
            Tagset<dcode> dst_tags(tid, dst);

            for (size_t i = 0; i + byte_shift < sz; ++i)
                dst_tags.set(i, dst_tags.get(i + byte_shift));

            const tag_t t = is_signed ? dst_tags.get(sz - 1) : tag_traits<tag_t>::cleared_val;
            for (size_t i = sz - byte_shift; i < sz; ++i)
                dst_tags.set(i, t);

            if (slop) {
                for (size_t i = 0; i + byte_shift + 1 < sz; ++i)
                    dst_tags.add(i, dst_tags.get(i + byte_shift + 1));
            }
            dst_tags.template zext<sz>();
        }
        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift >= sz)>::type HOOK_DECL unary(THREADID tid,
                                                                            typename Tagset<dcode>::arg_type dst) {
            // stub for switch
        }
    };

    template <bool is_signed>
    struct rshift_instrumentation : public instrumentation_base<rshift_instrumentation<is_signed>> {
        using typename instrumentation_base<rshift_instrumentation<is_signed>>::base_t;
        static void ins_unary_imm(INS ins) {
            uninstrumented(ins, "rshift unary imm");
            dump_instruction(ins);
        }
        static void ins_unary_op(INS ins) {
            // sar/shr OP_1 is implicit if it's CL or 1
            if (INS_OperandIsImplicit(ins, OP_1)) {
                if (INS_OperandIsImmediate(ins, OP_1)) {
                    ins_binary_imm(ins);
                } else if (INS_OperandIsReg(ins, OP_1)) {
                    base_t::ins_binary_op(ins);
                } else {
                    uninstrumented(ins, "rshift unary impl");
                }
            } else {
                uninstrumented(ins, "rshift unary");
                dump_instruction(ins);
            }
        }

        static void ins_binary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_1);
            UINT32 w = INS_OperandWidth(ins, OP_0);
            if ((val & 0x1f) >= w) {
                ins_clear_op(ins);
                return;
            }

            int rshft = val % w;
            bool slop = (rshft % 8) != 0;
#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case SHIFT:                                                                                                        \
        if (slop)                                                                                                      \
            rshift_imm<is_signed, SHIFT, true>::ins_unary_op(ins);                                                     \
        else                                                                                                           \
            rshift_imm<is_signed, SHIFT, false>::ins_unary_op(ins);                                                    \
        break;

            SWITCH8(rshft / 8);
        }

        static void ins_binary_op(INS ins) {
            // shrd OP_2 is implicit if it's CL
            if (INS_OperandIsImplicit(ins, OP_2)) {
                if (INS_OperandIsReg(ins, OP_2)) {
                    rshift_shrd::ins_ternary_op(ins);
                } else {
                    uninstrumented(ins, "rshift binary impl");
                }
            } else {
                uninstrumented(ins, "rshift binary");
            }
        }

        template <char dcode, char scode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<scode>::arg_type src) {
            // XXX
        }

#if 0
        // shrd
        static void ins_ternary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_2);
            UINT32 w = INS_OperandWidth(ins, OP_0);
            if ((val & 0x1f) >= w) {
                ins_clear_op(ins);
                return;
            }
            int shft = val % w;
            bool slop = shft % 8 != 0;

#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case (SHIFT):                                                                                                      \
        if (slop)                                                                                                      \
            rshift_imm<is_signed, SHIFT, true>::ins_binary_op(ins);                                                    \
        else                                                                                                           \
            rshift_imm<is_signed, SHIFT, false>::ins_binary_op(ins);                                                   \
        break;

            SWITCH8(shft / 8);
        }
#endif
        // shrx
        template <char dcode, char scode, char shftcode, size_t sz>
        static void HOOK_DECL ternary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                      typename Tagset<scode>::arg_type src, typename Tagset<shftcode>::arg_type shft) {
            // XXX
        }
    };

    // right rotation in byte_shift bytes,
    template <int byte_shift, bool lslop, bool rslop>
    struct rotate_imm : public instrumentation_base<rotate_imm<byte_shift, lslop, rslop>> {
        using typename instrumentation_base<rotate_imm<byte_shift, lslop, rslop>>::instrumentation_t;

        template <char dcode, char scode, size_t sz>
        static typename enable_if<(byte_shift <= sz)>::type HOOK_DECL binary(THREADID tid,
                                                                             typename Tagset<dcode>::arg_type dst,
                                                                             typename Tagset<scode>::arg_type src) {
            Tagset<dcode> dst_tags(tid, dst);
            TagsetCopy<sz> src_tags(Tagset<scode>(tid, src));

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
        template <char dcode, char scode, size_t sz>
        static typename enable_if<(byte_shift > sz)>::type HOOK_DECL binary(THREADID tid,
                                                                            typename Tagset<dcode>::arg_type dst,
                                                                            typename Tagset<scode>::arg_type src) {
            // stub for switch
        }
        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift <= sz)>::type HOOK_DECL unary(THREADID tid,
                                                                            typename Tagset<dcode>::arg_type dst) {
            instrumentation_t::template binary<dcode, dcode, sz>(tid, dst, dst);
        }

        template <char dcode, size_t sz>
        static typename enable_if<(byte_shift > sz)>::type HOOK_DECL unary(THREADID tid,
                                                                           typename Tagset<dcode>::arg_type dst) {
            // stub for switch
        }
    };

    template <bool left, bool carry>
    struct rotate_instrumentation : public instrumentation_base<rotate_instrumentation<left, carry>> {
        using typename instrumentation_base<rotate_instrumentation<left, carry>>::instrumentation_t;

        static void ins_unary_imm(INS ins) {
            uninstrumented(ins, "rotate unary imm");
        }
        static void ins_unary_op(INS ins) {
            // rol OP_1 is implicit when it's 1 or CL
            if (INS_OperandIsImplicit(ins, OP_1)) {
                if (INS_OperandIsImmediate(ins, OP_1)) {
                    instrumentation_t::ins_binary_imm(ins);
                } else if (INS_OperandIsReg(ins, OP_1)) {
                    instrumentation_t::ins_binary_op(ins);
                } else {
                    uninstrumented(ins, "rotate unary impl");
                    dump_instruction(ins);
                }
            } else {
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
                rotate_imm<SHIFT, true, true>::ins_unary_op(ins);                                                      \
            else                                                                                                       \
                rotate_imm<SHIFT, true, false>::ins_unary_op(ins);                                                     \
        } else {                                                                                                       \
            if (rslop)                                                                                                 \
                rotate_imm<SHIFT, false, true>::ins_unary_op(ins);                                                     \
            else                                                                                                       \
                rotate_imm<SHIFT, false, false>::ins_unary_op(ins);                                                    \
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

        // rorx
        static void ins_ternary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_2);
            UINT32 w = INS_OperandWidth(ins, OP_0);
            int rshft = val % w;

            bool slop = (rshft % 8) != 0;
#undef CASE
#define CASE(SHIFT)                                                                                                    \
    case (SHIFT):                                                                                                      \
        if (slop) {                                                                                                    \
            rotate_imm<SHIFT, true, true>::ins_binary_op(ins);                                                         \
        } else {                                                                                                       \
            rotate_imm<SHIFT, false, false>::ins_binary_op(ins);                                                       \
        }                                                                                                              \
        break;

            SWITCH8(rshft / 8);
        }

        static void ins_ternary_op(INS ins) {
            uninstrumented(ins, "rotate ternary");
        }
    };

} // namespace

void ins_lshift_op(INS ins) {
    lshift_instrumentation::ins_op(ins);
}

void ins_rshift_op(INS ins, bool is_signed) {
    if (is_signed)
        rshift_instrumentation<true>::ins_op(ins);
    else
        rshift_instrumentation<false>::ins_op(ins);
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
