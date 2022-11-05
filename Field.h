#pragma once
#include <vector>
#include "FieldItem.h"

class Field {
	public:
		Field() {}
		Field(const Field& field) {
			items_ = field.items_;
		}
		Field(Field&&) noexcept = default;
		void addItem(FieldItem* item);
		void removeItem(unsigned int index);
		std::vector<FieldItem*>& getItems() {
			return items_;
		}
	private:
		std::vector<FieldItem*> items_;
};

