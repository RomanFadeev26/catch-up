#pragma once
#include <string>
#include "IPresentationBuilder.h"

class FieldItemPresentationDirector {
public:
	FieldItemPresentationDirector() {};
	FieldItemPresentationDirector(IPresentationBuilder* builder): builder_(builder) {};
	enum class PresentationTypes { SQUARE };
	void changeBuilder(IPresentationBuilder* builder) {
		builder_ = builder;
	}
	IPresentationBuilder::FieldItemPresentation make() {
		builder_->setSprite();
		builder_->setPosition();
		return builder_->getResult();
	}
private:
	IPresentationBuilder* builder_ = nullptr;
};

