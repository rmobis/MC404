
#include <stdbool.h>
#include <stdlib.h>
#include "types/assembler.h"
#include "operandTypes/none.h"
#include "util.h"

bool validateNoneOpType(const char *token) {
	return token == NULL;
}

long long getNoneOpTypeValue(const char *token, Assembler *asmb) {
	return 0;
}