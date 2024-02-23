#include "TimerListener.h"

TimerListener::TimerListener(Timer* timer) : timer_(timer) {};

void TimerListener::update(const std::string& event, std::any& data) {};

void TimerListener::update(const std::string& event) {
	if (event == "TIME_UP") {
		updateScores();
		changeRoles();
		timer_->resetTimer();
	}
	if (event == "PLAYER_CATCHED") {
		timer_->resetTimer();
	}
};

void TimerListener::addPlayer(Player* player) {
	players_.push_back(player);
};

void TimerListener::changeRoles() {
	for (auto& i : players_) {
		i->changeRole();
	}
};

void TimerListener::updateScores() {
	for (auto& i : players_) {
		if (i->role() == Player::Roles::Victim) {
			i->increaseScore();
		}
	}
};
