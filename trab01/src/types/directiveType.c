
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "types/assembler.h"
#include "types/directiveType.h"
#include "types/private/directiveType.h"

DirectiveType *createDirectiveType(char *mnemonic, bool hasSecondOp, OperandType **firstOpTypes, OperandType **secondOpTypes, ExecuteDirectiveMethod executeMethod) {
	DirectiveType *dirType = malloc(sizeof(DirectiveType));
	int i;

	strcpy(dirType->mnemonic, mnemonic);

	i = 0;
	do {
		dirType->firstOperandTypes[i] = firstOpTypes[i];
	} while (firstOpTypes[i++] != NULL);

	i = 0;
	do {
		dirType->secondOperandTypes[i] = secondOpTypes[i];
	} while (secondOpTypes[i++] != NULL);

	dirType->hasSecondOperand = hasSecondOp;
	dirType->execute = executeMethod;

	dirType->free     = freeDirectiveType;

	return dirType;
}

void freeDirectiveType(DirectiveType *this) {
	free(this);
}