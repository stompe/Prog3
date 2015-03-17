#include "../include/Controller.h"

Controller::Controller(Player* player)
{
	this->player = player;
}

Controller::~Controller()
{
	delete player;
	
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

void Controller::handleControllerInput(SDL_Event event)
{
	switch(event.type)
		{
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_UP)
					moveControllerPlayerInY(-5);
			

				if (event.key.keysym.sym == SDLK_DOWN)
					moveControllerPlayerInY(5);
				

				if (event.key.keysym.sym == SDLK_LEFT)
					moveControllerPlayerInX(-5);
			
				if (event.key.keysym.sym == SDLK_RIGHT)
					moveControllerPlayerInX(5);	
				break;
			
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_UP)
					moveControllerPlayerInY(0);
			

				if (event.key.keysym.sym == SDLK_DOWN)
					moveControllerPlayerInY(0);
				

				if (event.key.keysym.sym == SDLK_LEFT)
					moveControllerPlayerInX(0);
			
				if (event.key.keysym.sym == SDLK_RIGHT)
					moveControllerPlayerInX(0);	

				break;
			
			default:
				break;
		}
}