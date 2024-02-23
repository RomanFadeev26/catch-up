#pragma once
#include <any>
#include "ICommand.h"
#include "FieldItem.h"

class MoveRightCommand : public ICommand {
	public:
		MoveRightCommand(FieldItem* item);
		void execute(const std::any& data) override;
		void execute() override;
	private:
		FieldItem* item_;
};

