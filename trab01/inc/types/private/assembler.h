/**
 * Assembler Structure Private API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"
#include "types/table.h"

/**
 * Frees an assembler instance.
 *
 * @param	this	The assembler to be freed.
 */
void freeAssembler(Assembler *this);

void parse(Assembler *this);

void parseLine(Assembler *this, char* line);

void handleLabel(Assembler *this, char *token);

void handleDirective(Assembler *this, char *token);

void handleInstruction(Assembler *this, char *token);

bool compareLabel(const Label *item, const char *key);

bool compareSymbol(const Symbol *item, const char *key);

CompareItemMethod compareDirectiveType(const DirectiveType *item, const char *key);

CompareItemMethod compareOperandType(const OperandType *item, const char *key);