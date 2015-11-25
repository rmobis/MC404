#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "util.h"

char *nextToken() {
	return strtok(NULL, SPACE_CHARACTERS);
}

bool isSymbol(const char *token) {
	// Symbols MUST NOT be null
	if (token == NULL) {
		return false;
	}

	int tokenLength = strlen(token);

	// Symbols MUST NOT exceed its maximum length
	if (tokenLength > SYMBOL_MAX_LENGTH) {
		return false;
	}

	// Symbols MUST NOT start with any digit
	if (isdigit(token[0])) {
		return false;
	}

	// Symbols MUST be alphanumeric plus underscore
	if (!isAlphanumeric_(token)) {
		return false;
	}

	return true;
}

bool isLabel(const char *token) {
	// Labels MUST NOT be null
	if (token == NULL) {
		return false;
	}

	int tokenLength = strlen(token);

	// Labels MUST end with a specific character
	if (token[tokenLength - 1] != LABEL_ENDING_CHAR) {
		return false;
	}

	bool r = true;
	char *newToken = malloc(sizeof(char) * tokenLength);

	strncpy(newToken, token, tokenLength - 1);
	newToken[tokenLength - 1] = '\0';

	// Labels MUST follow all rules followed by symbols
	if (!isSymbol(newToken)) {
		r = false;
	}

	free(newToken);

	return r;
}

bool isDirective(const char *token) {
	// Directives MUST NOT be null
	if (token == NULL) {
		return false;
	}


	// Directives MUST be one of the known directives
	for (int i = 0; knownDirectives[i] != NULL; i++) {
		if (strcmp(token, knownDirectives[i]) == 0) {
			return true;
		}
	}

	return false;
}

bool isInstruction(const char *token) {
	// Instructions MUST NOT be null
	if (token == NULL) {
		return false;
	}

	// Instructions MUST be one of the known directives
	for (int i = 0; knownMnemonics[i] != NULL; i++) {
		if (strcmp(token, knownMnemonics[i]) == 0) {
			return true;
		}
	}

	return false;
}

bool isComment(const char *token) {
	// Comments MUST NOT be null
	if (token == NULL) {
		return false;
	}

	// Comments MUST start with a specific character
	return token[0] == COMMENT_CHAR;
}

bool isNumeric(const char *str) {
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (!isdigit(str[i])) {
			return false;
		}
	}

	return true;
}

bool isHexadecimal(const char *str) {
	// Optionaly start with '0x'
	if (strstr(str, "0x") == str) {
		str += 2;
	}

	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (!isxdigit(str[i])) {
			return false;
		}
	}

	return true;
}

bool isAlphabetic(const char *str) {
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (!isalpha(str[i])) {
			return false;
		}
	}

	return true;
}

bool isAlphanumeric(const char *str) {
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (!isalnum(str[i])) {
			return false;
		}
	}

	return true;
}

bool isAlphanumeric_(const char *str) {
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (!isalnum(str[i]) && str[i] != '_') {
			return false;
		}
	}

	return true;
}