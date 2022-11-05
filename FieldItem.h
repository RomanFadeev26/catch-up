#pragma once

#include "SDL.h"
#include <string>
#include "IMoveable.h"

class FieldItem
{	public:
		FieldItem() {};
		FieldItem(const FieldItem& other) {
			startDest_.x_ = other.startDest_.x_;
			startDest_.y_ = other.startDest_.y_;
			dest_.x_ = other.dest_.x_;
			dest_.y_ = other.dest_.y_;
			content_ = other.content_;
		};
		FieldItem(FieldItem&&) = default;
		FieldItem& operator=(const FieldItem&) = default;
		FieldItem(IMoveable* content, int x, int y) : content_(content) {
			dest_.x_ = x;
			dest_.y_ = y;
			startDest_.x_ = x;
			startDest_.y_ = y;
		};
		struct Destination {
			int x_, y_;
		};

		const Destination& getDestination() const { return dest_; }
		IMoveable* getContent() const { return content_; }

		void move(unsigned int windowWidth, unsigned int windowHeight);
		void resetDestination();
	private:
		Destination startDest_{ 0, 0 };
		IMoveable* content_ = nullptr;
		Destination dest_{0, 0};
};
