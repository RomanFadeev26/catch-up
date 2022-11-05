#include "PlayerCatchedListener.h"

void PlayerCatchedListener::addPlayer(Player* player) {
	players_.push_back(player);
}

void PlayerCatchedListener::changeRoles() {
	for (auto& i : players_) {
		i->changeRole();
	}
}

void PlayerCatchedListener::updateScores() {
	for (auto& i : players_) {
		if (i->role() == Player::Roles::Hunter) {
			i->increaseScore();
		}
	}
}