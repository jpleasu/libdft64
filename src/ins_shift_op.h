
#ifndef __INS_SHIFT_OP_H__
#define __INS_SHIFT_OP_H__
#include "pin.H"

void ins_lshift_op(INS ins);
void ins_rshift_op(INS ins, bool is_signed);
void ins_rotate_op(INS ins, bool left, bool carry);

#endif
