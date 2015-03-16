#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include "SDL2/SDL.h"
#include <stdio.h>

class Sprite
{

public:

	Sprite(int width, int height, std::string filepath, int x, int y);
	~Sprite();

	void draw(SDL_Surface* screenSurface);
	void tick();

	inline std::string getFilepath(){return filepath;}

	inline int getWidth(){return width;}
	inline int getHeight(){return height;}

	inline int getXPosition(){return x;}
	inline int getYPosition(){return y;}

	inline void setXPosition(int x){this->x = x;}
	inline void setYPosition(int y){this->y = y;}
	inline void setPosition(int x, int y){this->x = x; this->y = y;}

	SDL_Surface* getImage();

private:

	int width;
	int height;

	int x;
	int y;

	std::string filepath;

	SDL_Surface* image;

};

#endif