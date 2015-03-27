#ifndef DYNAMICSPRITE_H
#define DYNAMICSPRITE_H

#include "Sprite.h"

class DynamicSprite : public Sprite
{

public:

	DynamicSprite(std::string filepath, int x, int y, SDL_Renderer* render);
	~DynamicSprite();

	void moveInX(int xPixels);
	void moveInY(int yPixels);
	
	void move(int xPixels, int yPixels);

	void update(int gravity);

private:

};

#endif