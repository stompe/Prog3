#include "../include/DynamicSprite.h"

DynamicSprite::DynamicSprite(std::string filepath, int x, int y, SDL_Renderer* render)
: Sprite(filepath, x, y, render)
{

}

DynamicSprite::~DynamicSprite()
{
}

// move the sprite in X
void DynamicSprite::moveInX(int xPixels)
{

	setSpriteXPosition(getSpriteXPosition() + xPixels);
}

// move the sprite in Y
void DynamicSprite::moveInY(int yPixels)
{
	setSpriteYPosition(getSpriteYPosition() + yPixels);
}

// move the sprite in X and Y
void DynamicSprite::move(int xPixels, int yPixels)
{
	setSpritePosition(getSpriteXPosition() + xPixels, getSpriteYPosition() + yPixels);
}

// update the position of the sprite and affect it by gravity every update
void DynamicSprite::update(int gravity)
{
	setSpriteYPosition(getSpriteYPosition() + gravity);
	Sprite::update();

}