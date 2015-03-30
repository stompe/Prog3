#ifndef STATICSPRITE_H
#define STATICSPRITE_H
#include "Sprite.h"

// A class to represent sprites that cant move in the game

class StaticSprite : public Sprite
{

public:

	StaticSprite(std::string filepath, int x, int y, SDL_Renderer* render);

private:

};

#endif