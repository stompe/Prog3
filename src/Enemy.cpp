#include "../include/Enemy.h"

Enemy::Enemy(std::string name, int width, int height, std::string filepath, int x, int y)
:DynamicSprite(width, height, filepath, x, y)
{
	this->name = name;
}