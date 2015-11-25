/**
 * Table Structure Public API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include <stdbool.h>
#include "types/typedefs.h"

typedef bool (*CompareItemMethod)(const void *, const void *);

struct Table {
	void **items;
	int curItems;
	int maxItems;
	CompareItemMethod compareItem;

	void *(*getItem)(Table *this, const void *);
	bool (*addItem)(Table *this, void *);
};

Table *createTable(int maxItems, CompareItemMethod compare);