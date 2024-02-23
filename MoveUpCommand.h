#pragma once
#include <any>
#include "SDL.h"
#include "ICommand.h"
#include "FieldItem.h"

class MoveUpCommand : public ICommand {
	public:
		MoveUpCommand(FieldItem* item);
		void execute(const std::any& data) override;
		void execute() override;
	private:
		FieldItem* item_;
};

