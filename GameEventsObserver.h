#pragma once
#include <vector>
#include <string>
#include <any>
#include "IListener.h"
#include "IObserver.h"


class GameEventsObserver: public IObserver {
	public:
		GameEventsObserver() = default;
		GameEventsObserver(GameEventsObserver&&) noexcept = default;
		void subscribe(IListener* subscriber) override;
		void unsubscribe(IListener* subscriber) override;
		void notify(const std::string& event) const override;
		void notify(const std::string& event, std::any& data) const override;
	private:
		std::vector<IListener*> subscribers_;
};

