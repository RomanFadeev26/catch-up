#pragma once
#include <string>
class Player
{
	public:
		enum class Roles {Victim, Hunter};
		Player(Roles role = Roles::Hunter, unsigned int score = 0, std::string name = ""):
			role_(role), score_(score), name_(name) {}
		Player(const Player&) = default;
		Player(Player&&) noexcept = default;

		const unsigned int score() const {
			return score_;
		}
		const Roles role() { return role_; }
		void increaseScore() {
			score_++;
		}
		void changeRole() {
			if (role_ == Roles::Hunter) {
				role_ = Roles::Victim;
			}
			else {
				role_ = Roles::Hunter;
			}
		}
	private:
		Roles role_ = Roles::Hunter;
		unsigned int score_ = 0;
		std::string name_ = "";
};

