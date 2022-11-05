#pragma once
#include <any>
#include "ICommand.h"
#include "FieldItem.h"

class MoveRightCommand : public ICommand {
	public:
		MoveRightCommand(FieldItem* item) : item_(item) {};
		void execute(const std::any& data) override {
			if (std::any_cast<bool>(data)) {
				item_->getContent()->changeSpeedX(10);
			}
			else {
				item_->getContent()->changeSpeedX(0);
			}
		}
		void execute() override {}
	private:
		FieldItem* item_;
};

