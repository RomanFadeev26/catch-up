#pragma once
#include "ILayer.h"
#include "Timer.h"
#include "Player.h"
#include "SDL.h"

class InterfaceLayer : public ILayer {
	public:
		InterfaceLayer() = default;
		InterfaceLayer(const InterfaceLayer&) = default;
		void renderItems() const override;
	private:
		Player* player1_ = nullptr;
		Player* player2_ = nullptr;
		SDL_Renderer* renderer_ = nullptr;
};

