/**
 * Instruction Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include "types/typedefs.h"

struct Instruction {
	Operand *operand;
	InstructionType *type;

	void (*free)(Instruction*);
};

Instruction *createInstruction(InstructionType *instrType, Operand *op);
