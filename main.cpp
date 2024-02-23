#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"

using namespace std;

int main(int argc, char** argv) {

	if (SDL_Init (SDL_INIT_EVERYTHING) < 0) return -1;
	static constexpr int IMG_FLAGS = IMG_INIT_PNG & IMG_INIT_JPG;
	IMG_Init(IMG_FLAGS);

	Game game;

	game.init();
	game.play();

	IMG_Quit();
	SDL_Quit();
	
	return 0;
}