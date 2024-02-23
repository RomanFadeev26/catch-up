#pragma once
#include <string>
#include "SDL.h"
#include "IMoveable.h"

class Square : public IMoveable {
	public:
		enum class SquareColor {RED, BLACK};
		Square(SquareColor color = SquareColor::RED, int speed = 0);
		Square(const Square& other);
		const SquareColor getColor() const;
		void changeColor();
		void changeSpeedX(int speed) override;
		void changeSpeedY(int speed) override;
		const Speed& getSpeed() const override;
	private:
		Speed speed_ {0, 0};
		SquareColor color_;
};

