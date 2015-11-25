/**
 * Error Reporting API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"


void reportError(int errorCode, int line) {
	if (errorCode & ERROR_SYNTAX) {
		fprintf(stderr, "ERROR on line %d\n", line);
	}

	fprintf(stderr, "%s\n", getErrorMessage(errorCode));

#ifdef _DEBUG
	getchar();
#endif

	exit(-1);
}

char const *getErrorMessage(int errorCode) {
	switch (errorCode) {
		case ERROR_INVALID_ARGS:
			return ERROR_MSG_INVALID_ARGS;

		case ERROR_READ_FILE:
			return ERROR_MSG_READ_FILE;

		default:
			return ERROR_MSG_UNKNOWN;
	}
}