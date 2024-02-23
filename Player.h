#pragma once
#include <string>
class Player
{
	public:
		enum class Roles {Victim, Hunter};
		Player(Roles role = Roles::Hunter, unsigned int score = 0, std::string name = "");
		Player(const Player&) = default;
		Player(Player&&) noexcept = default;

		const unsigned int score() const;
		const Roles role() const;
		void increaseScore();
		void changeRole();
	private:
		Roles role_ = Roles::Hunter;
		unsigned int score_ = 0;
		std::string name_ = "";
};

