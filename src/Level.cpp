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

void Level::draw(SDL_Surface* screenSurface)
{
	for(int i = 0; i < sprite_list.size(); i++)
	{
		sprite_list[i]->draw(screenSurface);
	}
}

void Level::update()
{
	for(int i = 0; i < sprite_list.size(); i++)
	{
		sprite_list[i]->tick();
	}
}

void Level::add(Sprite* sprite)
{
	sprite_list.push_back(sprite);
}