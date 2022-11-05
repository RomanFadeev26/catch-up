#pragma once
#include <any>
#include "ICommand.h"
class ExitGameCommand :
    public ICommand
{
public:
    ExitGameCommand(bool& isGameContinued): isGameContinued_(isGameContinued) {}
    void execute() override {
        isGameContinued_ = false;
    }
    void execute(const std::any&) override {}
private:
    bool& isGameContinued_;
};

