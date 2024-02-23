#include "GameLayer.h"

GameLayer::GameLayer(IObserver* intersectionsObserver, std::vector<IPresentationBuilder::FieldItemPresentation>& presentations) :
	intersectionsObserver_(intersectionsObserver), presentations_(presentations) {}

GameLayer::~GameLayer() {
	SDL_FreeSurface(background_);
};

void GameLayer::searchIntersections() const {
	if (playersHasIntersections()) {
		intersectionsObserver_->notify("PLAYER_CATCHED");
	}
}

void GameLayer::renderItems() const {
	searchIntersections();
	
	renderEngine_->setColor({ 0, 0, 0, 0 });
	IPresentationBuilder::FieldItemPresentation bgPresentation{ background_, { 0, 0, RenderEngine::DEFAULT_WINDOW_WIDTH, RenderEngine::DEFAULT_WINDOW_HEIGHT } };
	renderEngine_->addSprite(bgPresentation);

	for (auto& i : presentations_) {
		renderEngine_->addAnimation(i, 13);
	}
}

bool GameLayer::playersHasIntersections() const {
	return SDL_HasIntersection(&(presentations_[0].dist), &(presentations_[1].dist));
}