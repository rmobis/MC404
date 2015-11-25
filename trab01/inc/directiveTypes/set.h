/**
 * .set Directive API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

bool executeSetDirective(DirectiveType *this, Operand* firstOp, Operand *secondOp, Assembler *asmb);