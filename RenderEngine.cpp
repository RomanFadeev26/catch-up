#include "RenderEngine.h"

RenderEngine::RenderEngine() {
	renderer_ = SDL_CreateRenderer(window_.getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
};

RenderEngine* RenderEngine::instance_ = nullptr;

RenderEngine* RenderEngine::getInstance() {
	if (instance_ == nullptr) {
		instance_ = new RenderEngine();
	}
	return instance_;
}

RenderEngine::~RenderEngine() {
	if (renderer_) {
		SDL_DestroyRenderer(renderer_);
	}
};

void RenderEngine::destroyInstance() {
	if (instance_) {
		delete instance_;
	}
}

void RenderEngine::addAnimation(IPresentationBuilder::FieldItemPresentation presentation, int fps) {
	animations_.push_back({ presentation, { 0, 0, presentation.surface->w, 32 }, 0, fps});
};

void RenderEngine::setColor(SDL_Color color) {
	SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
};

void RenderEngine::addSprite(IPresentationBuilder::FieldItemPresentation presentation) {
	sprites_.push_back(presentation);
};

void RenderEngine::renderSprites() const {
	for (const auto& sprite : sprites_) {
		SDL_Texture* temp = SDL_CreateTextureFromSurface(renderer_, sprite.surface);
		SDL_RenderCopy(renderer_, temp, nullptr, &(sprite.dist));
		SDL_DestroyTexture(temp);
	}
};

void RenderEngine::renderAnimations() {
	currentFrame_++;
 	currentFrame_ = currentFrame_ % 26;
	for (auto& animation : animations_) {
		animation.frame_ = currentFrame_ % animation.fps_;
		animation.src_.y = animation.frame_ * animation.src_.h;
		SDL_Texture* temp = SDL_CreateTextureFromSurface(renderer_, animation.presentation_.surface);
		SDL_RenderCopy(renderer_, temp, &(animation.src_), &(animation.presentation_.dist));
		SDL_DestroyTexture(temp);
	}
};

void RenderEngine::render() {
	renderSprites();
	renderAnimations();
	SDL_RenderPresent(renderer_);
	sprites_.clear();
	animations_.clear();
};

SDL_Renderer* RenderEngine::getRenderer() const {
	return renderer_;
};

const Window& RenderEngine::getWindow() const {
	return window_;
}