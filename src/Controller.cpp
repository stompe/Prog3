#include "../include/Controller.h"
#include <iostream>


// create a new controller and set its controlled sprite
Controller::Controller(DynamicSprite* controlled_sprite)
{
	this->controlled_sprite = controlled_sprite;
}

// destroy this object
Controller::~Controller()
{
	delete controlled_sprite;

	printf("\nController deconstructed");
}


// move the sprite in X
void Controller::moveControllerPlayerInX(int xPixels)
{
	controlled_sprite->moveInX(xPixels);
}

// move the sprite in Y
void Controller::moveControllerPlayerInY(int yPixels)
{
	controlled_sprite->moveInY(yPixels);
}

// Handle input for the controller
void Controller::handleControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites)
{
	executeControllerInput(static_sprites, dynamic_sprites);
}

// a function to implement in sub-classes to determine what will happen with the controller  when input is given
void Controller::executeControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites){}


// check if the controlled sprite collided after it moved
bool Controller::checkAllCollision(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites)
{
	bool collided = NULL;
	SDL_Rect a, b;
	DynamicSprite* pSprite = controlled_sprite;
	a.x = pSprite->getSpriteXPosition();
	a.y = pSprite->getSpriteYPosition();
	a.w = pSprite->getSpriteWidth();
	a.h = pSprite->getSpriteHeight();

	//check against all static sprites in the level
	for(int i = 0; i < static_sprites.size(); i++)
	{
	
			StaticSprite* sSprite = static_sprites[i];
			b.x = sSprite->getSpriteXPosition();
			b.y = sSprite->getSpriteYPosition();
			b.w = sSprite->getSpriteWidth();
			b.h = sSprite->getSpriteHeight();
			if(checkCollision(a,b))
			{	
				collided = true;
				return collided;
			}
			else
				collided = false;

	
	}

	//check against all dynamic sprites in the level
	for(int i = 0; i < dynamic_sprites.size(); i++)
	{
		if(dynamic_sprites[i] != pSprite)
		{
				DynamicSprite* dSprite = dynamic_sprites[i];
				b.x = dSprite->getSpriteXPosition();
				b.y = dSprite->getSpriteYPosition();
				b.w = dSprite->getSpriteWidth();
				b.h = dSprite->getSpriteHeight();
				if(checkCollision(a,b))
				{	
					collided = true;
					return collided;
				}
				else
					collided = false;

		}
	}

	return collided;
}

// check if the controlled sprite collided with the other sprite supplied from checkAllCollision()
bool Controller::checkCollision(SDL_Rect a, SDL_Rect b)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//if any of the sides from A are outside of B
	if(bottomA <= topB)
	{
		return false;
	}

	if(topA >= bottomB)
	{
		return false;
	}

	if(rightA <= leftB)
	{
		return false;
	}

	if(leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}