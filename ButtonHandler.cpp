#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(const SDL_Scancode button, SDL_Event* event) : button_(button), event_(event) {
	isPressed_ = false;
};

void ButtonHandler::setCommand(ICommand* command) {
	command_ = command;
}

void ButtonHandler::handlePressing() {
	if (event_->type == SDL_KEYDOWN
		&& event_->key.keysym.scancode == button_
		&& event_->key.repeat == 0
		) {
		isPressed_ = true;
	}

	if (event_->type == SDL_KEYUP && event_->key.keysym.scancode == button_ && event_->key.repeat == 0) {
		isPressed_ = false;
	}
	if (isPressed_) {
		command_->execute();
	}
	if ((event_->key.keysym.scancode == button_ && event_->key.repeat == 0) || isPressed_) {
		command_->execute(std::make_any<bool>(isPressed_));
	}
}
