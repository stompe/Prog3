#include "include/GameEngine.h"
#include "include/DynamicSprite.h"
#include "include/Level.h"

int main(int argc, char* args[])
{
	GameEngine* gameEngine = new GameEngine("Games are awesome",640,480,60);

	Level* level = new Level("LevelOne");

	DynamicSprite* sprite = new DynamicSprite(680,480,"res/hello.bmp",-540,0);
	DynamicSprite* spritetwo = new DynamicSprite(20,20,"res/Green.bmp",300,100);
	DynamicSprite* spritethree = new DynamicSprite(20,20,"res/Green.bmp",400,200);
	DynamicSprite* spritefour = new DynamicSprite(20,20,"res/Green.bmp",300,300);
	DynamicSprite* spritefive = new DynamicSprite(20,20,"res/Green.bmp",100,400);

	level->add(sprite);
	level->add(spritetwo);
	level->add(spritethree);
	level->add(spritefour);
	level->add(spritefive);

	gameEngine->setLevel(level);

	gameEngine->run();

	delete gameEngine;

	return 0;
}