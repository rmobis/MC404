/**
 * Label Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

#define LABEL_MAX_LENGTH 64

struct Label {
	char name[LABEL_MAX_LENGTH];
	Location *location;

	void (*free)(Label *);
};

Label *createLabel(char *token, Location *loc);