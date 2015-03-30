#include "PlatformController.h"


// class to controll platforms in the game (in this case obsticles)
PlatformController::PlatformController(DynamicSprite* sprite,int speed, int max, int min, bool move_x, bool move_y) : Controller(sprite)
{
	this->speed = speed;
	this->max = max;
	this->min = min;
	this->move_x = move_x;
	this->move_y = move_y;
}

// controll the movement of the platform
void PlatformController::executeControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites)
{
	DynamicSprite* tmp = getControlledSprite();
	if(move_x)
	{
		if(tmp->getSpriteXPosition() > max || tmp->getSpriteXPosition() < min)
			speed *= (-1);

		moveControllerPlayerInX(speed);
			if(checkAllCollision(static_sprites, dynamic_sprites))
			{
				moveControllerPlayerInX((-speed));
			}
	}

	if(move_y){
		
		if(tmp->getSpriteYPosition() > max || tmp->getSpriteYPosition() < min)
			speed *= (-1);

		moveControllerPlayerInY(speed);
			if(checkAllCollision(static_sprites, dynamic_sprites))
			{
				moveControllerPlayerInY((-speed));
			}
	}
}