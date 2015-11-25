/**
 * STOR M(X, Y:Z) Instruction API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

char* getStorAInstrOperandValue(InstructionType *this, Instruction* instr, Assembler *asmb);