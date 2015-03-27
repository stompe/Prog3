#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "include/Controller.h"
#include "include/StaticSprite.h"

class GameController : public Controller
{
public:
	GameController(DynamicSprite* sprite);

	void executeControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites);

private:
	
};

#endif