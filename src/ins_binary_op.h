#ifndef __INS_BINARY_OP_H__
#define __INS_BINARY_OP_H__
#include "pin.H"

void ins_binary_op(INS ins);

// ins_binary_op except when OP_0 is immediate.  Each byte
// of immediate equal to maskval will clear corresponding position in dst
void ins_binary_bytemask_op(INS ins, uint8_t maskval);

#endif
