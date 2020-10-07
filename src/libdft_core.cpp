#include "libdft_core.h"
#include "ins_helper.h"

#include "ins_binary_op.h"
#include "ins_clear_op.h"
#include "ins_movsx_op.h"
#include "ins_punpck_op.h"
#include "ins_unary_op.h"
#include "ins_xchg_op.h"
#include "ins_xfer_op.h"

/* threads context */
extern thread_ctx_t *threads_ctx;

template <size_t sz>
static void HOOK_DECL sext_a(THREADID tid) {
    tag_t *rtag = RTAG[DFT_REG_RAX];
    tag_t signbyte = rtag[sz - 1];
    for (size_t i = 0; i < sz; ++i) {
        rtag[sz + i] = signbyte;
    }
}
template <size_t sz>
static void HOOK_DECL sext_ad(THREADID tid) {
    tag_t signbyte = RTAG[DFT_REG_RAX][sz - 1];
    tag_t *dstrtag = RTAG[DFT_REG_RDX];
    for (size_t i = 0; i < sz; i++)
        dstrtag[i] = signbyte;
}

template <size_t sz>
static void HOOK_DECL m2r_restore_op(THREADID tid, ADDRINT src) {
    size_t offset = src;
    for (size_t ri = 0; ri < 8; ++ri) {
        if (ri == DFT_REG_RSP)
            continue;
        tag_t *dst_tags = RTAG[DFT_REG_RDI + ri];
        for (size_t i = 0; i < sz; ++i)
            dst_tags[i] = tagmap_getb(offset++);
    }
}
template <size_t sz>
static void HOOK_DECL r2m_save_op(THREADID tid, ADDRINT dst) {
    size_t offset = dst;
    for (size_t ri = 0; ri < 8; ++ri) {
        if (ri == DFT_REG_RSP)
            continue;
        tag_t *src_tags = RTAG[DFT_REG_RDI + ri];
        for (size_t i = 0; i < sz; ++i)
            tagmap_setb(offset++, src_tags[i]);
    }
}

static bool reg_eq(INS ins) {
    return (!INS_OperandIsImmediate(ins, OP_1) && INS_MemoryOperandCount(ins) == 0 &&
            INS_OperandReg(ins, OP_0) == INS_OperandReg(ins, OP_1));
}

static void PIN_FAST_ANALYSIS_CALL r_clrq_zext(THREADID tid, uint32_t reg) {
    for (size_t i = 4; i < 8; i++) {
        RTAG[reg][i] = tag_traits<tag_t>::cleared_val;
    }
}

void ins_uni(INS ins) {
    if (INS_OperandCount(ins) < 1)
        return;
    if (INS_OperandIsReg(ins, OP_0) && INS_OperandWritten(ins, OP_0)) {
        REG reg_dst = INS_OperandReg(ins, OP_0);
        if (REG_is_gr32(reg_dst)) {
            R_CALL(r_clrq_zext, reg_dst);
        }
    }
}

void ins_binary_mul_op(INS ins) {
    ins_binary_op(ins);
}

void ins_binary_div_op(INS ins) {
    ins_binary_op(ins);
}
/*
 * instruction inspection (instrumentation function)
 *
 * analyze every instruction and instrument it
 * for propagating the tag bits accordingly
 *
 * @ins:	the instruction to be instrumented
 */
