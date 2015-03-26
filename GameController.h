#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "include/Controller.h"

class GameController : public Controller
{
public:
	GameController(DynamicSprite* sprite);

	//using Controller::executeControllerInput;
	void executeControllerInput(std::vector<Sprite*> sprites);

private:
};

#endif