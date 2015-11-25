

#include <stdbool.h>
#include <stdlib.h>

#include "types/word.h"
#include "types/wordType.h"
#include "types/private/word.h"
#include "types/instruction.h"


Word *createWord(WordType wordType) {
	Word *word = malloc(sizeof(Word));

	word->type = wordType;
	word->free = &freeWord;

	for (int i = 0; i < INSTRUCTIONS_PER_WORD; i++) {
		word->instructions[i] = NULL;
	}

	return word;
}

void freeWord(Word *this) {
	for (int i = 0; i < INSTRUCTIONS_PER_WORD; i++) {
		if (this->instructions[i] != NULL) {
			this->instructions[i]->free(this->instructions[i]);
		}
	}

	free(this);
}