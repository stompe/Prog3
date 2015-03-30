#include "../include/Player.h"

// set the sprite and name of the player
Player::Player(std::string player_name, DynamicSprite* player_sprite)
{
	this->player_name = player_name;
	this->player_sprite = player_sprite;
}

Player::~Player()
{

	printf("\nPlayer deconstructed");
}