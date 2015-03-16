#ifndef LEVEL_H
#define LEVEL_H

#include "Sprite.h"
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
	void add(Sprite* sprite);

	inline std::string getLevelName(){return level_name;}

private:

	std::vector<Sprite*> sprite_list;
	std::string level_name;
};

#endif