#include "SDL.h"
#include "FieldItem.h"

FieldItem::FieldItem() {};

FieldItem::FieldItem(const FieldItem& other) {
	startDest_.x_ = other.startDest_.x_;
	startDest_.y_ = other.startDest_.y_;
	dest_.x_ = other.dest_.x_;
	dest_.y_ = other.dest_.y_;
	content_ = other.content_;
};

FieldItem::FieldItem(IMoveable* content, int x, int y) : content_(content) {
	dest_.x_ = x;
	dest_.y_ = y;
	startDest_.x_ = x;
	startDest_.y_ = y;
};

const FieldItem::Destination& FieldItem::getDestination() const { return dest_; }

IMoveable* FieldItem::getContent() const { return content_; }

void FieldItem::move(unsigned int windowWidth, unsigned int windowHeight) {
	int speedX = content_->getSpeed().speedX_;
	int speedY = content_->getSpeed().speedY_;
	if (dest_.x_ + speedX < windowWidth && dest_.x_ + speedX > 0) {
		dest_.x_ += speedX;
	}
	if (dest_.y_ + speedY < windowHeight && dest_.y_ + speedY > 0) {
		dest_.y_ += speedY;
	}
}

void FieldItem::resetDestination() {
	dest_.x_ = startDest_.x_;
	dest_.y_ = startDest_.y_;
};
