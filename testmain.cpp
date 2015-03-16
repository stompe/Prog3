#include "include/GameEngine.h"
#include "include/StaticSprite.h"
#include "include/Level.h"

int main(int argc, char* args[])
{
	GameEngine* gameEngine = new GameEngine("Games are awesome",640,480,60);

	Level* level = new Level("LevelOne");

	Sprite* sprite = new Sprite(0,0,"res/hello.bmp",0,0);
	Sprite* spritetwo = new Sprite(0,0,"res/Green.bmp",300,300);
	Sprite* spritethree = new Sprite(0,0,"res/Green.bmp",400,300);
	Sprite* spritefour = new Sprite(0,0,"res/Green.bmp",300,400);
	Sprite* spritefive = new Sprite(0,0,"res/Green.bmp",100,300);

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