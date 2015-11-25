/**
 * Operand Structure Private API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

long long getOperandValue(Operand* this, Assembler *asm);

/**
 * Frees an operand instance.
 *
 * @param	this	The operand to be freed.
 */
void freeOperand(Operand *this);