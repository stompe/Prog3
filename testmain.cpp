#include "include/GameEngine.h"
#include "include/DynamicSprite.h"
#include "include/Level.h"
#include "include/Player.h"
#include "GameController.h"

int main(int argc, char* args[])
{
	GameEngine* gameEngine = new GameEngine("Games are awesome",640,480,60);

	Level* level = new Level("LevelOne");
	SDL_Renderer* render = gameEngine->getWindowRenderer();
	Sprite* background = new Sprite("res/hello.bmp",0,0,render);
	DynamicSprite* spritetwo = new DynamicSprite("res/Green.bmp",300,100,render);
	DynamicSprite* spritethree = new DynamicSprite("res/Green.bmp",400,200,render);
	DynamicSprite* spritefour = new DynamicSprite("res/Green.bmp",300,300,render);
	DynamicSprite* spritefive = new DynamicSprite("res/Green.bmp",100,400,render);

	Player* player_one = new Player("Adam",spritetwo);

	GameController* controller = new GameController(player_one->getPlayerSprite());

	level->setLevelController(controller);

	level->addBackground(background);
	level->addSprite(player_one->getPlayerSprite());
	level->addSprite(spritethree);
	level->addSprite(spritefour);
	level->addSprite(spritefive);

	gameEngine->setWindowLevel(level);

	gameEngine->run();

	delete gameEngine;

	return 0;
}