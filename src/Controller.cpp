#include "../include/Controller.h"

Controller::Controller(Player* player)
{
	this->player = player;
}

Controller::~Controller()
{
	delete player;
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
		if (event.key.keysym.sym == SDLK_UP)
			moveControllerPlayerInY(-5);
		

		if (event.key.keysym.sym == SDLK_DOWN)
			moveControllerPlayerInY(5);
		

		if (event.key.keysym.sym == SDLK_LEFT)
			moveControllerPlayerInX(-5);
		
		if (event.key.keysym.sym == SDLK_RIGHT)
			moveControllerPlayerInX(5);	
}