#include "TimerListener.h"

void TimerListener::addPlayer(Player* player) {
	players_.push_back(player);
}

void TimerListener::changeRoles() {
	for (auto& i : players_) {
		i->changeRole();
	}
}

void TimerListener::updateScores() {
	for (auto& i : players_) {
		if (i->role() == Player::Roles::Victim) {
			i->increaseScore();
		}
	}
}