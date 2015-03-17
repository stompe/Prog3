#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "DynamicSprite.h"

class Player
{

public:

	Player(std::string player_name, DynamicSprite* player_sprite);
	~Player();

	inline std::string getPlayerName(){return player_name;}
	inline void setPlayerName(std::string new_player_name){player_name = new_player_name;}

	inline DynamicSprite* getPlayerSprite(){return player_sprite;}
	inline void setPlayerSprite(DynamicSprite* new_player_sprite){player_sprite = new_player_sprite;}

private:

	std::string player_name;
	DynamicSprite* player_sprite;

};

#endif