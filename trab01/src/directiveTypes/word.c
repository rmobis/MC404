
#include "types/assembler.h"
#include "types/operand.h"
#include "types/directiveType.h"
#include "types/memoryMap.h"
#include "directiveTypes/word.h"
#include "types/position.h"
#include "types/location.h"
#include "error.h"

bool executeWordDirective(DirectiveType *this, Operand* firstOp, Operand *secondOp, Assembler *asmb) {
	long long value = firstOp->getValue(firstOp, asmb);

	if (asmb->LC->position == RightPosition) {
		reportError(ERROR_RIGHT_ALIGNED_WORD, asmb->fileLine);
	}

	// TODO: Figure out how to handle when label points to a memory position
	// that is on the right; use values higher than 2^40?
	asmb->memoryMap->addData(asmb->memoryMap, value, asmb->LC);

	asmb->LC->address++;

	return true;
}