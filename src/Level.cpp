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

	delete controller;

	Mix_FreeMusic(music);
	music = NULL;

	sprite_list.clear();
	printf("\nLevel deconstructed");
}

void Level::handleInput()
{
	controller->handleControllerInput(sprite_list);
}

void Level::draw(SDL_Renderer* render)
{	
	background->draw(render);
	for(int i = 0; i < sprite_list.size(); i++)
	{
		sprite_list[i]->draw(render);
	}
}

void Level::update()
{
	for(int i = 0; i < sprite_list.size(); i++)
	{
		sprite_list[i]->update();
	}
}

void Level::addSprite(Sprite* sprite)
{
	sprite_list.push_back(sprite);
}

void Level::addBackground(Sprite* background)
{
	this->background = background;
}

void Level::playMusic()
{
	Mix_PlayMusic(music, 1);
}