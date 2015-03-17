#ifndef LEVEL_H
#define LEVEL_H

#include "DynamicSprite.h"
#include <vector>
#include <string>
#include "SDL2/SDL.h"

class Level
{

public:

	Level(std::string level_name);
	~Level();

	void draw(SDL_Surface* screenSurface);
	void update();
	void add(DynamicSprite* sprite);

	inline std::string getLevelName(){return level_name;}
	inline void setLevelName(std::string new_level_name){level_name = new_level_name;}

	inline std::vector<DynamicSprite*> getLevelSpriteList(){return sprite_list;}
	inline void setLevelSpriteList(std::vector<DynamicSprite*> new_sprite_list){sprite_list = new_sprite_list;}

private:

	std::vector<DynamicSprite*> sprite_list;
	std::string level_name;
};

#endif