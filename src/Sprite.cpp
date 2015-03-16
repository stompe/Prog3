#include "../include/Sprite.h"

Sprite::Sprite(int width, int height, std::string filepath, int x, int y)
{
	this->width = width;
	this->height = height;
	this->filepath = filepath;
	this->x = x;
	this->y = y;
	image = SDL_LoadBMP(filepath.c_str());
}

Sprite::~Sprite()
{
	SDL_FreeSurface(image);
	image = NULL;
	printf("\nSprite deconstructed");
}

void Sprite::tick()
{
	
}

void Sprite::draw(SDL_Surface* screenSurface)
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(image,NULL,screenSurface,&offset);
}

SDL_Surface* Sprite::getImage()
{
	return image;
}