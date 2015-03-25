#include "../include/Enemy.h"

Enemy::Enemy(std::string name, std::string filepath, int x, int y, SDL_Renderer* render)
:DynamicSprite(filepath, x, y, render)
{
	this->name = name;
}