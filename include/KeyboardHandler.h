#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include "SDL2/SDL.h"

// A class to handle keyboard input in the game

class KeyboardHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();
	
	// functions to hadle the events and check if there are any keies pressed
	void handleKeyboardEvent();
	bool isPressed(int keyCode);
	bool isReleased(int keyCode);

private:
};

#endif