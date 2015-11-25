
#include <stdlib.h>
#include "types/position.h"
#include "types/location.h"
#include "types/private/location.h"

Location *createLocation(int addr, Position pos) {
	Location *loc = malloc(sizeof(Location));

	loc->address   = addr;
	loc->position  = pos;
	loc->increment = &incrementLocation;
	loc->free      = &freeLocation;

	return loc;
}

Location *cloneLocation(Location *orig) {
	return createLocation(orig->address, orig->position);
}

void incrementLocation(Location *loc) {
	if (loc->position == LeftPosition) {
		loc->position = RightPosition;
	} else {
		loc->position = LeftPosition;
		loc->address++;
	}
}

void freeLocation(Location *loc) {
	free(loc);
}