#include "../include/Level.h"

Level::Level(std::string level_name)
{
	this->level_name = level_name;
}

Level::~Level()
{
	for(int i = 0; i < static_sprite_list.size(); i++)
	{
		delete static_sprite_list[i];
	}

	for(int i = 0; i < dynamic_sprite_list.size(); i++)
	{
		delete dynamic_sprite_list[i];
	}

	delete controller;

	Mix_FreeMusic(music);
	music = NULL;

	static_sprite_list.clear();
	dynamic_sprite_list.clear();
	printf("\nLevel deconstructed");
}

void Level::handleInput()
{
	controller->handleControllerInput(static_sprite_list, dynamic_sprite_list);
}

void Level::draw(SDL_Renderer* render)
{	
	background->draw(render);
	for(int i = 0; i < static_sprite_list.size(); i++)
	{
		static_sprite_list[i]->draw(render);
	}

	for(int i = 0; i < dynamic_sprite_list.size(); i++)
	{
		dynamic_sprite_list[i]->draw(render);
	}

}

void Level::update(int gravity)
{
	for(int i = 0; i < static_sprite_list.size(); i++)
	{
		static_sprite_list[i]->update();
	}

	for(int i = 0; i < dynamic_sprite_list.size(); i++)
	{
		dynamic_sprite_list[i]->update(gravity);
		if(dynamic_sprite_list[i] == controller->getControlledSprite())
		{
			if(controller->checkAllCollision(static_sprite_list, dynamic_sprite_list))
				controller->getControlledSprite()->update(-gravity);
		}
	}
}



void Level::addBackground(Sprite* background)
{
	this->background = background;
}

void Level::playMusic()
{
	Mix_PlayMusic(music, 1);
}