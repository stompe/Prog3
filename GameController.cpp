#include "GameController.h"

	GameController::GameController(DynamicSprite* sprite) : Controller(sprite)
	{

	}

void GameController::executeControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites)
{
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_UP))
	{
		moveControllerPlayerInY(-4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			printf("Collision top\n");
			moveControllerPlayerInY(-(-4));
		}
	}

	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_DOWN))
	{
		moveControllerPlayerInY(4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			printf("Collision bot\n");
			moveControllerPlayerInY(-(4));
		}
	}

	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_LEFT))
	{
		moveControllerPlayerInX(-4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			printf("Collision left\n");
			moveControllerPlayerInX(-(-4));
		}
	}
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_RIGHT))
	{
		moveControllerPlayerInX(4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			printf("Collision right\n");
			moveControllerPlayerInX(-(4));
		}
	}
}