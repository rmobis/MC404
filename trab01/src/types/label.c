
#include <string.h>
#include <stdlib.h>
#include "types/label.h"
#include "types/private/label.h"
#include "types/location.h"

typedef struct Label Label;

Label *createLabel(char *token, Location *loc) {
	Label *lab = malloc(sizeof(Label));

	strcpy(lab->name, token);

	lab->location = loc;
	lab->free  = &freeLabel;

	return lab;
}

void freeLabel(Label *lab) {
	lab->location->free(lab->location);
	free(lab);
}