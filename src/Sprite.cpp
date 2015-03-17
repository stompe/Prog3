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

void Sprite::update()
{
	
}

void Sprite::draw(SDL_Surface* screen_surface)
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface(image,NULL,screen_surface,&offset);
}