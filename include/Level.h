#ifndef LEVEL_H
#define LEVEL_H

#include "DynamicSprite.h"
#include "StaticSprite.h"
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

	void handleInput();
	void draw(SDL_Renderer* render);
	void update(int gravity);
	void addSprite(Sprite* sprite);
	void addBackground(Sprite* background);
	void playMusic();
	void stopMusic();

	inline std::string getLevelName(){return level_name;}
	inline void setLevelName(std::string new_level_name){level_name = new_level_name;}

	inline Sprite* getLevelBackground(){return background;}
	inline void setLevelBackground(Sprite* new_background){background = new_background;}

	inline std::vector<StaticSprite*> getLevelStaticSpriteList(){return static_sprite_list;}
	inline std::vector<DynamicSprite*> getLevelDynamicSpriteList(){return dynamic_sprite_list;}

	inline void addStaticSprite(StaticSprite* new_static_sprite){static_sprite_list.push_back(new_static_sprite);}
	inline void addDynamicSprite(DynamicSprite* new_dynamic_sprite){dynamic_sprite_list.push_back(new_dynamic_sprite);}

	inline void setLevelStaticSpriteList(std::vector<StaticSprite*> new_static_sprite_list){static_sprite_list = new_static_sprite_list;}
	inline void setLevelDynamicSpriteList(std::vector<DynamicSprite*> new_dynamic_sprite_list){dynamic_sprite_list = new_dynamic_sprite_list;}
	
	inline Controller* getLevelController(){return controller;}
	inline void setLevelController(Controller* new_controller){controller = new_controller;}

	inline Mix_Music* getLevelMusic(){return music;}
	inline void setLevelMusic(Mix_Music* new_music){music = new_music;}

private:

	std::vector<StaticSprite*> static_sprite_list;
	std::vector<DynamicSprite*> dynamic_sprite_list;
	std::string level_name;
	Controller* controller;
	Sprite* background;
	Mix_Music* music;
};

#endif