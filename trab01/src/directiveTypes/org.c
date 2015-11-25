
#include "types/assembler.h"
#include "types/operand.h"
#include "types/directiveType.h"
#include "directiveTypes/org.h"
#include "types/position.h"
#include "types/location.h"

bool executeOrgDirective(DirectiveType *this, Operand* firstOp, Operand *secondOp, Assembler *asmb) {
	long long address = firstOp->getValue(firstOp, asmb);

	asmb->LC->address = address;
	asmb->LC->position = LeftPosition;
}