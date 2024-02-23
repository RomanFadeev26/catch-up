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
		ButtonHandler(const SDL_Scancode button, SDL_Event* event);
		void setCommand(ICommand* command);

		void handlePressing();
	private:
		ICommand* command_ = nullptr;
		const SDL_Scancode button_;
		SDL_Event* event_;
		bool isPressed_;
};

