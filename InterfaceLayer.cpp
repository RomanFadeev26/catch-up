#include "InterfaceLayer.h"

InterfaceLayer::InterfaceLayer(Player* player1, Player* player2, Timer* timer) :
	player1_(player1), player2_(player2), timer_(timer)
{
	TTF_Init();
	font_ = TTF_OpenFont("fonts/Roboto/Roboto-Regular.ttf", 14);
};

InterfaceLayer::~InterfaceLayer() {
	TTF_CloseFont(font_);
}

void InterfaceLayer::renderItems() const {

	std::string player1Points = std::to_string(player1_->score()).append(" Player 1");
	std::string player2Points = std::to_string(player2_->score()).append(" Player 2");
	std::string currentTime = std::to_string(timer_->getCurrentSeconds());

	SDL_Surface* player1PointsSurface_ = TTF_RenderText_Solid(font_, player1Points.c_str(), color_);
	SDL_Surface* player2PointsSurface_ = TTF_RenderText_Solid(font_, player2Points.c_str(), color_);
	SDL_Surface* timerSurface_ = TTF_RenderText_Solid(font_, currentTime.c_str(), color_);

	int windowWidth = SDL_GetWindowSurface(renderEngine_->getWindow().getWindow())->w;
	IPresentationBuilder::FieldItemPresentation player1Presentation{ player1PointsSurface_, { 10, 10, player1PointsSurface_->w, player1PointsSurface_->h } };
	IPresentationBuilder::FieldItemPresentation player2Presentation{ player2PointsSurface_, { windowWidth - 10 - player1PointsSurface_->w, 10, player1PointsSurface_->w, player1PointsSurface_->h } };
	IPresentationBuilder::FieldItemPresentation timerPresentation{ timerSurface_, { (windowWidth - timerSurface_->w) / 2, 10, timerSurface_->w, timerSurface_->h } };

	renderEngine_->addSprite(player1Presentation);
	renderEngine_->addSprite(player2Presentation);
	renderEngine_->addSprite(timerPresentation);
};