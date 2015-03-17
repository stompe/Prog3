#include "include/GameEngine.h"
#include "include/DynamicSprite.h"
#include "include/Level.h"
#include "include/Player.h"
#include "include/Controller.h"

int main(int argc, char* args[])
{
	GameEngine* gameEngine = new GameEngine("Games are awesome",640,480,60);

	Level* level = new Level("LevelOne");

	DynamicSprite* sprite = new DynamicSprite(680,480,"res/hello.bmp",0,0);
	DynamicSprite* spritetwo = new DynamicSprite(20,20,"res/Green.bmp",300,100);
	DynamicSprite* spritethree = new DynamicSprite(20,20,"res/Green.bmp",400,200);
	DynamicSprite* spritefour = new DynamicSprite(20,20,"res/Green.bmp",300,300);
	DynamicSprite* spritefive = new DynamicSprite(20,20,"res/Green.bmp",100,400);

	Player* player_one = new Player("Adam",spritetwo);

	Controller* controller = new Controller(player_one);

	level->setLevelController(controller);

	level->add(sprite);
	level->add(player_one->getPlayerSprite());
	level->add(spritethree);
	level->add(spritefour);
	level->add(spritefive);

	gameEngine->setWindowLevel(level);

	gameEngine->run();

	delete gameEngine;

	return 0;
}