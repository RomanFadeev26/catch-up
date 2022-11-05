#pragma once

class IMoveable {
	public:
		struct Speed {
			int speedX_, speedY_;
		};
		virtual const Speed& getSpeed() const= 0;
		virtual void changeSpeedX(int speed) = 0;
		virtual void changeSpeedY(int speed) = 0;
		virtual ~IMoveable() = default;
};