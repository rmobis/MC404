/**
 * Location Structure Private API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

void incrementLocation(Location *this);

/**
 * Frees a location instance.
 *
 * @param	this	The location to be freed.
 */
void freeLocation(Location *this);