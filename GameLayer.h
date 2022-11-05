#pragma once
#include <vector>
#include <list>
#include "SDL.h"
#include "SDL_image.h"
#include "ILayer.h"
#include "IPresentationBuilder.h"
#include "IObserver.h"

class GameLayer: public ILayer {
	public:
		GameLayer(IObserver* intersectionsObserver, std::vector<IPresentationBuilder::FieldItemPresentation>& presentations, SDL_Renderer* renderer):
			intersectionsObserver_(intersectionsObserver), presentations_(presentations), renderer_(renderer){}
		GameLayer() = default;
		GameLayer(const GameLayer&) = default;
		~GameLayer() override {
			SDL_FreeSurface(background_);
		}

		void renderItems() const override;
		
	private:
		SDL_Renderer* renderer_ = nullptr;
		SDL_Surface* background_ = IMG_Load("sprites/background.png");
		std::vector<IPresentationBuilder::FieldItemPresentation> presentations_;
		IObserver* intersectionsObserver_;
		bool playersHasIntersections() const;
		void searchIntersections() const;
};

