#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include "SDL2/SDL.h"
#include <stdio.h>

class Sprite
{

public:

	Sprite(int width, int height, std::string filepath, int x, int y);
	~Sprite();

	void draw(SDL_Surface* screenSurface);
	void tick();
	SDL_Surface* getImage();

private:

	int width;
	int height;
	int x;
	int y;
	std::string filepath;
	SDL_Surface* image;

};

#endif