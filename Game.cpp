#include "Game.h"

Game::Game() {
	timer_.setObserver(gameEventsOberver_);
	square1_ = new Square(Square::SquareColor::RED);
	square2_ = new Square(Square::SquareColor::BLACK);

	field_.addItem(new FieldItem(square1_, 100, 240));
	field_.addItem(new FieldItem(square2_, RenderEngine::DEFAULT_WINDOW_WIDTH - 100, 240));


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

Game::~Game() {
	for (auto& i : field_.getItems()) {
		delete i;
	}
	gameEventsOberver_->unsubscribe(playerCatchedListener_);
	gameEventsOberver_->unsubscribe(timerListener_);
	delete square1_;
	delete square2_;
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
	renderEngine_->destroyInstance();
};

void Game::updatePlayers() {
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

void Game::init() {
	eventsHandler_.setButtonEvents();
	playerCatchedListener_->addPlayer(&player1_);
	playerCatchedListener_->addPlayer(&player2_);
	timerListener_->addPlayer(&player1_);
	timerListener_->addPlayer(&player2_);
	gameEventsOberver_->subscribe(playerCatchedListener_);
	gameEventsOberver_->subscribe(timerListener_);
}

void Game::play() {
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
				i->move(RenderEngine::DEFAULT_WINDOW_WIDTH - presentation.dist.w, RenderEngine::DEFAULT_WINDOW_HEIGHT - presentation.dist.h);
			}
		}

		GameLayer* gameLayer = new GameLayer(gameEventsOberver_, presentations);
		timer_.alarm();
		gameLayer->renderItems();

		InterfaceLayer* interfaceLayer = new InterfaceLayer(&player1_, &player2_, &timer_);
		interfaceLayer->renderItems();
		renderEngine_->render();
		delete gameLayer;
		delete interfaceLayer;
	}
}