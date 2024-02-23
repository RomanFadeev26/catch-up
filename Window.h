#pragma once
#include "SDL.h"
class Window
{	
	public:
		Window(int width = 0, int heigth = 0);
		Window(const Window&);
		Window(Window&&) noexcept = default;
		void changeSize(int deltaHeight, int deltaWidth);
		SDL_Window* getWindow() const;
		~Window();
	private:
		int height_;
		int width_;
		SDL_Window* window_;
};

