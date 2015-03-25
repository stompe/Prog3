#ifndef ENEMY_H
#define ENEMY_H

#include "DynamicSprite.h"

class Enemy : DynamicSprite
{
public:
	Enemy(std::string name, std::string filepath, int x, int y, SDL_Renderer* render);
	~Enemy();

private:
	std::string name;
};
#endif