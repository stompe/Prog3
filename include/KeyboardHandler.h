#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include "SDL2/SDL.h"

class KeyboardHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();
	void handleKeyboardEvent();
	bool isPressed(int keyCode);
	bool isReleased(int keyCode);

private:
};

#endif