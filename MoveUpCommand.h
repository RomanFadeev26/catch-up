#pragma once
#include <any>
#include "SDL.h"
#include "ICommand.h"
#include "FieldItem.h"

class MoveUpCommand : public ICommand {
	public:
		MoveUpCommand(FieldItem* item) : item_(item) {};
		void execute(const std::any& data) override {
			if (std::any_cast<bool>(data)) {
				item_->getContent()->changeSpeedY(-10);
			}
			else {
				item_->getContent()->changeSpeedY(0);
			}
		}
		void execute() override {}
	private:
		FieldItem* item_;
};

