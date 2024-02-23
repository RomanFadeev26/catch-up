#include "Window.h"

Window::Window(int width, int heigth) : height_(heigth), width_(width) {
	window_ = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, heigth, 0);
};

Window::Window(const Window& window) {
	height_ = window.height_;
	width_ = window.width_;
	window_ = window.window_;
}

Window::~Window() {
	SDL_DestroyWindow(window_);
}

SDL_Window* Window::getWindow() const {
	return window_;
}

void Window::changeSize(int deltaHeight, int deltaWidth) {
	height_ += deltaHeight;
	width_ += deltaWidth;
	SDL_SetWindowSize(window_, width_, height_);
}

