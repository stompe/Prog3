#ifndef PLATFORMCONTROLLER_H
#define PLATFORMCONTROLLER_H

#include "include/Controller.h"
#include "include/StaticSprite.h"


// class to controll platforms in the game
// they can move in x or y
// and they have a min and max position to move between
class PlatformController : public Controller
{
public:
	PlatformController(DynamicSprite* sprite,int speed, int max, int min,bool move_x, bool move_y);

	void executeControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites);

private:
	int speed;
	int max;
	int min;
	bool move_x;
	bool move_y;
	
};

#endif