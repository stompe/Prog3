#ifndef ENEMY_H
#define ENEMY_H

#include "DynamicSprite.h"

class Enemy : DynamicSprite
{
public:
	Enemy(std::string name, std::string filepath, int x, int y, SDL_Renderer* render);
	~Enemy();

	inline std::string getEnemyName(){return name;}
	inline void setEnemyName(std::string new_name){name = new_name;}
	
private:
	std::string name;
};
#endif