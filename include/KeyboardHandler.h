#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include "SDL2/SDL.h"

class KeyboardHandler
{
public:
	KeyboardHandler();
	~KeyboardHandler();
	void handleKeyboardEvent(SDL_Event event, int state);
	bool isPressed(int keyCode);
	bool isReleased(int keyCode);

private:
	//const Uint8 *keystate = SDL_GetKeyboardState(NULL);
};

#endif