/**
* Operand Type Structure API
* Author: Raphael Mobis (r.mobis@gmail.com)
*/

#pragma once

#include <stdbool.h>
#include "types/typedefs.h"

struct OperandType {
	bool (*validate)(char const*);
	long long (*getValue)(char const*, Assembler*);

	void (*free)(OperandType*);
};

OperandType *createOperandType(bool(*validate)(char const*), long long(*getValue)(char const*, Assembler*));