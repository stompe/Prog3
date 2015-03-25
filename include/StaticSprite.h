#ifndef STATICSPRITE_H
#define STATICSPRITE_H
#include "Sprite.h"

class StaticSprite : public Sprite
{

public:

	StaticSprite(std::string filepath, int x, int y, SDL_Renderer* render);

private:

};

#endif