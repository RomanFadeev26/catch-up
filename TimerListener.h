#pragma once
#include <vector>
#include "Player.h"
#include "IListener.h"

class TimerListener :
    public IListener
{
    public:
        TimerListener() = default;
        TimerListener(const TimerListener&) = default;
        void addPlayer(Player* player);
        void update(const std::string& event, std::any& data) override {
            if (event == "TIME_UP") {
                updateScores();
                changeRoles();
            }
        }
    private:
        std::vector<Player*> players_;
        void changeRoles();
        void updateScores();
};

