#pragma once
#include "SDL.h"
#include "Player.h"
#include "Field.h"
#include "FieldItem.h"
#include "GameEventsObserver.h"
#include "GameLayer.h"
#include "EventsHandler.h"
#include "Square.h"
#include "SquarePresentationBuilder.h"
#include "FieldItemPresentationDirector.h"
#include "PlayerCatchedListener.h"
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

constexpr int DEFAULT_WINDOW_WIDTH = 640, DEFAULT_WINDOW_HEIGHT = 480;

class Game
{
	public:
		Game() {
			timer_.setObserver(gameEventsOberver_);
			square1_ = new Square(Square::SquareColor::RED);
			square2_ = new Square(Square::SquareColor::BLACK);
			renderer_ = SDL_CreateRenderer(window_.getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			field_.addItem(new FieldItem(square1_, 100, 240));
			field_.addItem(new FieldItem(square2_, DEFAULT_WINDOW_WIDTH - 100, 240));


			moveUpPlayer1Command_ = new MoveUpCommand(field_.getItems()[0]);
			moveLeftPlayer1Command_ = new MoveLeftCommand(field_.getItems()[0]);

			moveDownPlayer1Command_ = new MoveDownCommand(field_.getItems()[0]);
			moveRightPlayer1Command_ = new MoveRightCommand(field_.getItems()[0]);


			moveUpPlayer2Command_ = new MoveUpCommand(field_.getItems()[1]);
			moveLeftPlayer2Command_ = new MoveLeftCommand(field_.getItems()[1]);

			moveDownPlayer2Command_ = new MoveDownCommand(field_.getItems()[1]);
			moveRightPlayer2Command_ = new MoveRightCommand(field_.getItems()[1]);

			exitGameCommand_ = new ExitGameCommand(isGameContinued_);

			eventsHandler_ = EventsHandler(
				moveUpPlayer1Command_,
				moveUpPlayer2Command_,
				moveLeftPlayer1Command_,
				moveLeftPlayer2Command_,
				moveDownPlayer1Command_,
				moveDownPlayer2Command_,
				moveRightPlayer1Command_,
				moveRightPlayer2Command_,
				exitGameCommand_
			);
		}
		void init() {
			eventsHandler_.setButtonEvents();
			playerCatchedListener_->addPlayer(&player1_);
			playerCatchedListener_->addPlayer(&player2_);
			gameEventsOberver_->subscribe(playerCatchedListener_);
		}
		
		void play() {
			while (isGameContinued_) {
				updatePlayers();
				eventsHandler_.handleButtonEvents();

				std::vector<IPresentationBuilder::FieldItemPresentation> presentations;
				fieldItemPresentationDirector_.changeBuilder(squareBuilder_);

				for (const auto i : field_.getItems()) {
					if (dynamic_cast<Square*>(i->getContent())) {
						squareBuilder_->changeFieldItem(i);
						IPresentationBuilder::FieldItemPresentation presentation = fieldItemPresentationDirector_.make();
						presentations.push_back(presentation);
						i->move(DEFAULT_WINDOW_WIDTH - presentation.dist.w, DEFAULT_WINDOW_HEIGHT - presentation.dist.h);
					}
				}

				GameLayer* gameLayer = new GameLayer(gameEventsOberver_, presentations, renderer_);
				timer_.alarm();
				gameLayer->renderItems();
				delete gameLayer;
			}
		}
		~Game() {
			for (auto& i : field_.getItems()) {
				delete i;
			}
			delete square1_;
			delete square2_;
			SDL_DestroyRenderer(renderer_);
			delete moveUpPlayer1Command_;
			delete moveUpPlayer2Command_;
			delete moveLeftPlayer1Command_;
			delete moveLeftPlayer2Command_;
			delete moveDownPlayer1Command_;
			delete moveDownPlayer2Command_;
			delete moveRightPlayer1Command_;
			delete moveRightPlayer2Command_;
			delete playerCatchedListener_;
			delete exitGameCommand_;
			delete gameEventsOberver_;
			delete squareBuilder_;
		}
	private:
		bool isGameContinued_ = true;
		Player player1_ = Player(Player::Roles::Hunter, 0, "Player 1");
		Square* square1_ = nullptr;
		Player player2_ = Player(Player::Roles::Victim, 0, "Player 2");
		Square* square2_ = nullptr;
		Field field_ = Field();
		//todo заюзаем dynamic_cast для выбора билдера - он возвращает NULL если невозможно преобразовать
		Window window_ = Window(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
		SDL_Renderer* renderer_ = nullptr;
		SquarePresentationBuilder* squareBuilder_ = new SquarePresentationBuilder();
		PlayerCatchedListener* playerCatchedListener_ = new PlayerCatchedListener();
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

		void updatePlayers() {
			if (player1_.role() == Player::Roles::Hunter && square1_->getColor() == Square::SquareColor::BLACK) {
				square1_->changeColor();
				field_.getItems()[0]->resetDestination();
			}
			if (player1_.role() == Player::Roles::Victim && square1_->getColor() == Square::SquareColor::RED) {
				square1_->changeColor();
				field_.getItems()[0]->resetDestination();
			}
			if (player2_.role() == Player::Roles::Victim && square2_->getColor() == Square::SquareColor::RED) {
				square2_->changeColor();
				field_.getItems()[1]->resetDestination();
			}
			if (player2_.role() == Player::Roles::Hunter && square2_->getColor() == Square::SquareColor::BLACK) {
				square2_->changeColor();
				field_.getItems()[1]->resetDestination();
			}
		}
};

