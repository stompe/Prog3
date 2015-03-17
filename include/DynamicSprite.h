#ifndef DYNAMICSPRITE_H
#define DYNAMICSPRITE_H

#include "Sprite.h"

class DynamicSprite : public Sprite
{

public:

	DynamicSprite(int width, int height, std::string filepath, int x, int y);
	~DynamicSprite();

	void moveInX(int xPixels);
	void moveInY(int yPixels);
	
	void move(int xPixels, int yPixels);

	void update();

private:

};

#endif