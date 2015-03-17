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

	void draw(SDL_Surface* screen_surface);
	void update();

	inline int getSpriteWidth(){return width;}
	inline int getSpriteHeight(){return height;}

	inline void setSpriteWidth(int new_width){width = new_width;}
	inline void setSpriteHeight(int new_height){height = new_height;}

	inline int getSpriteXPosition(){return x;}
	inline int getSpriteYPosition(){return y;}

	inline void setSpriteXPosition(int x){this->x = x;}
	inline void setSpriteYPosition(int y){this->y = y;}
	inline void setSpritePosition(int x, int y){this->x = x; this->y = y;}

	inline std::string getSpriteFilepath(){return filepath;}
	inline void setSpriteFilepath(std::string new_filepath){filepath = new_filepath;}

	inline SDL_Surface* getSpriteImage(){return image;};
	inline void setSpriteImage(SDL_Surface* new_image){image = new_image;}

private:

	int width;
	int height;

	int x;
	int y;

	std::string filepath;

	SDL_Surface* image;

};

#endif