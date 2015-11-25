
#include <stdbool.h>
#include <stdlib.h>
#include "types/assembler.h"
#include "operandTypes/hex.h"
#include "util.h"

bool validateHexOpType(const char *token) {
	if (!isHexadecimal(token)) {
		return false;
	}

	long long v = strtoll(token, NULL, 16);

	// Even though hex values actually go from -2^39 to (2^39 - 1), since we're
	// considering a 64 bits data type, the representation gets slightly
	// different.
	return v >= 0 && v <= 1099511627775LL;
}

long long getHexOpTypeValue(const char *token, Assembler *asmb) {
	return strtoll(token, NULL, 10);
}