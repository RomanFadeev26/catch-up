#include "Window.h"

void Window::changeSize(int deltaHeight, int deltaWidth) {
	height_ += deltaHeight;
	width_ += deltaWidth;
	SDL_SetWindowSize(window_, width_, height_);
}

