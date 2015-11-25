/**
 * Symbol Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

#define SYMBOL_MAX_LENGTH 64

struct Symbol {
	char name[SYMBOL_MAX_LENGTH];
	Operand *value;

	void(*free)(Symbol* this);
};

Symbol *createSymbol(char const *name, Operand *value);