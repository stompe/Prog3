#include "../include/Sprite.h"

Sprite::Sprite(std::string filepath, int x, int y, SDL_Renderer* render)
{
	//set the filepath to the resource
	this->filepath = filepath;
	
	// set the position of the sprite
	this->x = x;
	this->y = y;


	//create a image from the resource at the filepath
	SDL_Surface* image = SDL_LoadBMP(filepath.c_str());


	// set dimensions of the sprite to the dimensions of the image
	this->width = image->w;
	this->height = image->h;

	// set bounds of the sprite to the image bounds
	offset.x = x;
	offset.y = y;
	offset.w = width;
	offset.h = height;

	// create the texture from the image
	texture = SDL_CreateTextureFromSurface(render, image);
	
	// release the resources connected to the surface image
	SDL_FreeSurface(image);
}

Sprite::~Sprite()
{
	// release all resources connected to this object when it is destroyed
	SDL_DestroyTexture(texture);
	texture = NULL;
	printf("\nSprite deconstructed");
}

// update the bounds of the sprite to the current location
void Sprite::update()
{
	offset.x = this->x;
	offset.y = this->y;
	offset.w = this->width;
	offset.h = this->height;
}


// draw the sprite to the screen
void Sprite::draw(SDL_Renderer* render)
{
	SDL_RenderCopy(render, texture, NULL, &offset);
}