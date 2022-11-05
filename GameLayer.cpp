#include "GameLayer.h"

void GameLayer::searchIntersections() const {
	if (playersHasIntersections()) {
		intersectionsObserver_->notify("PLAYER_CATCHED");
	}
}

void GameLayer::renderItems() const {
	searchIntersections();
	SDL_RenderClear(renderer_);
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);

	SDL_Texture* bgTexture = SDL_CreateTextureFromSurface(renderer_, background_);
	SDL_RenderCopy(renderer_, bgTexture, nullptr, nullptr);
	SDL_DestroyTexture(bgTexture);

	for (auto& i : presentations_) {
		SDL_Texture* temp = SDL_CreateTextureFromSurface(renderer_, i.surface);
		SDL_RenderCopy(renderer_, temp, nullptr, &(i.dist));

		// todo возможно я тут слишком рано уничтожаю текстуры - на случай, если оно посыпется непонятно как
		SDL_DestroyTexture(temp);
	}
	SDL_RenderPresent(renderer_);
}

bool GameLayer::playersHasIntersections() const {
	return SDL_HasIntersection(&(presentations_[0].dist), &(presentations_[1].dist));
}