

#include <stdlib.h>
#include <string.h>

#include "types/symbol.h"
#include "types/operand.h"
#include "types/private/symbol.h"


Symbol *createSymbol(char const *name, Operand *value) {
	Symbol *sym = malloc(sizeof(Symbol));

	strcpy(sym->name, name);

	sym->value = value;
	sym->free  = &freeSymbol;

	return sym;
}

void freeSymbol(Symbol *this) {
	this->value->free(this->value);

	free(this);
}