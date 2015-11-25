
#include <string.h>
#include <stdlib.h>
#include "types/instruction.h"
#include "types/private/instruction.h"
#include "types/operand.h"
#include "types/instructionType.h"

Instruction *createInstruction(InstructionType *instrType, Operand *op) {
	Instruction *instr = malloc(sizeof(Instruction));

	instr->type    = instrType;
	instr->operand = op;
	instr->free    = &freeInstruction;

	return instr;
}

void freeInstruction(Instruction *instr) {
	instr->operand->free(instr->operand);
	free(instr);
}