#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	RenderWindow(const char* p_title, int p_width, int p_height);
	SDL_Texture* loadTexture(const char* p_filePath);
	void clear();
	void render(SDL_Texture* p_texture);
	void display();
	void cleanUp();
};