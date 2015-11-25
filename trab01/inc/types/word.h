/**
 * Word Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdbool.h>
#include "types/wordType.h"
#include "types/typedefs.h"

#define INSTRUCTIONS_PER_WORD 2

struct Word {
	Instruction *instructions[INSTRUCTIONS_PER_WORD];
	long long data;
	WordType type;

	void(*free)(Word* this);
};

Word *createWord(WordType wordType);