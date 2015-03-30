#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "DynamicSprite.h"


// A class to represent players in the game
// has a sprite to draw on screen and a name
class Player
{

public:

	Player(std::string player_name, DynamicSprite* player_sprite);
	~Player();


	// get and set the name of the player
	inline std::string getPlayerName(){return player_name;}
	inline void setPlayerName(std::string new_player_name){player_name = new_player_name;}

	// get and set the 2D sprite for the player
	inline DynamicSprite* getPlayerSprite(){return player_sprite;}
	inline void setPlayerSprite(DynamicSprite* new_player_sprite){player_sprite = new_player_sprite;}

private:

	std::string player_name;
	DynamicSprite* player_sprite;

};

#endif