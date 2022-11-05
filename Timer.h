#pragma once
#include "IObserver.h"
#include "SDL.h"

class Timer {
	public:
		Timer() = default;
		Timer(const Timer&) = default;
		Timer(Timer&&) = default;
		Timer(IObserver* timerObserver): timerObserver_(timerObserver) {}
		Timer& operator=(Timer&&) noexcept = default;
		void setObserver(IObserver* observer) {
			timerObserver_ = observer;
		}
		void alarm() {
			static constexpr Uint8 ONE_ROUND = 60;
			if (getSeconds() >= ONE_ROUND) {
				timerObserver_->notify("PLAYER_CATCHED");
				resetTime();
			}
		}
		
	private:
		Uint32 timer_ = 0;
		IObserver* timerObserver_ = nullptr;
		const Uint32 getTime() {
			return SDL_GetTicks() - timer_;
		}
		void resetTime() {
			timer_ = SDL_GetTicks();
		}
		unsigned int getSeconds() {
			return getTime() / 1000;
		}
};

