
#include <stdbool.h>
#include <stdlib.h>
#include "types/assembler.h"
#include "operandTypes/decN231_231.h"
#include "util.h"

bool validateDecN231_231OpType(const char *token) {
	if (!isNumeric(token)) {
		return false;
	}

	long long v = strtoll(token, NULL, 10);

	return v >= -2147483648LL && v <= 2147483647LL;
}

long long getDecN231_231OpTypeValue(const char *token, Assembler *asmb) {
	return strtoll(token, NULL, 10);
}