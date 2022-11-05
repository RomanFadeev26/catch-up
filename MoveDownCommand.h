#pragma once
#include <any>
#include "ICommand.h"
#include "FieldItem.h"

class MoveDownCommand : public ICommand {
public:
	MoveDownCommand(FieldItem* item) : item_(item) {};
	void execute(const std::any& data) override {
		if (std::any_cast<bool>(data)) {
			item_->getContent()->changeSpeedY(10);
		}
		else {
			item_->getContent()->changeSpeedY(0);
		}
	}
	void execute() override {}
private:
	FieldItem* item_;
};

