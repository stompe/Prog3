#include "../include/Controller.h"

Controller::Controller(Player* player)
{
	this->player = player;
}

Controller::~Controller()
{
	delete player;
}