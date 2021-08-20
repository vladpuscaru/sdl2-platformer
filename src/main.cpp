#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argv, char* args[]) {
	
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "Hey... SDL_Init HAS FAILED. \nSDL_ERROR:" << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "Hey... IMG_Init HAS FAILED. \nIMG_ERROR: " << SDL_GetError() << std::endl;
	}


	RenderWindow window("Game v1.0", 1280, 720);
	bool gameRunning = true;
	SDL_Event event;

	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

	while (gameRunning) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameRunning = false;
			}
		}

		window.clear();
		window.render(grassTexture);
		window.display();
	}


	window.cleanUp();
	SDL_Quit();

	return 0;
}