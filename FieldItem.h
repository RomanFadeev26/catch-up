#pragma once

#include "SDL.h"
#include <string>
#include "IMoveable.h"

class FieldItem
{	public:
		FieldItem();
		FieldItem(const FieldItem& other);
		FieldItem(FieldItem&&) = default;
		FieldItem& operator=(const FieldItem&) = default;
		FieldItem(IMoveable* content, int x, int y);

		struct Destination {
			int x_, y_;
		};

		const Destination& getDestination() const;
		IMoveable* getContent() const;

		void move(unsigned int windowWidth, unsigned int windowHeight);
		void resetDestination();
	private:
		Destination startDest_{ 0, 0 };
		IMoveable* content_ = nullptr;
		Destination dest_{0, 0};
};
