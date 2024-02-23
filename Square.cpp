#include "Square.h"

Square::Square(SquareColor color, int speed) : color_(color) {};

Square::Square(const Square& other) {
	speed_.speedX_ = other.speed_.speedX_;
	speed_.speedY_ = other.speed_.speedY_;
	color_ = other.color_;
};

const Square::SquareColor Square::getColor() const { return color_; };

void Square::changeColor() {
	if (color_ == SquareColor::RED) {
		color_ = SquareColor::BLACK;
	}
	else {
		color_ = SquareColor::RED;
	}
};

void Square::changeSpeedX(int speed) {
	speed_.speedX_ = speed;
};

void Square::changeSpeedY(int speed) {
	speed_.speedY_ = speed;
};

const Square::Speed& Square::getSpeed() const {
	return speed_;
};