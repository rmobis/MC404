/**
 * Instruction Type Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdlib.h>
#include "types/typedefs.h"

#define LABEL_MAX_LENGTH 64

struct InstructionType {
	char *mnemonic;
	int machineCode;
	bool hasAlignment;
	bool hasOperand;
	OperandType *operandTypes[3 + 1];

	void (*getRepresentation)(InstructionType*, Instruction*, Assembler*, char[5]);

	void (*free)(InstructionType*);
};

InstructionType *createInstructionType(char *mnemonic, int machineCode, bool hasAlignment, bool hasOp);

