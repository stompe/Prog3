#include "../include/DynamicSprite.h"

DynamicSprite::DynamicSprite(int width, int height, std::string filepath, int x, int y)
: Sprite(width, height, filepath, x, y)
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
	
}