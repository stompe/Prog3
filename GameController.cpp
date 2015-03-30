#include "GameController.h"

	GameController::GameController(DynamicSprite* sprite) : Controller(sprite)
	{

	}

// function implemented to handle input for the player
void GameController::executeControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites)
{	
	// move up
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_UP))
	{
		moveControllerPlayerInY(-4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			delete this;
		}
	}

	// move down
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_DOWN))
	{
		moveControllerPlayerInY(4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			delete this;
		}
	}

	// move left
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_LEFT))
	{
		moveControllerPlayerInX(-4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			delete this;
		}
	}

	// move right
	if(getKeyboardHandler()->isPressed(SDL_SCANCODE_RIGHT))
	{
		moveControllerPlayerInX(4);
		if(checkAllCollision(static_sprites, dynamic_sprites))
		{
			delete this;
		}
	}
}