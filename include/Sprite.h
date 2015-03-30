#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include "SDL2/SDL.h"
#include <stdio.h>


// A class to represent 2D images on the screen in the game
// has values for position and dimensions
// and a SDL_Rect to represent bounds of the sprite
class Sprite
{

public:

	Sprite(std::string filepath, int x, int y, SDL_Renderer* render);
	~Sprite();

	// draws the sprite to the screen
	void draw(SDL_Renderer* render);

	// update the bounds of the sprite
	void update();

	// get dimensions
	inline int getSpriteWidth(){return width;}
	inline int getSpriteHeight(){return height;}

	// set dimensions
	inline void setSpriteWidth(int new_width){width = new_width;}
	inline void setSpriteHeight(int new_height){height = new_height;}

	// get positions of the sprite
	inline int getSpriteXPosition(){return x;}
	inline int getSpriteYPosition(){return y;}

	// set position of the sprite
	inline void setSpriteXPosition(int x){this->x = x;}
	inline void setSpriteYPosition(int y){this->y = y;}
	inline void setSpritePosition(int x, int y){this->x = x; this->y = y;}

	// get and set the filepath to the resource used for this sprite
	inline std::string getSpriteFilepath(){return filepath;}
	inline void setSpriteFilepath(std::string new_filepath){filepath = new_filepath;}

	// the current SDL_Texture of this sprite
	inline SDL_Texture* getSpriteTexture(){return texture;}
	inline void setSpriteTexture(SDL_Texture* new_texture){texture = new_texture;}
	
private:

	// dimensions
	int width;
	int height;

	// postions
	int x;
	int y;

	//path to resource
	std::string filepath;

	// the SDL_Texture for this sprite, used to draw sprite on screen
	SDL_Texture* texture;

	// bounds of this sprite, used when checking for collisions in the game
	SDL_Rect offset;

};

#endif