#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Player.h"
#include "StaticSprite.h"
#include "SDL2/SDL.h"
#include "KeyboardHandler.h"
#include "SDL2/SDL_mixer.h"
#include <vector>

// A class to controll dynamic sprites in the game
// can implement for both players and AI

class Controller
{

public:

	Controller(DynamicSprite* controlled_sprite);
	~Controller();

	// functions to get the controlled sprite and to set it for the controller
	inline DynamicSprite* getControlledSprite(){return controlled_sprite;}
	inline void setControllerPlayer(DynamicSprite* new_controlled_sprite){controlled_sprite = new_controlled_sprite;}


	//Functions to move the sprite in x and y
	void moveControllerPlayerInX(int xPixels);
	void moveControllerPlayerInY(int yPixels);

	//Handles input if any is needed and calls for collision check
	void handleControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites);

	// check if the sprite collided with any object
	bool checkAllCollision(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites);
	bool checkCollision(SDL_Rect rectA, SDL_Rect rectB);

	// handles the input for this controller
	inline KeyboardHandler* getKeyboardHandler(){return keyboard_handler;}

	// function to implement in sub-classes that executes the input
	virtual void executeControllerInput(std::vector<StaticSprite*> static_sprites, std::vector<DynamicSprite*> dynamic_sprites);
	
private:

	// the sprite that this controller controls
	DynamicSprite* controlled_sprite;

	// handles the keyboard input
	KeyboardHandler* keyboard_handler;

};

#endif