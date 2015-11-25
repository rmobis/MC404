/**
 * Memory Map Structure Private API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

bool isMemoryMapFilled(MemoryMap *this, Location *loc, WordType type);

void addMemoryMapInstruction(MemoryMap *this, Instruction *instr, Location *loc);

void addMemoryMapData(MemoryMap *this, long long data, Location *loc);

/**
 * Frees a memory map instance.
 *
 * @param	this	The memory map to be freed.
 */
void freeMemoryMap(MemoryMap *this);