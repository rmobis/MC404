
#include <stdbool.h>
#include <stdlib.h>

#include "types/assembler.h"
#include "types/operandType.h"
#include "types/private/operandType.h"

OperandType *createOperandType(bool(*validate)(char const*), long long(*getValue)(char const*, Assembler*)) {
	OperandType *opType = malloc(sizeof(OperandType));

	opType->validate = validate;
	opType->getValue = getValue;
	opType->free     = freeOperandType;

	return opType;
}

void freeOperandType(OperandType *this) {
	free(this);
}