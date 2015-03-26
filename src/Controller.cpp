#include "../include/Controller.h"
#include <iostream>

Controller::Controller(DynamicSprite* controlled_sprite)
{
	this->controlled_sprite = controlled_sprite;
}

Controller::~Controller()
{
	
	printf("\nController deconstructed");
}

void Controller::moveControllerPlayerInX(int xPixels)
{
	controlled_sprite->moveInX(xPixels);
}

void Controller::moveControllerPlayerInY(int yPixels)
{
	controlled_sprite->moveInY(yPixels);
}

void Controller::handleControllerInput(std::vector<Sprite*> sprites)
{
	executeControllerInput(sprites);
}

void Controller::executeControllerInput(std::vector<Sprite*> sprites){}

bool Controller::checkAllCollision(std::vector<Sprite*> sprites)
{
	bool collided = NULL;
	SDL_Rect a, b;
	DynamicSprite* pSprite = controlled_sprite;
	a.x = pSprite->getSpriteXPosition();
	a.y = pSprite->getSpriteYPosition();
	a.h = pSprite->getSpriteWidth();
	a.w = pSprite->getSpriteHeight();


	for(int i = 0; i < sprites.size(); i++)
	{
		if(sprites[i] != pSprite)
		{
				Sprite* s = sprites[i];
				b.x = s->getSpriteXPosition();
				b.y = s->getSpriteYPosition();
				b.h = s->getSpriteWidth();
				b.w = s->getSpriteHeight();
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