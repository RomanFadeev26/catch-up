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
		void subscribe(IListener* subscriber) override {
			subscribers_.push_back(subscriber);
		}
		void unsubscribe(IListener* subscriber) override {
			for (std::vector<IListener*>::iterator i = subscribers_.begin(); i != subscribers_.end(); i++) {
				if ((*i) == subscriber) {
					subscribers_.erase(i);
				}
			}
		}
		void notify(const std::string& event) const override {
			for (auto i : subscribers_) {
				i->update(event);
			}
		}
		void notify(const std::string& event, std::any& data) const override {
			for (auto i : subscribers_) {
				i->update(event, data);
			}
		}
	private:
		std::vector<IListener*> subscribers_;
};