void ins_inspect(INS ins) {

    /* use XED to decode the instruction and extract its opcode */
    xed_iclass_enum_t ins_indx = (xed_iclass_enum_t)INS_Opcode(ins);
    /* sanity check */
    if (unlikely(ins_indx <= XED_ICLASS_INVALID || ins_indx >= XED_ICLASS_LAST)) {
        LOG(std::string(__func__) + ": unknown opcode (opcode=" + decstr(ins_indx) + ")\n");
        /* done */
        return;
    }

    // LOGD("[ins] %s \n", INS_Disassemble(ins).c_str());
    /*
    char *cstr;
    cstr = new char[INS_Disassemble(ins).size() + 1];
    strcpy(cstr, INS_Disassemble(ins).c_str());
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)dasm, IARG_PTR, cstr, IARG_END);
    */

    switch (ins_indx) {
    // **** logical ****
    case XED_ICLASS_AND:
    case XED_ICLASS_PAND:
    case XED_ICLASS_ANDN:
        ins_bytevec_op(ins, 0x00);
        break;
    case XED_ICLASS_OR:
    case XED_ICLASS_POR:
        ins_bytevec_op(ins, 0xff);
        break;
    case XED_ICLASS_XOR:
    case XED_ICLASS_XORPS:
    case XED_ICLASS_XORPD:
    case XED_ICLASS_PXOR:
        ins_bytevec_op(ins);
        break;

    // **** arithmetic ****
    case XED_ICLASS_ADC: // there is no tagging of CF, assume it can be anything.. always carry
        ins_bytecasc_op(ins);
        break;
    case XED_ICLASS_ADD:
    case XED_ICLASS_ADD_LOCK:
    case XED_ICLASS_ADDPD:
    case XED_ICLASS_ADDSD:
    case XED_ICLASS_ADDSS:
        ins_bytecasc_op(ins, 0ul);
        break;
    case XED_ICLASS_SBB:
    case XED_ICLASS_SUB:
    case XED_ICLASS_SUBSD:
    case XED_ICLASS_PSUBB:
    case XED_ICLASS_PSUBW:
    case XED_ICLASS_PSUBD:
        if (reg_eq(ins)) {
            ins_clear_op(ins);
        } else {
            ins_bytecasc_op(ins);
        }
        break;
    case XED_ICLASS_DIV:
    case XED_ICLASS_IDIV:
        ins_unary_div_op(ins);
        break;
    case XED_ICLASS_MUL:
        ins_unary_mul_op(ins);
        break;
    case XED_ICLASS_IMUL:
        if (INS_OperandIsImplicit(ins, OP_1)) {
            ins_unary_mul_op(ins);
        } else {
            ins_binary_mul_op(ins);
            // if ternary // TODO
        }
        break;
    case XED_ICLASS_MULSD:
    case XED_ICLASS_MULPD:
        ins_binary_mul_op(ins);
        break;
    case XED_ICLASS_DIVSD:
        ins_binary_div_op(ins);
        break;

    case XED_ICLASS_LEA:
        ins_lea(ins);
        break;

    // **** xfer ****
    case XED_ICLASS_BSF:
    case XED_ICLASS_BSR:
    case XED_ICLASS_TZCNT:
    case XED_ICLASS_MOV:
        if (INS_OperandIsImmediate(ins, OP_1) ||
            (INS_OperandIsReg(ins, OP_1) && REG_is_seg(INS_OperandReg(ins, OP_1)))) {
            ins_clear_op(ins);
        } else {
            ins_xfer_op(ins);
        }
        break;

    case XED_ICLASS_MOVD:
    case XED_ICLASS_MOVQ:
    case XED_ICLASS_MOVAPS:
    case XED_ICLASS_MOVAPD:
    case XED_ICLASS_MOVDQU:
    case XED_ICLASS_MOVDQA:
    case XED_ICLASS_MOVUPS:
    case XED_ICLASS_MOVUPD:
    case XED_ICLASS_MOVSS:
    // only xmm, ymm
    case XED_ICLASS_VMOVD:
    case XED_ICLASS_VMOVQ:
    case XED_ICLASS_VMOVAPS:
    case XED_ICLASS_VMOVAPD:
    case XED_ICLASS_VMOVDQU:
    case XED_ICLASS_VMOVDQA:
    case XED_ICLASS_VMOVUPS:
    case XED_ICLASS_VMOVUPD:
    case XED_ICLASS_VMOVSS:
    case XED_ICLASS_MOVSD_XMM:
    case XED_ICLASS_CVTSI2SD:
    case XED_ICLASS_CVTSD2SI:
        ins_xfer_op(ins);
        break;
    case XED_ICLASS_MOVLPD:
    case XED_ICLASS_MOVLPS:
        ins_movlp(ins);
        break;
    // case XED_ICLASS_VMOVLPD:
    // case XED_ICLASS_VMOVLPS:
    case XED_ICLASS_MOVHPD:
    case XED_ICLASS_MOVHPS:
        ins_movhp(ins);
        break;
    // case XED_ICLASS_VMOVHPD:
    // case XED_ICLASS_VMOVHPS:
    // case XED_ICLASS_MOVHLPS:
    // case XED_ICLASS_VMOVHLPS:
    case XED_ICLASS_CMOVB:
    case XED_ICLASS_CMOVBE:
    case XED_ICLASS_CMOVL:
    case XED_ICLASS_CMOVLE:
    case XED_ICLASS_CMOVNB:
    case XED_ICLASS_CMOVNBE:
    case XED_ICLASS_CMOVNL:
    case XED_ICLASS_CMOVNLE:
    case XED_ICLASS_CMOVNO:
    case XED_ICLASS_CMOVNP:
    case XED_ICLASS_CMOVNS:
    case XED_ICLASS_CMOVNZ:
    case XED_ICLASS_CMOVO:
    case XED_ICLASS_CMOVP:
    case XED_ICLASS_CMOVS:
    case XED_ICLASS_CMOVZ:
        ins_xfer_op_predicated(ins);
        break;
    case XED_ICLASS_MOVBE:
        ins_movbe_op(ins);
        break;
    case XED_ICLASS_MOVSX:
    case XED_ICLASS_MOVZX:
        ins_movsx_op(ins);
        break;
    case XED_ICLASS_MOVSXD:
        ins_movsxd_op(ins);
        break;
    case XED_ICLASS_CBW:
        CALL((sext_a<1>));
        break;
    case XED_ICLASS_CWDE:
        CALL((sext_a<2>));
        break;
    case XED_ICLASS_CDQE:
        CALL((sext_a<4>));
        break;
    case XED_ICLASS_CWD:
        CALL((sext_ad<2>));
        break;
    case XED_ICLASS_CDQ:
        CALL((sext_ad<4>));
        break;
    case XED_ICLASS_CQO:
        CALL((sext_ad<8>));
        break;

    case XED_ICLASS_XLAT:
        M2R_CALL(m2r_xfer_opb_l, REG_AL);
        break;
    case XED_ICLASS_LODSB:
        M2R_CALL_P(m2r_xfer_opb_l, REG_AL);
        break;
    case XED_ICLASS_LODSW:
        M2R_CALL_P(m2r_xfer_opw, REG_AX);
        break;
    case XED_ICLASS_LODSD:
        M2R_CALL_P(m2r_xfer_opl, REG_EAX);
        break;
    case XED_ICLASS_LODSQ:
        M2R_CALL_P(m2r_xfer_opq, REG_RAX);
        break;
    case XED_ICLASS_STOSB:
        ins_stosb(ins);
        break;
    case XED_ICLASS_STOSW:
        ins_stosw(ins);
        break;
    case XED_ICLASS_STOSD:
        ins_stosd(ins);
        break;
    case XED_ICLASS_STOSQ:
        ins_stosq(ins);
        break;
    case XED_ICLASS_MOVSQ:
        M2M_CALL(m2m_xfer_opq);
        break;
    case XED_ICLASS_MOVSD:
        M2M_CALL(m2m_xfer_opl);
        break;
    case XED_ICLASS_MOVSW:
        M2M_CALL(m2m_xfer_opw);
        break;
    case XED_ICLASS_MOVSB:
        M2M_CALL(m2m_xfer_opb);
        break;

    case XED_ICLASS_PCMPEQB:
        ins_binary_op(ins);
        break;
    case XED_ICLASS_BSWAP:
        ins_unary_bswap_op(ins);
        break;

    // ****** other ******
    case XED_ICLASS_CMPXCHG:
    case XED_ICLASS_CMPXCHG_LOCK:
        ins_cmpxchg_op(ins);
        break;
    case XED_ICLASS_XCHG:
        ins_xchg_op(ins);
        break;
    case XED_ICLASS_XADD:
    case XED_ICLASS_XADD_LOCK:
        ins_xadd_op(ins);
        break;

    case XED_ICLASS_POP:
        ins_pop_op(ins);
        break;
    case XED_ICLASS_PUSH:
        ins_push_op(ins);
        break;
    case XED_ICLASS_POPA:
        M_CALL_R(m2r_restore_op<2>);
        break;
    case XED_ICLASS_POPAD:
        M_CALL_R(m2r_restore_op<4>);
        break;
    case XED_ICLASS_PUSHA:
        M_CALL_W(r2m_save_op<2>);
        break;
    case XED_ICLASS_PUSHAD:
        M_CALL_W(r2m_save_op<4>);
        break;
    case XED_ICLASS_PUSHF:
        M_CLEAR_N(2);
        break;
    case XED_ICLASS_PUSHFD:
        M_CLEAR_N(4);
        break;
    case XED_ICLASS_PUSHFQ:
        M_CLEAR_N(8);
        break;

    case XED_ICLASS_RCL:
    case XED_ICLASS_RCR:
    case XED_ICLASS_ROL:
    case XED_ICLASS_ROR:
    case XED_ICLASS_SHL:
    case XED_ICLASS_SAR:
    case XED_ICLASS_SHR:
    case XED_ICLASS_SHLD:
    case XED_ICLASS_SHRD:
    case XED_ICLASS_NEG:
    case XED_ICLASS_NOT:
    case XED_ICLASS_NOP:
    case XED_ICLASS_BT:
    case XED_ICLASS_DEC:
    case XED_ICLASS_DEC_LOCK:
    case XED_ICLASS_INC:
    case XED_ICLASS_INC_LOCK:
    case XED_ICLASS_XSAVEC:
    case XED_ICLASS_XRSTOR:
        ins_uni(ins);
        break;

    case XED_ICLASS_PUNPCKLBW:
        ins_punpckl_op<1>(ins);
        break;
    case XED_ICLASS_PUNPCKLWD:
        ins_punpckl_op<2>(ins);
        break;
    case XED_ICLASS_PUNPCKLDQ:
        ins_punpckl_op<4>(ins);
        break;
    case XED_ICLASS_PUNPCKLQDQ:
        ins_punpckl_op<8>(ins);
        break;

    // ****** clear op ******
    // TODO: add rules with CMP
    case XED_ICLASS_SETB:
    case XED_ICLASS_SETBE:
    case XED_ICLASS_SETL:
    case XED_ICLASS_SETLE:
    case XED_ICLASS_SETNB:
    case XED_ICLASS_SETNBE:
    case XED_ICLASS_SETNL:
    case XED_ICLASS_SETNLE:
    case XED_ICLASS_SETNO:
    case XED_ICLASS_SETNP:
    case XED_ICLASS_SETNS:
    case XED_ICLASS_SETNZ:
    case XED_ICLASS_SETO:
    case XED_ICLASS_SETP:
    case XED_ICLASS_SETS:
    case XED_ICLASS_SETZ:
        ins_clear_op_predicated(ins);
        break;
    case XED_ICLASS_STMXCSR:
        ins_clear_op(ins);
        break;
    case XED_ICLASS_SMSW:
    case XED_ICLASS_STR:
    case XED_ICLASS_LAR:
        ins_clear_op(ins);
        break;
    case XED_ICLASS_RDPMC:
    case XED_ICLASS_RDTSC:
        ins_clear_op_l2(ins);
        break;
    case XED_ICLASS_CPUID:
        ins_clear_op_l4(ins);
        break;
    case XED_ICLASS_LAHF:
        ins_clear_op(ins);
        break;

    case XED_ICLASS_SALC:
        ins_clear_op(ins);
        break;

    case XED_ICLASS_CMP:
        // ins_cmp_op(ins);
        // break;

    // Ignore
    case XED_ICLASS_JMP:
    case XED_ICLASS_JZ:
    case XED_ICLASS_JNZ:
    case XED_ICLASS_JB:
    case XED_ICLASS_JNB:
    case XED_ICLASS_JBE:
    case XED_ICLASS_JO:
    case XED_ICLASS_JNBE:
    case XED_ICLASS_JL:
    case XED_ICLASS_JNL:
    case XED_ICLASS_JLE:
    case XED_ICLASS_JNLE:
    case XED_ICLASS_JS:
    case XED_ICLASS_JNS:
    case XED_ICLASS_JP:
    case XED_ICLASS_JNP:
    case XED_ICLASS_RET_FAR:
    case XED_ICLASS_RET_NEAR:
    case XED_ICLASS_CALL_FAR:
    case XED_ICLASS_CALL_NEAR:
    case XED_ICLASS_LEAVE:
    case XED_ICLASS_SYSCALL:
    case XED_ICLASS_TEST:
        break;

    // TODO
    case XED_ICLASS_XGETBV:
    case XED_ICLASS_PMOVMSKB:
    case XED_ICLASS_VPMOVMSKB:
    case XED_ICLASS_PSHUFD:
    case XED_ICLASS_PMINUB:
    case XED_ICLASS_PSLLDQ:
    case XED_ICLASS_PSRLDQ:
    case XED_ICLASS_VPCMPEQB:
    case XED_ICLASS_VPBROADCASTB:
    case XED_ICLASS_VZEROUPPER:
    case XED_ICLASS_UNPCKLPD:
    case XED_ICLASS_PSHUFB:
    case XED_ICLASS_VPTEST:
    // TODO: ternary
    case XED_ICLASS_VMULSD:
    case XED_ICLASS_VDIVSD:
    case XED_ICLASS_VPOR:
    case XED_ICLASS_VPXOR:
    case XED_ICLASS_VPSUBB:
    case XED_ICLASS_VPSUBW:
    case XED_ICLASS_VPSUBD:
    case XED_ICLASS_VPXORD:
    case XED_ICLASS_VPXORQ:
    case XED_ICLASS_VPAND:
    case XED_ICLASS_VPANDN:
    case XED_ICLASS_VPSLLDQ:
    case XED_ICLASS_VPCMPGTB:
    case XED_ICLASS_VPALIGNR:
    case XED_ICLASS_VPCMPISTRI:
        // break;
    case XED_ICLASS_CMPSB:
    case XED_ICLASS_CMPSW:
    case XED_ICLASS_CMPSD:
    case XED_ICLASS_CMPSQ:
    case XED_ICLASS_CMPSS: // FIXME, 3arg
    case XED_ICLASS_UCOMISS:
    case XED_ICLASS_UCOMISD:
    case XED_ICLASS_VPMINUB:
    case XED_ICLASS_PCMPISTRI:
        // break;

    default:
        uninstrumented(ins);
        break;
    }
}
