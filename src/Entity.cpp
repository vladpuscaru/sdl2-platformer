#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture) {
	this->x = p_x;
	this->y = p_y;
	this->texture = p_texture;

	this->currentFrame.x = 0;
	this->currentFrame.y = 0;
	this->currentFrame.w = 32;
	this->currentFrame.h = 32;
}

float Entity::getX() const {
	return this->x;
}

float Entity::getY() const {
	return this->y;
}

SDL_Rect Entity::getCurrentFrame() const {
	return this->currentFrame;
}

SDL_Texture* Entity::getTexture() const {
	return this->texture;
}