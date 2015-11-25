
#include "types/assembler.h"
#include "types/operand.h"
#include "types/operandType.h"
#include "types/table.h"
#include "types/directiveType.h"
#include "directiveTypes/set.h"
#include "types/symbol.h"

bool executeSetDirective(DirectiveType *this, Operand* firstOp, Operand *secondOp, Assembler *asmb) {
	Table *symbolTable = asmb->symbolTable;
	Symbol *sym = createSymbol(firstOp->content, secondOp);

	symbolTable->addItem(symbolTable, sym);

	return true;
}