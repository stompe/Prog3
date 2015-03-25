#ifndef LEVEL_H
#define LEVEL_H

#include "DynamicSprite.h"
#include "Player.h"
#include "Controller.h"
#include <vector>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

class Level
{

public:

	Level(std::string level_name);
	~Level();

	void handleInput(SDL_Event event);
	void draw(SDL_Renderer* render);
	void update();
	void add(DynamicSprite* sprite);
	void addBackground(Sprite* background);
	void playMusic();
	void stopMusic();

	inline std::string getLevelName(){return level_name;}
	inline void setLevelName(std::string new_level_name){level_name = new_level_name;}
	inline Sprite* getLevelBackground(){return background;}
	inline std::vector<DynamicSprite*> getLevelSpriteList(){return sprite_list;}
	inline void setLevelSpriteList(std::vector<DynamicSprite*> new_sprite_list){sprite_list = new_sprite_list;}

	inline void setLevelController(Controller* new_controller){controller = new_controller;}

private:

	std::vector<DynamicSprite*> sprite_list;
	std::string level_name;
	Controller* controller;
	Sprite* background;
	Mix_Music* music;
};

#endif