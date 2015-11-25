
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "types/assembler.h"
#include "types/instructionType.h"
#include "types/private/instructionType.h"

InstructionType *createInstructionType(char *mnemonic, int machineCode, bool hasAlignment, bool hasOp) {
	InstructionType *instrType = malloc(sizeof(InstructionType));

	strcpy(instrType->mnemonic, mnemonic);
	instrType->machineCode = machineCode;
	instrType->hasAlignment = hasAlignment;
	instrType->hasOperand = hasOp;

	instrType->getRepresentation = getInstructionTypeRepresentation;
	instrType->free     = freeInstructionType;

	return instrType;
}

void getInstructionTypeRepresentation(InstructionType *this, Instruction *instr, Assembler *asmb, char buffer[5]) {

}

void freeInstructionType(InstructionType *this) {
	free(this);
}