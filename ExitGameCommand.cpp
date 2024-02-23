#include "ExitGameCommand.h"

ExitGameCommand::ExitGameCommand(bool& isGameContinued) : isGameContinued_(isGameContinued) {}

void ExitGameCommand::execute() {
    isGameContinued_ = false;
}

void ExitGameCommand::execute(const std::any&) {}