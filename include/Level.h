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

// A class to represent levels in the game
// keeps track of all sprites in the level and all the controllers
// plays sounds and music


class Level
{

public:

	Level(std::string level_name);
	~Level();

	// function to handle input for the level
	void handleInput();

	// draws every asset for this level
	void draw(SDL_Renderer* render);

	// calculate all updates in the level for alla sprites and implement gravity
	void update(int gravity);

	// adds a sprite to the level
	void addSprite(Sprite* sprite);

	// add a sprite to represent the background to the level
	void addBackground(Sprite* background);

	// controll music in the level
	void playMusic();
	void stopMusic();


	// get and set the name of the level
	inline std::string getLevelName(){return level_name;}
	inline void setLevelName(std::string new_level_name){level_name = new_level_name;}

	// get and set the background for the level
	inline Sprite* getLevelBackground(){return background;}
	inline void setLevelBackground(Sprite* new_background){background = new_background;}

	// get the lists of static- and dynamicsprites in the level
	inline std::vector<StaticSprite*> getLevelStaticSpriteList(){return static_sprite_list;}
	inline std::vector<DynamicSprite*> getLevelDynamicSpriteList(){return dynamic_sprite_list;}

	// add a sprite to the level (static or dynamic)
	inline void addStaticSprite(StaticSprite* new_static_sprite){static_sprite_list.push_back(new_static_sprite);}
	inline void addDynamicSprite(DynamicSprite* new_dynamic_sprite){dynamic_sprite_list.push_back(new_dynamic_sprite);}

	// set the current list of static or dynamic sprites to the list given as parameter
	inline void setLevelStaticSpriteList(std::vector<StaticSprite*> new_static_sprite_list){static_sprite_list = new_static_sprite_list;}
	inline void setLevelDynamicSpriteList(std::vector<DynamicSprite*> new_dynamic_sprite_list){dynamic_sprite_list = new_dynamic_sprite_list;}
	
	// get all the controllers for the level
	inline std::vector<Controller*> getLevelControllers(){return controller_list;}

	// add a new controller to the level
	inline void addLevelController(Controller* new_controller){controller_list.push_back(new_controller);}

	// get and set the current music for the level
	inline Mix_Music* getLevelMusic(){return music;}
	inline void setLevelMusic(Mix_Music* new_music){music = new_music;}

private:

	// lists of all the different sprites in the level
	std::vector<StaticSprite*> static_sprite_list;
	std::vector<DynamicSprite*> dynamic_sprite_list;

	// list of all the controllers in the level
	std::vector<Controller*> controller_list;

	// the levels name
	std::string level_name;

	// the sprite that represents the background in the level
	Sprite* background;

	// the current music in the level
	Mix_Music* music;
};

#endif