/**
 * Instruction Type Structure Private API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"


void getInstructionTypeRepresentation(InstructionType *this, Instruction *instr, Assembler *asmb, char buffer[5]);

/**
 * Frees a instruction type instance.
 *
 * @param	this	The instruction type to be freed.
 */
void freeInstructionType(InstructionType *this);