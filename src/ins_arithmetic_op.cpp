#include "ins_arithmetic_op.h"
#include "ins_helper.h"

namespace {
    template <bool b, typename T = void>
    struct enable_if;

    template <typename T>
    struct enable_if<true, T> {
        using type = T;
    };
    struct unary_clear : public instrumentation_base<unary_clear> {
        template <char dcode, size_t sz>
        static void HOOK_DECL unary(THREADID tid, typename Tagset<dcode>::arg_type dst) {
            Tagset<dcode> dst_tags(tid, dst);
            for (size_t i = 0; i < sz; i++) {
                dst_tags.set(i, tag_traits<tag_t>::cleared_val);
            }
            dst_tags.template zext<sz>();
        }
    };

    struct mul_casc : public instrumentation_base<mul_casc> {
        // cascade dst into dst
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
        // cascade src into dst
        template <char scode, char dcode, size_t sz>
        static void HOOK_DECL binary(THREADID tid, typename Tagset<dcode>::arg_type dst,
                                     typename Tagset<scode>::arg_type src) {
            Tagset<scode> src_tags(tid, src);
            Tagset<dcode> dst_tags(tid, dst);

            tag_t t = src_tags.get(0);
            dst_tags.set(0, t);
            for (size_t i = 1; i < sz; i++) {
                t = tag_combine(t, src_tags.get(i));
                dst_tags.set(i, t);
            }

            dst_tags.template zext<sz>();
        }
    };

    struct mul_instrumentation : public instrumentation_base<mul_instrumentation> {
        static void ins_unary_imm(INS ins) {
            uninstrumented(ins, "mul unary imm");
        }

        // unary MUL and MUL are the same
        template <char scode, size_t sz>
        static typename enable_if<sz != 1>::type HOOK_DECL unary(THREADID tid, typename Tagset<scode>::arg_type src) {
            // implicit source is the A register
            // implicit destination is D:A registers
            Tagset<'r'> a_tags(tid, DFT_REG_RAX);
            Tagset<'r'> d_tags(tid, DFT_REG_RDX);
            Tagset<scode> src_tags(tid, src);
            tag_t t = tag_combine(a_tags.get(0), src_tags.get(0));
            a_tags.set(0, t);
            for (size_t i = 1; i < sz; i++) {
                t = tag_combine(t, a_tags.get(i), src_tags.get(i));
                a_tags.set(i, t);
            }
            for (size_t i = 0; i < sz; i++)
                d_tags.set(i, t);

            a_tags.template zext<sz>();
            d_tags.template zext<sz>();
        }

        template <char scode, size_t sz>
        static typename enable_if<sz == 1>::type HOOK_DECL unary(THREADID tid, typename Tagset<scode>::arg_type src) {
            // implicit source is the AL register
            // implicit destination is AX register
            Tagset<'r'> a_tags(tid, DFT_REG_RAX);
            Tagset<scode> src_tags(tid, src);
            tag_t t = tag_combine(a_tags.get(0), src_tags.get(0));
            a_tags.set(0, t);
            a_tags.set(1, t);
        }

