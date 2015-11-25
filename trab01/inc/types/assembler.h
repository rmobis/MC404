/**
 * IAS Assembler API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdio.h>

#include "types/typedefs.h"


#define LABEL_TABLE_SIZE  1038
#define SYMBOL_TABLE_SIZE 461
#define MEMORY_MAP_SIZE   1024




#define COMMENT_SYMBOL '#'
#define SPACE_CHARACTERS " \t\n"


#define LABEL_MAX_LENGTH 64
#define LABEL_ENDING_SYMBOL ':'

#define DIRECTIVE_MAX_LENGTH 64
#define DIRECTIVE_STARTING_SYMBOL '.'

#define MAX_SYMBOL_LENGTH 64
#define MAX_INPUT_FILE_LENGTH 4096
#define MAX_LINE_LENGTH MAX_INPUT_FILE_LENGTH
#define MAX_TOKEN_LENGTH MAX_LINE_LENGTH

struct Assembler {
	Location *LC;
	FILE *sourceFile;
	int fileLine;

	Table *labelTable;
	Table *symbolTable;
	Table *operandTypeTable;
	Table *directiveTypeTable;
	Table *instructionTypeTable;
	MemoryMap *memoryMap;

	void (*parse)(Assembler*);
	void (*parseLine)(Assembler*, char*);
	void (*handleLabel)(Assembler*, char*);
	void (*handleDirective)(Assembler*, char*);
	void (*handleInstruction)(Assembler*, char*);
	void (*free)(Assembler*);
};

Assembler *createAssembler(FILE *sourceFile, int maxLabels, int maxSymbols);



int parseCode(FILE *f);