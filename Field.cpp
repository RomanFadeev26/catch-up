#include "Field.h"

void Field::addItem(FieldItem* item) {
	items_.push_back(item);
}

void Field::removeItem(unsigned int index) {
	items_.erase(items_.begin() + index);
}