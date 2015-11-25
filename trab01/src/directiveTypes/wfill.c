
#include "types/assembler.h"
#include "types/operand.h"
#include "types/directiveType.h"
#include "types/memoryMap.h"
#include "directiveTypes/wfill.h"
#include "types/position.h"
#include "types/location.h"
#include "error.h"

bool executeWfillDirective(DirectiveType *this, Operand* firstOp, Operand *secondOp, Assembler *asmb) {
	long long times = firstOp->getValue(firstOp, asmb);
	long long value = secondOp->getValue(secondOp, asmb);

	if (asmb->LC->position == RightPosition) {
		reportError(ERROR_RIGHT_ALIGNED_WORD, asmb->fileLine);
	}

	// TODO: Figure out how to handle when label points to a memory position
	// that is on the right; use values higher than 2^40?
	for (int i = 0; i < times; i++) {
		// TODO: Move LC inside memoryMap since that's an easier place to
		// handle incrementing and that kind of stuff.
		asmb->memoryMap->addData(asmb->memoryMap, value, asmb->LC);

		asmb->LC->address++;
	}

	return true;
}