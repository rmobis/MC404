
#include <stdbool.h>
#include "operandTypes/symbol.h"
#include "types/assembler.h"
#include "types/table.h"
#include "types/symbol.h"
#include "types/operand.h"
#include "operandTypes/symbol.h"
#include "util.h"
#include "error.h"

bool validateSymbolOpType(const char *token) {
	return isSymbol(token);
}

long long getSymbolOpTypeValue(const char *token, Assembler *asmb) {
	Table *symbolTable = asmb->symbolTable;

	Symbol *sym = symbolTable->getItem(symbolTable, token);

	if (sym == NULL) {
		reportError(ERROR_UNDEFINED_SYMBOL, asmb->fileLine);
	}

	return sym->value->getValue(sym->value, asmb);
}