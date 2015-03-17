#include "../include/Level.h"

Level::Level(std::string level_name)
{
	this->level_name = level_name;
}

Level::~Level()
{
	for(int i = 0; i < sprite_list.size(); i++)
	{
		delete sprite_list[i];
	}

	sprite_list.clear();
	printf("\nLevel deconstructed");
}

void Level::draw(SDL_Surface* screen_surface)
{
	for(int i = 0; i < sprite_list.size(); i++)
	{
		sprite_list[i]->draw(screen_surface);
	}
}

void Level::update()
{
	for(int i = 0; i < sprite_list.size(); i++)
	{
		sprite_list[i]->update();
	}
}

void Level::add(DynamicSprite* sprite)
{
	sprite_list.push_back(sprite);
}