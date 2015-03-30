#ifndef DYNAMICSPRITE_H
#define DYNAMICSPRITE_H

#include "Sprite.h"

// A class that represents a 2D sprite on the screen
// can also move in x or y and can be affected by gravity

class DynamicSprite : public Sprite
{

public:

	DynamicSprite(std::string filepath, int x, int y, SDL_Renderer* render);
	~DynamicSprite();

	//functions to move the sprite in x or y
	void moveInX(int xPixels);
	void moveInY(int yPixels);
	
	// function to move the sprite in both x and y
	void move(int xPixels, int yPixels);


	//function that updates the sprites position on screen
	void update(int gravity);

private:

};

#endif