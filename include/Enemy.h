#ifndef ENEMY_H
#define ENEMY_H

#include "DynamicSprite.h"

class Enemy : DynamicSprite
{
public:
	Enemy(std::string name, int widht, int height, std::string filepath, int x, int y );
	~Enemy();

private:
	std::string name;
};
#endif