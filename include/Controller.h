#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Player.h"
#include "SDL2/SDL.h"

class Controller
{

public:

	Controller(Player* player);
	~Controller();

	inline Player* getControllerPlayer(){return player;}
	inline void setControllerPlayer(Player* new_player){player = new_player;}

	void moveControllerPlayerInX(int xPixels);
	void moveControllerPlayerInY(int yPixels);

	void handleControllerInput(SDL_Event event);

private:

	Player* player;
};

#endif