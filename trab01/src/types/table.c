
#include <stdlib.h>
#include "types/table.h"
#include "types/private/table.h"

Table *createTable(int maxItems, CompareItemMethod compare) {
	Table *tab = malloc(sizeof(Table));

	tab->items       = malloc(sizeof(void*) * maxItems);
	tab->curItems    = 0;
	tab->maxItems    = maxItems;
	tab->compareItem = compare;

	tab->getItem     = getTableItem;
	tab->addItem     = addTableItem;

	return tab;
}

void *getTableItem(Table *this, const void *key) {
	for (int i = 0; i < this->curItems; i++) {
		if (this->compareItem(this->items[i], key)) {
			return this->items[i];
		}
	}

	return NULL;
}

bool addTableItem(Table *this, void *item) {
	if (this->curItems >= this->maxItems) {
		return false;
	}

	this->items[this->curItems++] = item;
	return true;
}