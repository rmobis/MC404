

#include <stdbool.h>
#include <stdlib.h>

#include "types/word.h"
#include "types/instruction.h"
#include "types/location.h"
#include "types/wordType.h"
#include "types/memoryMap.h"
#include "types/private/memoryMap.h"


MemoryMap *createMemoryMap(int maxWords) {
	MemoryMap *map = malloc(sizeof(MemoryMap));

	map->words          = malloc(maxWords * sizeof(Word*));
	map->maxWords       = maxWords;

	map->isFilled       = isMemoryMapFilled;
	map->addInstruction = addMemoryMapInstruction;
	map->addData        = addMemoryMapData;
	map->free           = freeMemoryMap;

	return map;
}

bool isMemoryMapFilled(MemoryMap *this, Location *loc, WordType type) {
	Word *word = this->words[loc->address];

	if (word == NULL) {
		return false;
	}

	if (type == DataWord || type != word->type) {
		return true;
	}

	if (word->instructions[loc->address] != NULL) {
		return true;
	}

	return false;
}

void addMemoryMapInstruction(MemoryMap *this, Instruction *instr, Location *loc) {
	Word *word = this->words[loc->address];

	if (word == NULL) {
		word = createWord(InstructionWord);
		this->words[loc->address] = word;
	}

	word->instructions[loc->position] = instr;
}

void addMemoryMapData(MemoryMap *this, long long data, Location *loc) {
	Word *word = this->words[loc->address];

	if (word == NULL) {
		word = createWord(DataWord);
		this->words[loc->address] = word;
	}

	word->data = data;
}

void freeMemoryMap(MemoryMap *this) {
	for (int i = 0; i < this->maxWords; i++) {
		if (this->words[i] != NULL) {
			this->words[i]->free(this->words[i]);
		}
	}

	free(this->words);
	free(this);
}