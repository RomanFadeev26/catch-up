#include "SDL.h"
#include "FieldItem.h"

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
