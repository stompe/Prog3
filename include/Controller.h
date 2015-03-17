#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Player.h"
class Controller
{

public:

	Controller(Player* player);
	~Controller();

	inline Player* getControllerPlayer(){return player;}
	inline void setControllerPlayer(Player* new_player){player = new_player;}

private:

	Player* player;
};

#endif