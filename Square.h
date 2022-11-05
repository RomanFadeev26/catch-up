#pragma once
#include <string>
#include "SDL.h"
#include "IMoveable.h"

class Square : public IMoveable {
	public:
		enum class SquareColor {RED, BLACK};
		Square(SquareColor color = SquareColor::RED, int speed = 0) : color_(color) {}
		Square(const Square& other) {
			speed_.speedX_ = other.speed_.speedX_;
			speed_.speedY_ = other.speed_.speedY_;
			color_ = other.color_;
		}
		const SquareColor getColor() const { return color_; }
		void changeColor() {
			if (color_ == SquareColor::RED) {
				color_ = SquareColor::BLACK;
			}
			else {
				color_ = SquareColor::RED;
			}
		}
		void changeSpeedX(int speed) override {
			speed_.speedX_ = speed;
		}
		void changeSpeedY(int speed) override {
			speed_.speedY_ = speed;
		}
		const Speed& getSpeed() const override {
			return speed_;
		}
	private:
		Speed speed_ {0, 0};
		SquareColor color_;
};

