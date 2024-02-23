#pragma once
#include <vector>
#include <string>
#include <any>
#include "GameEventsObserver.h"
#include "Player.h"
#include "IListener.h"

class PlayerCatchedListener :
    public IListener
{
    public:
        PlayerCatchedListener() = default;
        PlayerCatchedListener(const PlayerCatchedListener&) = default;
        void addPlayer(Player* player);
        void update(const std::string& event, std::any& data) override;
        void update(const std::string& event) override;
    private:
        std::vector<Player*> players_;
        void changeRoles();
        void updateScores();
};

