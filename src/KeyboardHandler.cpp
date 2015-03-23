#include "../include/KeyboardHandler.h"
#include <stdio.h>

KeyboardHandler::KeyboardHandler()
{
}

void KeyboardHandler::handleKeyboardEvent(SDL_Event event, int state)
{
	//keystate[event.key.keysym.sym] = state;
	/**
	if(keyCode > 0 && keyCode < 256)
	{
		return keyState[keyCode];
	}
	return false;
	*/
}

bool KeyboardHandler::isPressed(int keyCode)
{
	//return (keystate[keyCode] == 1);
	return false;
}

bool KeyboardHandler::isReleased(int keyCode)
{
	//return (keystate[keyCode] == 0);
	return false;
}