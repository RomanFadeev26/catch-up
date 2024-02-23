#pragma once
#include <vector>
#include <list>
#include "SDL.h"
#include "SDL_image.h"
#include "ILayer.h"
#include "IPresentationBuilder.h"
#include "IObserver.h"
#include "RenderEngine.h"

class GameLayer: public ILayer {
	public:
		GameLayer(IObserver* intersectionsObserver, std::vector<IPresentationBuilder::FieldItemPresentation>& presentations);
		GameLayer() = default;
		GameLayer(const GameLayer&) = default;
		~GameLayer() override;
		void renderItems() const override;
		
	private:
		RenderEngine* renderEngine_ = RenderEngine::getInstance();
		SDL_Surface* background_ = IMG_Load("sprites/background.png");
		std::vector<IPresentationBuilder::FieldItemPresentation> presentations_;
		IObserver* intersectionsObserver_;
		bool playersHasIntersections() const;
		void searchIntersections() const;
};