        static void ins_binary_imm(INS ins) {
            UINT64 val = INS_OperandImmediate(ins, OP_1);
            if (val == 0ul) {
                unary_clear::ins_unary_op(ins);
            } else {
                mul_casc::ins_unary_op(ins);
            }
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

        static void ins_ternary_imm(INS ins) {
            // instrumentation_t::ins_binary_op(ins);
            UINT64 val = INS_OperandImmediate(ins, OP_2);
            if (val == 0ul) {
                unary_clear::ins_unary_op(ins);
            } else {
                mul_casc::ins_binary_op(ins);
            }
        }
        static void ins_ternary_op(INS ins) {
            uninstrumented(ins, "mul ternary");
            dump_instruction(ins);
        }
    };
} // namespace

static void PIN_FAST_ANALYSIS_CALL r2r_unary_opb_u(THREADID tid, uint32_t src) {
    tag_t tmp_tag = RTAG[src][1];

    RTAG[DFT_REG_RAX][0] = tag_combine(RTAG[DFT_REG_RAX][0], tmp_tag);
    RTAG[DFT_REG_RAX][1] = tag_combine(RTAG[DFT_REG_RAX][1], tmp_tag);
}

static void PIN_FAST_ANALYSIS_CALL r2r_unary_div_opb_l(THREADID tid, uint32_t src) {
    tag_t tmp_tag = tag_combine(RTAG[DFT_REG_RAX][0], RTAG[src][0]);
    tmp_tag = tag_combine(tmp_tag, RTAG[DFT_REG_RAX][1]);

    RTAG[DFT_REG_RAX][0] = tmp_tag; // quotient
    RTAG[DFT_REG_RAX][1] = tmp_tag; // remainder
}

template <size_t sz>
static void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
r2r_unary_div_op(THREADID tid, uint32_t src) {
    tag_t *src_tag = RTAG[src];
    tag_t *a_tag = RTAG[DFT_REG_RAX];
    tag_t *d_tag = RTAG[DFT_REG_RDX];

    tag_t tmp_tag = tag_combine(src_tag[0], a_tag[0], d_tag[0]);
    for (size_t i = 1; i < sz; ++i) {
        tmp_tag = tag_combine(tmp_tag, src_tag[i], a_tag[i], d_tag[i]);
    }

    for (size_t i = 0; i < sz; ++i) {
        // remainder
        a_tag[i] = tmp_tag;
        // quotient
        d_tag[i] = tmp_tag;
    }
    maybe_zext<sz>(a_tag);
    maybe_zext<sz>(d_tag);
}

template <size_t sz>
static void PIN_FAST_ANALYSIS_CALL __attribute__((optimize("unroll-loops")))
r2r_unary_mul_op(THREADID tid, uint32_t src) {
    tag_t *src_tag = RTAG[src];
    tag_t *a_tag = RTAG[DFT_REG_RAX];
    tag_t *d_tag = RTAG[DFT_REG_RDX];
    tag_t acc;

    acc = a_tag[0] = tag_combine(src_tag[0], a_tag[0]);
    for (size_t i = 1; i < sz; i++) {
        acc = a_tag[i] = tag_combine(acc, src_tag[i], a_tag[i]);
    }

    for (size_t i = 0; i < sz; i++) {
        d_tag[i] = acc;
    }

    maybe_zext<sz>(d_tag);
    maybe_zext<sz>(a_tag);
}

static void PIN_FAST_ANALYSIS_CALL m2r_unary_opb(THREADID tid, ADDRINT src) {
    tag_t tmp_tag = MTAG(src);
    tag_t dst_tag[] = R16TAG(DFT_REG_RAX);

    RTAG[DFT_REG_RAX][0] = tag_combine(dst_tag[0], tmp_tag);
    RTAG[DFT_REG_RAX][1] = tag_combine(dst_tag[1], tmp_tag);
}

static void PIN_FAST_ANALYSIS_CALL m2r_unary_opw(THREADID tid, ADDRINT src) {
    tag_t tmp_tag[] = M16TAG(src);
    tag_t dst1_tag[] = R16TAG(DFT_REG_RDX);
    tag_t dst2_tag[] = R16TAG(DFT_REG_RAX);

    for (size_t i = 0; i < 2; i++) {
        RTAG[DFT_REG_RDX][i] = tag_combine(dst1_tag[i], tmp_tag[i]);
        RTAG[DFT_REG_RAX][i] = tag_combine(dst2_tag[i], tmp_tag[i]);
    }
}

static void PIN_FAST_ANALYSIS_CALL m2r_unary_opq(THREADID tid, ADDRINT src) {
    tag_t tmp_tag[] = M64TAG(src);
    tag_t dst1_tag[] = R64TAG(DFT_REG_RDX);
    tag_t dst2_tag[] = R64TAG(DFT_REG_RAX);

    for (size_t i = 0; i < 8; i++) {
        RTAG[DFT_REG_RDX][i] = tag_combine(dst1_tag[i], tmp_tag[i]);
        RTAG[DFT_REG_RAX][i] = tag_combine(dst2_tag[i], tmp_tag[i]);
    }
}

static void PIN_FAST_ANALYSIS_CALL m2r_unary_opl(THREADID tid, ADDRINT src) {
    tag_t tmp_tag[] = M32TAG(src);
    tag_t dst1_tag[] = R32TAG(DFT_REG_RDX);
    tag_t dst2_tag[] = R32TAG(DFT_REG_RAX);

    for (size_t i = 0; i < 4; i++) {
        RTAG[DFT_REG_RDX][i] = tag_combine(dst1_tag[i], tmp_tag[i]);
        RTAG[DFT_REG_RAX][i] = tag_combine(dst2_tag[i], tmp_tag[i]);
    }
}

void ins_div_op(INS ins) {
    if (INS_OperandIsMemory(ins, OP_0))
        switch (INS_MemoryWriteSize(ins)) {
        case BIT2BYTE(MEM_64BIT_LEN):
            M_CALL_R(m2r_unary_opq);
            break;
        case BIT2BYTE(MEM_LONG_LEN):
            M_CALL_R(m2r_unary_opl);
            break;
        case BIT2BYTE(MEM_WORD_LEN):
            M_CALL_R(m2r_unary_opw);
            break;
        case BIT2BYTE(MEM_BYTE_LEN):
        default:
            M_CALL_R(m2r_unary_opb);
            break;
        }
    else {
        REG reg_src = INS_OperandReg(ins, OP_0);
        if (REG_is_gr64(reg_src))
            R_CALL(r2r_unary_div_op<8>, reg_src);
        else if (REG_is_gr32(reg_src))
            R_CALL((r2r_unary_div_op<4>), reg_src);
        else if (REG_is_gr16(reg_src))
            R_CALL((r2r_unary_div_op<2>), reg_src);
        else if (REG_is_Upper8(reg_src))
            R_CALL(r2r_unary_opb_u, reg_src);
        else
            R_CALL(r2r_unary_div_opb_l, reg_src);
    }
}

void ins_mul_op(INS ins) {
    mul_instrumentation::ins_op(ins);
}
