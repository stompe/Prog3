#include "../include/Player.h"

Player::Player(std::string player_name, DynamicSprite* player_sprite)
{
	this->player_name = player_name;
	this->player_sprite = player_sprite;
}

Player::~Player()
{
	delete player_sprite;
}