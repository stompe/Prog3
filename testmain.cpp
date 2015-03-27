#include "include/GameEngine.h"
#include "include/DynamicSprite.h"
#include "include/Level.h"
#include "include/Player.h"
#include "GameController.h"
#include "PlatformController.h"
#include <iostream>

int main(int argc, char* args[])
{
	int gravity = 2; 

	GameEngine* gameEngine = new GameEngine("Games are awesome",640,480,60);
	gameEngine->setGravity(gravity);


	Level* level = new Level("LevelOne");
	SDL_Renderer* render = gameEngine->getWindowRenderer();
	Sprite* background = new Sprite("res/background.bmp",0,0,render);
	DynamicSprite* spritetwo = new DynamicSprite("res/Green.bmp",300,100,render);
	DynamicSprite* spritethree = new DynamicSprite("res/Green.bmp",400,200,render);
	StaticSprite* spritefour = new StaticSprite("res/Green.bmp",300,300,render);
	//StaticSprite* spritefive = new StaticSprite("res/Green.bmp",100,400,render);
	StaticSprite* ground = new StaticSprite("res/mark.bmp",0,440,render);

	Player* player_one = new Player("Adam",spritetwo);

	GameController* controller = new GameController(player_one->getPlayerSprite());
	PlatformController* platform = new PlatformController(spritethree,2,600,100,true,false);

	level->setLevelController(platform);

	level->addBackground(background);
	level->addDynamicSprite(player_one->getPlayerSprite());
	level->addDynamicSprite(spritethree);
	level->addStaticSprite(spritefour);
	//level->addStaticSprite(spritefive);
	level->addStaticSprite(ground);

	std::cout << ground->getSpriteWidth() << " - " << ground->getSpriteHeight() << std::endl;

	gameEngine->setWindowLevel(level);

	gameEngine->run();

	delete gameEngine;

	return 0;
}