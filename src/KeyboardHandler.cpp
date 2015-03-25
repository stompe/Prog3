#include "../include/KeyboardHandler.h"
#include <stdio.h>

KeyboardHandler::KeyboardHandler()
{
}

void KeyboardHandler::handleKeyboardEvent()
{

}

bool KeyboardHandler::isPressed(int keyCode)
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	return (keystate[keyCode] == 1);
}

bool KeyboardHandler::isReleased(int keyCode)
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	
	return (keystate[keyCode] == 0);
}