
#include <stdbool.h>
#include <stdlib.h>
#include "types/assembler.h"
#include "operandTypes/dec1_1023.h"
#include "util.h"

bool validateDec1_1023OpType(const char *token) {
	if (!isNumeric(token)) {
		return false;
	}

	long long v = strtoll(token, NULL, 10);

	return v >= 1LL && v <= 1023LL;
}

long long getDec1_1023OpTypeValue(const char *token, Assembler *asmb) {
	return strtoll(token, NULL, 10);
}