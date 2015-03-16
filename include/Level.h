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

private:

	std::vector<DynamicSprite*> sprite_list;
	std::string level_name;
};

#endif