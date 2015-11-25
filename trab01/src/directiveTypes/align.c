
#include "types/assembler.h"
#include "types/operand.h"
#include "types/directiveType.h"
#include "directiveTypes/align.h"
#include "types/position.h"
#include "types/location.h"

bool executeAlignDirective(DirectiveType *this, Operand* firstOp, Operand *secondOp, Assembler *asmb) {
	long long mul = firstOp->getValue(firstOp, asmb);

	if (asmb->LC->position == RightPosition) {
		asmb->LC->increment(asmb->LC);
	}

	if (asmb->LC->address % mul != 0) {
		asmb->LC->address = asmb->LC->address + (mul - (asmb->LC->address % mul));
	}

	return true;
}