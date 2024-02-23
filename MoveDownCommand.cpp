#include "MoveDownCommand.h"

MoveDownCommand::MoveDownCommand(FieldItem* item) : item_(item) {};

void MoveDownCommand::execute(const std::any& data) {
	if (std::any_cast<bool>(data)) {
		item_->getContent()->changeSpeedY(10);
	}
	else {
		item_->getContent()->changeSpeedY(0);
	}
};

void MoveDownCommand::execute() {};