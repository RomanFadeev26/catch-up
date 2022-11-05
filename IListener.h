#pragma once
#include <string>
#include <any>

class IListener {
	public:
		virtual void update(const std::string& event) = 0;
		virtual void update(const std::string& event, std::any& data) = 0;
		virtual ~IListener() = default;
};