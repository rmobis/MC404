/**
* Operand Structure API
* Author: Raphael Mobis (r.mobis@gmail.com)
*/

#pragma once

#include <stdbool.h>
#include "types/typedefs.h"

#define OPERAND_MAX_LENGTH 64

struct Operand {
	char content[OPERAND_MAX_LENGTH];
	OperandType *type;

	long long (*getValue)(Operand*, Assembler*);
	void (*free)(Operand*);
};

Operand *createOperand(char *token, OperandType **validTypes);
