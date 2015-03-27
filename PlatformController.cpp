#include "PlatformController.h"

	PlatformController::PlatformController(DynamicSprite* sprite,int speed, int max, int min, bool move_x, bool move_y) : Controller(sprite)
	{
		this->speed = speed;
		this->max = max;
		this->min = min;
		this->move_x = move_x;
		this->move_y = move_y;
	}

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

	moveControllerPlayerInY(-2);
}