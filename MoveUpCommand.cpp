#include "MoveUpCommand.h"

MoveUpCommand::MoveUpCommand(FieldItem* item) : item_(item) {};

void MoveUpCommand::execute(const std::any& data) {
	if (std::any_cast<bool>(data)) {
		item_->getContent()->changeSpeedY(-10);
	}
	else {
		item_->getContent()->changeSpeedY(0);
	}
};

void MoveUpCommand::execute() {};
