
#include <stdlib.h>
#include <string.h>
#include "types/operand.h"
#include "types/private/operand.h"
#include "types/operandType.h"

Operand *createOperand(char *token, OperandType **validTypes) {
	OperandType *opType = NULL;

	for (int i = 0; validTypes[i] != NULL; i++) {
		if (validTypes[i]->validate(token)) {
			opType = validTypes[i];
		}
	}

	if (opType == NULL) {
		return NULL;
	}

	Operand *op = malloc(sizeof(Operand));

	strcpy(op->content, token);

	op->type     = opType;
	op->getValue = &getOperandValue;

	return op;
}

long long getOperandValue(Operand *this, Assembler *asm) {
	return this->type->getValue(this->content, asm);
}

void freeOperand(Operand *op) {
	free(op);
}
