#include "Timer.h"

Timer::Timer(IObserver* timerObserver) : timerObserver_(timerObserver) {};

void Timer::setObserver(IObserver* observer) {
	timerObserver_ = observer;
};

void Timer::alarm() {
	static constexpr Uint8 ONE_ROUND = 30;
	if (getCurrentSeconds() >= ONE_ROUND) {
		timerObserver_->notify("TIME_UP");
	}
};

const int Timer::getCurrentSeconds() const {
	return getTime() / 1000;
};

void Timer::resetTimer() {
	timer_ = SDL_GetTicks();
};

const Uint32 Timer::getTime() const {
	return SDL_GetTicks() - timer_;
};
