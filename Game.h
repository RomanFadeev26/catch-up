#pragma once
#include "SDL.h"
#include "Player.h"
#include "Field.h"
#include "FieldItem.h"
#include "GameEventsObserver.h"
#include "GameLayer.h"
#include "InterfaceLayer.h"
#include "EventsHandler.h"
#include "Square.h"
#include "SquarePresentationBuilder.h"
#include "FieldItemPresentationDirector.h"
#include "PlayerCatchedListener.h"
#include "TimerListener.h"
#include "Window.h"
#include "MoveDownCommand.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "MoveUpCommand.h"
#include "ExitGameCommand.h"
#include "Timer.h"
#include "ICommand.h"
#include "IObserver.h"
#include "IListener.h"
#include "RenderEngine.h"

class Game
{
	public:
		Game();
		void init();
		void play();
		~Game();
	private:
		bool isGameContinued_ = true;
		Player player1_ = Player(Player::Roles::Hunter, 0, "Player 1");
		Square* square1_ = nullptr;
		Player player2_ = Player(Player::Roles::Victim, 0, "Player 2");
		Square* square2_ = nullptr;
		Field field_ = Field();
		RenderEngine* renderEngine_ = RenderEngine::getInstance();
		SquarePresentationBuilder* squareBuilder_ = new SquarePresentationBuilder();
		PlayerCatchedListener* playerCatchedListener_ = new PlayerCatchedListener();
		TimerListener* timerListener_ = new TimerListener(&timer_);
		EventsHandler eventsHandler_;
		Timer timer_;
		FieldItemPresentationDirector fieldItemPresentationDirector_;
		IObserver* gameEventsOberver_ = new GameEventsObserver();
		ICommand* moveUpPlayer1Command_;
		ICommand* moveUpPlayer2Command_;
		ICommand* moveLeftPlayer1Command_;
		ICommand* moveLeftPlayer2Command_;
		ICommand* moveDownPlayer1Command_;
		ICommand* moveDownPlayer2Command_;
		ICommand* moveRightPlayer1Command_;
		ICommand* moveRightPlayer2Command_;
		ICommand* exitGameCommand_;
		int startTime_ = 0;

		void updatePlayers();
};

