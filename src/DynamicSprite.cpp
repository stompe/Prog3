#include "../include/DynamicSprite.h"

DynamicSprite::DynamicSprite(std::string filepath, int x, int y, SDL_Renderer* render)
: Sprite(filepath, x, y, render)
{

}

DynamicSprite::~DynamicSprite()
{

}

void DynamicSprite::moveInX(int xPixels)
{

	setSpriteXPosition(getSpriteXPosition() + xPixels);
}

void DynamicSprite::moveInY(int yPixels)
{
	setSpriteYPosition(getSpriteYPosition() + yPixels);
}

void DynamicSprite::move(int xPixels, int yPixels)
{
	setSpritePosition(getSpriteXPosition() + xPixels, getSpriteYPosition() + yPixels);
}

void DynamicSprite::update()
{
	Sprite::update();
}