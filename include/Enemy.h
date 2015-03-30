#ifndef ENEMY_H
#define ENEMY_H

#include "DynamicSprite.h"


// A class to represent enemies in the game

class Enemy : DynamicSprite
{
public:
	Enemy(std::string name, std::string filepath, int x, int y, SDL_Renderer* render);
	~Enemy();

	// functions to get the name and set it for the enemy
	inline std::string getEnemyName(){return name;}
	inline void setEnemyName(std::string new_name){name = new_name;}
	
private:

	// the name of the enemy
	std::string name;
};
#endif