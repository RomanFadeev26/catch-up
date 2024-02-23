#include "GameEventsObserver.h"

void GameEventsObserver::subscribe(IListener* subscriber) {
	subscribers_.push_back(subscriber);
}

void GameEventsObserver::unsubscribe(IListener * subscriber) {
	for (std::vector<IListener*>::iterator i = subscribers_.begin(); i != subscribers_.end(); i++) {
		if ((*i) == subscriber) {
			subscribers_.erase(i);
		}
	}
}

void GameEventsObserver::notify(const std::string& event) const {
	for (auto i : subscribers_) {
		i->update(event);
	}
}

void GameEventsObserver::notify(const std::string& event, std::any& data) const {
	for (auto i : subscribers_) {
		i->update(event, data);
	}
}
