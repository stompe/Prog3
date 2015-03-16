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

	setXPosition(getXPosition() + xPixels);
}

void DynamicSprite::moveInY(int yPixels)
{
	setYPosition(getYPosition() + yPixels);
}

void DynamicSprite::move(int xPixels, int yPixels)
{
	setPosition(getXPosition() + xPixels, getYPosition() + yPixels);
}

void DynamicSprite::tick()
{
	if(getXPosition() >= 0 && getXPosition() + getWidth() < 640 && getFilepath() != "res/hello.bmp") 
		moveInX(1);
	if(getFilepath() == "res/hello.bmp")
	{
		moveInX(1);
		if(getXPosition() >= 0)
			setXPosition(-getWidth()/2);
	}
	if(getXPosition() + getWidth() >= 640)
		setXPosition(0);
}