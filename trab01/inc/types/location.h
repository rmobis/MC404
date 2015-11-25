/**
 * Location Structure API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdlib.h>
#include "types/typedefs.h"
#include "types/position.h"

struct Location {
	int address;
	Position position;

	void (*increment)(Location*);
	void (*free)(Location*);
};

Location *createLocation(int addr, Position pos);
Location *cloneLocation(Location *orig);