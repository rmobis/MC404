
#include <stdbool.h>
#include <stdlib.h>
#include "types/assembler.h"
#include "operandTypes/dec0_232.h"
#include "util.h"

bool validateDec0_232OpType(const char *token) {
	if (!isNumeric(token)) {
		return false;
	}

	long long v = strtoll(token, NULL, 10);

	return v >= 1LL && v <= 4294967295LL;
}

long long getDec0_232OpTypeValue(const char *token, Assembler *asmb) {
	return strtoll(token, NULL, 10);
}