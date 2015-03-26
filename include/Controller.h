#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Player.h"
#include "SDL2/SDL.h"
#include "KeyboardHandler.h"
#include "SDL2/SDL_mixer.h"
#include <vector>

class Controller
{

public:

	Controller(DynamicSprite* controlled_sprite);
	~Controller();

	inline DynamicSprite* getControlledSprite(){return controlled_sprite;}
	inline void setControllerPlayer(DynamicSprite* new_controlled_sprite){controlled_sprite = new_controlled_sprite;}

	void moveControllerPlayerInX(int xPixels);
	void moveControllerPlayerInY(int yPixels);

	void handleControllerInput(std::vector<Sprite*> sprites);

	bool checkAllCollision(std::vector<Sprite*> sprites);
	bool checkCollision(SDL_Rect rectA, SDL_Rect rectB);

	inline KeyboardHandler* getKeyboardHandler(){return keyboard_handler;}

	virtual void executeControllerInput(std::vector<Sprite*> sprites);
	
private:

	DynamicSprite* controlled_sprite;
	KeyboardHandler* keyboard_handler;

};

#endif