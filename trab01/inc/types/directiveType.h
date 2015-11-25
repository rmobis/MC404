/**
 * Directive Type Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdlib.h>
#include "types/typedefs.h"

typedef bool (*ExecuteDirectiveMethod)(DirectiveType*, Operand*, Operand*, Assembler*);

struct DirectiveType {
	char *mnemonic;
	bool hasSecondOperand;
	OperandType *firstOperandTypes[3 + 1];
	OperandType *secondOperandTypes[3 + 1];

	ExecuteDirectiveMethod execute;
	void (*free)(DirectiveType*);
};

DirectiveType *createDirectiveType(char *mnemonic, bool hasSecondOp, OperandType **firstOpTypes, OperandType **secondOpTypes, ExecuteDirectiveMethod executeMethod);

