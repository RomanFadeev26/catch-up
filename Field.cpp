#include "Field.h"

Field::Field(const Field& field) {
	items_ = field.items_;
}

void Field::addItem(FieldItem* item) {
	items_.push_back(item);
}

void Field::removeItem(unsigned int index) {
	items_.erase(items_.begin() + index);
}

std::vector<FieldItem*>& Field::getItems() {
	return items_;
}