/**
 * Memory Map Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdbool.h>
#include "types/typedefs.h"

struct MemoryMap {
	Word **words;
	int maxWords;

	bool (*isFilled)(MemoryMap*, Location*, WordType);
	void (*addInstruction)(MemoryMap*, Instruction*, Location*);
	void (*addData)(MemoryMap *, long long, Location*);

	void (*free)(MemoryMap *);
};

MemoryMap *createMemoryMap(int maxWords);