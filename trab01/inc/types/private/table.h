/**
 * Table Structure Private API
 * Author: Raphael Mobis (r.mobis@gmail.com)
 */

#pragma once

#include "types/typedefs.h"

void *getTableItem(Table *this, const void *key);

bool addTableItem(Table *this, void *item);