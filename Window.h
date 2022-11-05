#pragma once
#include "SDL.h"
class Window
{	
	public:
		Window(int width = 0, int heigth = 0): height_(heigth), width_(width) {
			window_ = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, heigth, 0);
		}
		Window(Window&&) noexcept = default;
		void changeSize(int deltaHeight, int deltaWidth);
		SDL_Window* getWindow() const {
			return window_;
		}
		~Window() {
			SDL_DestroyWindow(window_);
		}
	private:
		int height_;
		int width_;
		SDL_Window* window_;
};

