#include "EventsHandler.h"

EventsHandler::~EventsHandler() {
	for (auto& i : buttonHandlers_) {
		delete i;
	}
}

void EventsHandler::setButtonEvents() {
	ButtonHandler* moveUpPlayer1Handler = new ButtonHandler(SDL_SCANCODE_W, &event_);
	moveUpPlayer1Handler->setCommand(moveUpPlayer1Command_);
	buttonHandlers_.push_back(moveUpPlayer1Handler);

	ButtonHandler* moveLeftPlayer1Handler = new ButtonHandler(SDL_SCANCODE_A, &event_);
	moveLeftPlayer1Handler->setCommand(moveLeftPlayer1Command_);
	buttonHandlers_.push_back(moveLeftPlayer1Handler);

	ButtonHandler* moveDownPlayer1Handler = new ButtonHandler(SDL_SCANCODE_S, &event_);
	moveDownPlayer1Handler->setCommand(moveDownPlayer1Command_);
	buttonHandlers_.push_back(moveDownPlayer1Handler);

	ButtonHandler* moveRightPlayer1Handler = new ButtonHandler(SDL_SCANCODE_D, &event_);
	moveRightPlayer1Handler->setCommand(moveRightPlayer1Command_);
	buttonHandlers_.push_back(moveRightPlayer1Handler);



	ButtonHandler* moveUpPlayer2Handler = new ButtonHandler(SDL_SCANCODE_UP, &event_);
	moveUpPlayer2Handler->setCommand(moveUpPlayer2Command_);
	buttonHandlers_.push_back(moveUpPlayer2Handler);

	ButtonHandler* moveLeftPlayer2Handler = new ButtonHandler(SDL_SCANCODE_LEFT, &event_);
	moveLeftPlayer2Handler->setCommand(moveLeftPlayer2Command_);
	buttonHandlers_.push_back(moveLeftPlayer2Handler);

	ButtonHandler* moveDownPlayer2Handler = new ButtonHandler(SDL_SCANCODE_DOWN, &event_);
	moveDownPlayer2Handler->setCommand(moveDownPlayer2Command_);
	buttonHandlers_.push_back(moveDownPlayer2Handler);

	ButtonHandler* moveRightPlayer2Handler = new ButtonHandler(SDL_SCANCODE_RIGHT, &event_);
	moveRightPlayer2Handler->setCommand(moveRightPlayer2Command_);
	buttonHandlers_.push_back(moveRightPlayer2Handler);

	ButtonHandler* exitGameHandler = new ButtonHandler(SDL_SCANCODE_ESCAPE, &event_);
	exitGameHandler->setCommand(exitGameCommand_);
	buttonHandlers_.push_back(exitGameHandler);
}

void EventsHandler::handleButtonEvents() {
	while (SDL_PollEvent(&event_) != 0) {
		for (const auto& i : buttonHandlers_) {
			i->handlePressing();
		}
	}
}