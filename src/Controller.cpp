#include "../include/Controller.h"
#include <iostream>

Controller::Controller(Player* player)
{
	this->player = player;
	//keyHandler = new KeyboardHandler();
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
	printf("before Switch\n");
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
	executeControllerInput();
}

void Controller::executeControllerInput()
{
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	printf("start of exeConInput\n");
	if(keystate[SDL_SCANCODE_UP])
	{
		moveControllerPlayerInY(-5);
	}
	printf("after first if exi\n");
	if(keystate[SDL_SCANCODE_DOWN])
	{
		moveControllerPlayerInY(5);
	}

	if(keystate[SDL_SCANCODE_LEFT])
	{
		moveControllerPlayerInX(-5);
	}

	if(keystate[SDL_SCANCODE_RIGHT])
	{
		moveControllerPlayerInX(5);
	}
}