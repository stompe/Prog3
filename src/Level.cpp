#include "../include/Level.h"

Level::Level(std::string level_name)
{
	this->level_name = level_name;
	music = Mix_LoadMUS("res/song.wav");
}


// release all resources of the level
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

	for(int i = 0; i < controller_list.size(); i++)
	{
		delete controller_list[i];
	}

	Mix_FreeMusic(music);
	music = NULL;

	static_sprite_list.clear();
	dynamic_sprite_list.clear();
	controller_list.clear();
	printf("\nLevel deconstructed");
}


// handle input for the level every frame
void Level::handleInput()
{
	
	for(int i = 0; i < controller_list.size(); i++)
	{
		controller_list[i]->handleControllerInput(static_sprite_list, dynamic_sprite_list);
	}

}


// draw the assets in the level to the screen
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

// calculate positions of all assets in the level and effekt them with gravity
void Level::update(int gravity)
{
	for(int i = 0; i < static_sprite_list.size(); i++)
	{
		static_sprite_list[i]->update();
	}

	for(int i = 0; i < dynamic_sprite_list.size(); i++)
	{
		dynamic_sprite_list[i]->update(gravity);
	}
}


// add a background to the level
void Level::addBackground(Sprite* background)
{
	this->background = background;
}

// play the music of the level
void Level::playMusic()
{
	Mix_PlayMusic(music, 1);
}