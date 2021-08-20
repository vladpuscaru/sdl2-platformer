#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

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

void RenderWindow::render(Entity& p_entity) {
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;

	SDL_Rect dst;
	dst.x = p_entity.getX() * 4;
	dst.y = p_entity.getY() * 4;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;

	SDL_RenderCopy(this->renderer, p_entity.getTexture(), &src, &dst);
}

void RenderWindow::display() {
	SDL_RenderPresent(this->renderer);
}

void RenderWindow::cleanUp() {
	SDL_DestroyWindow(this->window);
}