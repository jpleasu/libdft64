#ifndef __INS_BINARY_OP_H__
#define __INS_BINARY_OP_H__
#include "pin.H"

void ins_binary_op(INS ins);
void ins_bytecasc_op(INS ins);
void ins_bytecasc_op(INS ins, UINT64 nopval);
void ins_bytevec_op(INS ins);
void ins_bytevec_op(INS ins, uint8_t maskval);

#endif
