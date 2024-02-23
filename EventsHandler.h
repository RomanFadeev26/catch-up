#pragma once
#include <vector>
#include "SDL.h"
#include "ButtonHandler.h"
#include "ICommand.h"
class EventsHandler
{	
	public:
		EventsHandler() = default;
		EventsHandler(
			ICommand* moveUpPlayer1Command,
			ICommand* moveUpPlayer2Command,
			ICommand* moveLeftPlayer1Command,
			ICommand* moveLeftPlayer2Command,
			ICommand* moveDownPlayer1Command,
			ICommand* moveDownPlayer2Command,
			ICommand* moveRightPlayer1Command,
			ICommand* moveRightPlayer2Command,
			ICommand* exitGameCommand
		);
		EventsHandler(const EventsHandler&) = default;
		EventsHandler(EventsHandler&&) noexcept = default;
		~EventsHandler();
		EventsHandler& operator=(EventsHandler&&) noexcept = default;
		void setButtonEvents();
		void handleButtonEvents();
	private:
		SDL_Event event_;
		ICommand* moveUpPlayer1Command_ = nullptr;
		ICommand* moveUpPlayer2Command_ = nullptr;
		ICommand* moveLeftPlayer1Command_ = nullptr;
		ICommand* moveLeftPlayer2Command_ = nullptr;
		ICommand* moveDownPlayer1Command_ = nullptr;
		ICommand* moveDownPlayer2Command_ = nullptr;
		ICommand* moveRightPlayer1Command_ = nullptr;
		ICommand* moveRightPlayer2Command_ = nullptr;
		ICommand* exitGameCommand_ = nullptr;
		std::vector<ButtonHandler*> buttonHandlers_;
};

