#pragma once
#include <any>
#include "ICommand.h"
#include "FieldItem.h"

class MoveDownCommand : public ICommand {
public:
	MoveDownCommand(FieldItem* item);
	void execute(const std::any& data) override;
	void execute() override;
private:
	FieldItem* item_;
};

