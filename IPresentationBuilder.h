#pragma once
#include "SDL.h"

class IPresentationBuilder {
public:
	virtual void setSprite() = 0;
	virtual void setPosition() = 0;
	struct FieldItemPresentation {
		SDL_Surface* surface;
		SDL_Rect dist;
	};
	virtual FieldItemPresentation getResult() = 0;
	virtual ~IPresentationBuilder() = default;
};