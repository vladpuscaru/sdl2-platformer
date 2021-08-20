#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height) 
	: window(NULL), renderer(NULL)
{
	this->window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		std::cout << "Window failed to init. ERROR: " << SDL_GetError() << std::endl;
	}

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
	SDL_Texture* texture = NULL;

	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL) {
		std::cout << "Failed to load a texture. ERROR: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void RenderWindow::clear() {
	SDL_RenderClear(this->renderer);
}

void RenderWindow::render(SDL_Texture* p_texture) {
	SDL_RenderCopy(this->renderer, p_texture, NULL, NULL);
}

void RenderWindow::display() {
	SDL_RenderPresent(this->renderer);
}

void RenderWindow::cleanUp() {
	SDL_DestroyWindow(this->window);
}