
#include <stdbool.h>
#include <stdlib.h>
#include "types/assembler.h"
#include "operandTypes/dec0_231.h"
#include "util.h"

bool validateDec0_231OpType(const char *token) {
	if (!isNumeric(token)) {
		return false;
	}

	long long v = strtoll(token, NULL, 10);

	return v >= 1LL && v <= 2147483647LL;
}

long long getDec0_231OpTypeValue(const char *token, Assembler *asmb) {
	return strtoll(token, NULL, 10);
}