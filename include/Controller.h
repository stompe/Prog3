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

	Controller(Player* player);
	~Controller();

	inline Player* getControllerPlayer(){return player;}
	inline void setControllerPlayer(Player* new_player){player = new_player;}

	void moveControllerPlayerInX(int xPixels);
	void moveControllerPlayerInY(int yPixels);

	void handleControllerInput(SDL_Event event, std::vector<DynamicSprite*> sprites);

	bool checkAllCollision(std::vector<DynamicSprite*> sprites);
	bool checkCollision(SDL_Rect rectA, SDL_Rect rectB);


private:

	Player* player;
	KeyboardHandler* keyboard_handler;
	Mix_Chunk* sound;

	void executeControllerInput(std::vector<DynamicSprite*> sprites);
};

#endif