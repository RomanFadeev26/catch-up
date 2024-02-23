#include "EventsHandler.h"

EventsHandler::EventsHandler(
	ICommand* moveUpPlayer1Command,
	ICommand* moveUpPlayer2Command,
	ICommand* moveLeftPlayer1Command,
	ICommand* moveLeftPlayer2Command,
	ICommand* moveDownPlayer1Command,
	ICommand* moveDownPlayer2Command,
	ICommand* moveRightPlayer1Command,
	ICommand* moveRightPlayer2Command,
	ICommand* exitGameCommand
) :
	moveUpPlayer1Command_(moveUpPlayer1Command),
	moveUpPlayer2Command_(moveUpPlayer2Command),
	moveLeftPlayer1Command_(moveLeftPlayer1Command),
	moveLeftPlayer2Command_(moveLeftPlayer2Command),
	moveDownPlayer1Command_(moveDownPlayer1Command),
	moveDownPlayer2Command_(moveDownPlayer2Command),
	moveRightPlayer1Command_(moveRightPlayer1Command),
	moveRightPlayer2Command_(moveRightPlayer2Command),
	exitGameCommand_(exitGameCommand)
{};

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