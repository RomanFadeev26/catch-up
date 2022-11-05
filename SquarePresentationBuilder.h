#pragma once
#include "SDL.h"
#include "IPresentationBuilder.h"
#include "FieldItem.h"
#include "SDL_image.h"
#include "Square.h"

class SquarePresentationBuilder: public IPresentationBuilder {
	public:
		SquarePresentationBuilder(SquarePresentationBuilder&&) = default;
		SquarePresentationBuilder() {};
		SquarePresentationBuilder(FieldItem* fieldItem) :
			fieldItem_(fieldItem){}

		~SquarePresentationBuilder() override {
			SDL_FreeSurface(surface_);
		}

		void changeFieldItem(FieldItem* fieldItem) {
			fieldItem_ = fieldItem;
		}

		void setSprite() override {
			surface_ = dynamic_cast<const Square*> (fieldItem_->getContent())->getColor() == Square::SquareColor::RED
				? redSurface_
				: blackSurface_;
		}
		void setPosition() override {
			dist_ = { fieldItem_->getDestination().x_, fieldItem_->getDestination().y_, surface_->w, surface_->h };
		}
		FieldItemPresentation getResult() override {
			return { surface_, dist_ };
		}
	private:
		FieldItem* fieldItem_ = nullptr;
		SDL_Surface* redSurface_ = IMG_Load("sprites/red_drop.jpg");
		SDL_Surface* blackSurface_ = IMG_Load("sprites/black_drop.jpg");
		SDL_Surface* surface_ = nullptr;
		SDL_Rect dist_{ 0, 0, 0, 0 };
};

