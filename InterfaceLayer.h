#pragma once
#include <string>
#include "SDL_ttf.h"
#include "ILayer.h"
#include "Timer.h"
#include "Player.h"
#include "SDL.h"
#include "RenderEngine.h"

class InterfaceLayer : public ILayer {
	public:
		InterfaceLayer() = default;
		InterfaceLayer(const InterfaceLayer&) = default;
		InterfaceLayer(Player* player1, Player* player2, Timer* timer);
		~InterfaceLayer() override;
		void renderItems() const override;
	private:
		Player* player1_ = nullptr;
		Player* player2_ = nullptr;
		RenderEngine* renderEngine_ = RenderEngine::getInstance();
		Timer* timer_ = nullptr;
		TTF_Font* font_ = nullptr;
		SDL_Color color_ = { 255, 165, 0 };

};

