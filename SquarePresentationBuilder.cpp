#include "SquarePresentationBuilder.h"

SquarePresentationBuilder::SquarePresentationBuilder() {};
SquarePresentationBuilder::SquarePresentationBuilder(FieldItem* fieldItem) : fieldItem_(fieldItem) {}

SquarePresentationBuilder::~SquarePresentationBuilder() {
	SDL_FreeSurface(surface_);
}

void SquarePresentationBuilder::changeFieldItem(FieldItem* fieldItem) {
	fieldItem_ = fieldItem;
}

void SquarePresentationBuilder::setSprite() {
	surface_ = dynamic_cast<const Square*> (fieldItem_->getContent())->getColor() == Square::SquareColor::RED
		? redSurface_
		: blackSurface_;
}

void SquarePresentationBuilder::setPosition() {
	dist_ = { fieldItem_->getDestination().x_, fieldItem_->getDestination().y_, surface_->w, 32 };
}

IPresentationBuilder::FieldItemPresentation SquarePresentationBuilder::getResult() {
	return { surface_, dist_ };
}