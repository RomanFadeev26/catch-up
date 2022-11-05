#pragma once
#include <any>
#include "SDL.h"
#include "ICommand.h"

class ButtonHandler
{
	public:
		ButtonHandler() = default;
		ButtonHandler(const ButtonHandler&) = default;
		ButtonHandler(ButtonHandler&&) = default;
		ButtonHandler(const SDL_Scancode button, SDL_Event* event): button_(button), event_(event){}
		void setCommand(ICommand* command) {
			command_ = command;
		}

		void handlePressing(){
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
	private:
		ICommand* command_ = nullptr;
		const SDL_Scancode button_;
		SDL_Event* event_;
		bool isPressed_;
};

