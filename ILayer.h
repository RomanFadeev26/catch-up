#pragma once
#include "SDL.h"

class ILayer {
	public:
		virtual void renderItems() const = 0;
		virtual ~ILayer() = default;
};
