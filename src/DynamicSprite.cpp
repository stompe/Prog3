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
	if(getSpriteXPosition() >= 0 && getSpriteXPosition() + getSpriteWidth() < 640 && getSpriteFilepath() != "res/hello.bmp") 
		moveInX(1);
	if(getSpriteFilepath() == "res/hello.bmp")
	{
		moveInX(1);
		if(getSpriteXPosition() >= 0)
			setSpriteXPosition(-getSpriteWidth()/2);
	}
	if(getSpriteXPosition() + getSpriteWidth() >= 640)
		setSpriteXPosition(0);
}