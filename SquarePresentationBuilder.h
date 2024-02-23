#pragma once
#include "SDL.h"
#include "IPresentationBuilder.h"
#include "FieldItem.h"
#include "SDL_image.h"
#include "Square.h"

class SquarePresentationBuilder: public IPresentationBuilder {
	public:
		SquarePresentationBuilder(SquarePresentationBuilder&&) = default;
		SquarePresentationBuilder();
		SquarePresentationBuilder(FieldItem* fieldItem);

		~SquarePresentationBuilder() override;

		void changeFieldItem(FieldItem* fieldItem);

		void setSprite() override;

		void setPosition() override;

		FieldItemPresentation getResult() override;
	private:
		FieldItem* fieldItem_ = nullptr;
		SDL_Surface* redSurface_ = IMG_Load("sprites/white_slime.png");
		SDL_Surface* blackSurface_ = IMG_Load("sprites/purple_slime.png");
		SDL_Surface* surface_ = nullptr;
		SDL_Rect dist_{ 0, 0, 0, 0 };
		int frame_ = 0;
};

