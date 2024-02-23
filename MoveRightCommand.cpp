#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand(FieldItem* item) : item_(item) {};

void MoveRightCommand::execute(const std::any& data) {
	if (std::any_cast<bool>(data)) {
		item_->getContent()->changeSpeedX(10);
	}
	else {
		item_->getContent()->changeSpeedX(0);
	}
};

void MoveRightCommand::execute() {};
