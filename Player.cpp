#include "Player.h"

Player::Player(Roles role, unsigned int score, std::string name) :
	role_(role), score_(score), name_(name) {};


const unsigned int Player::score() const {
	return score_;
};

const Player::Roles Player::role() const { return role_; };

void Player::increaseScore() {
	score_++;
};

void Player::changeRole() {
	if (role_ == Roles::Hunter) {
		role_ = Roles::Victim;
	}
	else {
		role_ = Roles::Hunter;
	}
};
