
#include <stdbool.h>
#include "operandTypes/symbol.h"
#include "types/assembler.h"
#include "types/table.h"
#include "types/operandType.h"
#include "types/operand.h"
#include "types/label.h"
#include "types/location.h"
#include "operandTypes/label.h"
#include "util.h"
#include "error.h"

bool validateLabelOpType(const char *token) {
	return isLabel(token);
}

long long getLabelOpTypeValue(const char *token, Assembler *asmb) {
	Table *labelTable = asmb->labelTable;

	Label *lab = labelTable->getItem(labelTable, token);

	if (lab == NULL) {
		reportError(ERROR_UNDEFINED_LABEL, asmb->fileLine);
	}

	return lab->location->address;
}