#pragma once
#include <vector>
#include "Timer.h"
#include "Player.h"
#include "IListener.h"

class TimerListener :
    public IListener
{
    public:
        TimerListener() = default;
        TimerListener(const TimerListener&) = default;
        TimerListener(Timer* timer);
        void addPlayer(Player* player);
        void update(const std::string& event, std::any& data) override;
        void update(const std::string& event) override;
    private:
        std::vector<Player*> players_;
        Timer* timer_ = nullptr;
        void changeRoles();
        void updateScores();
};

