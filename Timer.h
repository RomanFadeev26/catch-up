#pragma once
#include "IObserver.h"
#include "SDL.h"

class Timer {
	public:
		Timer() = default;
		Timer(const Timer&) = default;
		Timer(Timer&&) = default;
		Timer(IObserver* timerObserver);
		Timer& operator=(Timer&&) noexcept = default;
		void setObserver(IObserver* observer);
		void alarm();

		const int getCurrentSeconds() const;

		void resetTimer();
		
	private:
		Uint32 timer_ = 0;
		IObserver* timerObserver_ = nullptr;
		const Uint32 getTime() const;
};

