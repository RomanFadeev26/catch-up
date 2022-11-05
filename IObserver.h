#pragma once
#include <string>
#include <any>
#include "IListener.h"


class IObserver {
	public:
		virtual void notify(const std::string& event) const = 0;
		virtual void notify(const std::string& event, std::any& data) const = 0;
		virtual void subscribe(IListener* listener) = 0;
		virtual void unsubscribe(IListener* listener) = 0;
		virtual ~IObserver() = default;
};