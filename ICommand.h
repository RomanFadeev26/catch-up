#pragma once
#include <any>

class ICommand {
	public:
		virtual void execute() = 0;
		virtual void execute(const std::any& data) = 0;
		virtual ~ICommand() = default;
};