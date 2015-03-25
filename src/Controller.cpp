#include "../include/Controller.h"
#include <iostream>

Controller::Controller(Player* player)
{
	this->player = player;
	sound = Mix_LoadWAV("res/sound.wav");
}

Controller::~Controller()
{
	delete player;
	Mix_FreeChunk(sound);
	
	printf("\nController deconstructed");
}

void Controller::moveControllerPlayerInX(int xPixels)
{
	player->getPlayerSprite()->moveInX(xPixels);
}

void Controller::moveControllerPlayerInY(int yPixels)
{
	player->getPlayerSprite()->moveInY(yPixels);
}

void Controller::handleControllerInput(SDL_Event event, std::vector<DynamicSprite*> sprites)
{
	/*printf("before Switch\n");
	switch(event.type)
		{
			case SDL_KEYDOWN:
					keyHandler->handleKeyboardEvent(event,1);
				break;
			
			case SDL_KEYUP:
					keyHandler->handleKeyboardEvent(event,0);
				break;
			
			default:
				break;
		}
	printf("after Switch\n");
	*/
	executeControllerInput(sprites);
}

void Controller::executeControllerInput(std::vector<DynamicSprite*> sprites)
{
	if(keyboard_handler->isPressed(SDL_SCANCODE_UP))
	{
		moveControllerPlayerInY(-5);
		if(checkAllCollision(sprites))
		{
			printf("Collision top\n");
			moveControllerPlayerInY(-(-5));
			Mix_PlayChannel(-1, sound, 0);
		}
	}

	if(keyboard_handler->isPressed(SDL_SCANCODE_DOWN))
	{
		moveControllerPlayerInY(5);
		if(checkAllCollision(sprites))
		{
			printf("Collision bot\n");
			moveControllerPlayerInY(-(5));
			Mix_PlayChannel(-1, sound, 0);
		}
	}

	if(keyboard_handler->isPressed(SDL_SCANCODE_LEFT))
	{
		moveControllerPlayerInX(-5);
		if(checkAllCollision(sprites))
		{
			printf("Collision left\n");
			moveControllerPlayerInX(-(-5));
			Mix_PlayChannel(-1, sound, 0);
		}
	}
	if(keyboard_handler->isPressed(SDL_SCANCODE_RIGHT))
	{
		moveControllerPlayerInX(5);
		if(checkAllCollision(sprites))
		{
			printf("Collision right\n");
			moveControllerPlayerInX(-(5));
			Mix_PlayChannel(-1, sound, 0);
		}
	}
}

bool Controller::checkAllCollision(std::vector<DynamicSprite*> sprites)
{
	bool collided = NULL;
	SDL_Rect a, b;
	DynamicSprite* pSprite = player->getPlayerSprite();
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