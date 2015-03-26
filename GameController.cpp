#include "GameController.h"

	GameController::GameController(DynamicSprite* sprite) : Controller(sprite)
	{

	}

void GameController::executeControllerInput(std::vector<Sprite*> sprites)
{
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_UP))
	{
		moveControllerPlayerInY(-5);
		if(checkAllCollision(sprites))
		{
			printf("Collision top\n");
			moveControllerPlayerInY(-(-5));
		}
	}

	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_DOWN))
	{
		moveControllerPlayerInY(5);
		if(checkAllCollision(sprites))
		{
			printf("Collision bot\n");
			moveControllerPlayerInY(-(5));
		}
	}

	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_LEFT))
	{
		moveControllerPlayerInX(-5);
		if(checkAllCollision(sprites))
		{
			printf("Collision left\n");
			moveControllerPlayerInX(-(-5));
		}
	}
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_RIGHT))
	{
		moveControllerPlayerInX(5);
		if(checkAllCollision(sprites))
		{
			printf("Collision right\n");
			moveControllerPlayerInX(-(5));
		}
	}
}