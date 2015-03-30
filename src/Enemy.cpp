#include "../include/Enemy.h"

// A very basic class for enemies to implement from

Enemy::Enemy(std::string name, std::string filepath, int x, int y, SDL_Renderer* render)
:DynamicSprite(filepath, x, y, render)
{
	this->name = name;
}