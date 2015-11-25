
#include <stdbool.h>
#include "operandTypes/symbol.h"
#include "types/assembler.h"
#include "types/table.h"
#include "types/operandType.h"
#include "types/operand.h"
#include "types/label.h"
#include "types/location.h"
#include "operandTypes/instructionLabel.h"
#include "util.h"
#include "error.h"

bool validateInstructionLabelOpType(const char *token) {
	return isSymbol(token);
}

long long getInstructionLabelOpTypeValue(const char *token, Assembler *asmb) {
	Table *labelTable = asmb->labelTable;

	Label *lab = labelTable->getItem(labelTable, token);

	if (lab == NULL) {
		reportError(ERROR_UNDEFINED_LABEL, asmb->fileLine);
	}

	return lab->location->address;
}