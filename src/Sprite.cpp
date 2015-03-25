#include "../include/Sprite.h"

Sprite::Sprite(std::string filepath, int x, int y, SDL_Renderer* render)
{
	this->filepath = filepath;
	this->x = x;
	this->y = y;
	SDL_Surface* image = SDL_LoadBMP(filepath.c_str());
	this->width = image->w;
	this->height = image->h;

	offset.x = x;
	offset.y = y;
	offset.w = width;
	offset.h = height;

	texture = SDL_CreateTextureFromSurface(render, image);
	SDL_FreeSurface(image);


}

Sprite::~Sprite()
{
	SDL_DestroyTexture(texture);
	texture = NULL;
	printf("\nSprite deconstructed");
}

void Sprite::update()
{
	offset.x = this->x;
	offset.y = this->y;
	offset.w = this->width;
	offset.h = this->height;
}

void Sprite::draw(SDL_Renderer* render)
{
	SDL_RenderCopy(render, texture, NULL, &offset);
}