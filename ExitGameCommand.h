#pragma once
#include <any>
#include "ICommand.h"
class ExitGameCommand :
    public ICommand
{
public:
    ExitGameCommand(bool& isGameContinued);
    void execute() override;
    void execute(const std::any&) override;
private:
    bool& isGameContinued_;
};

