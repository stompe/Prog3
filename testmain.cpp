#include "include/GameEngine.h"
#include "include/DynamicSprite.h"
#include "include/Level.h"
#include "include/Player.h"
#include "GameController.h"
#include "PlatformController.h"
#include <iostream>

int main(int argc, char* args[])
{
	int gravity = 0; 

	GameEngine* gameEngine = new GameEngine("Games are awesome",640,480,60);
	gameEngine->setGravity(gravity);


	Level* level = new Level("LevelOne");
	SDL_Renderer* render = gameEngine->getWindowRenderer();
	Sprite* background = new Sprite("res/background.bmp",0,0,render);


	DynamicSprite* pSprite = new DynamicSprite("res/Player.bmp",300,200,render);

	//Create the sprites for the level
	DynamicSprite* sprite1 = new DynamicSprite("res/Green.bmp",80,100,render);
	DynamicSprite* sprite2 = new DynamicSprite("res/Green.bmp",150,50,render);
	DynamicSprite* sprite3 = new DynamicSprite("res/Enemy.bmp",500,200,render);
	DynamicSprite* sprite4 = new DynamicSprite("res/Green.bmp",400,300,render);
	DynamicSprite* sprite5 = new DynamicSprite("res/Green.bmp",140,280,render);
	DynamicSprite* sprite6 = new DynamicSprite("res/Enemy.bmp",500,80,render);
	DynamicSprite* sprite7 = new DynamicSprite("res/Enemy.bmp",80,400,render);
	DynamicSprite* sprite8 = new DynamicSprite("res/Green.bmp",320,150,render);
	DynamicSprite* sprite9 = new DynamicSprite("res/Enemy.bmp",600,200,render);
	DynamicSprite* sprite10 = new DynamicSprite("res/Green.bmp",600,350,render);
	DynamicSprite* sprite11 = new DynamicSprite("res/Green.bmp",500,175,render);
	DynamicSprite* sprite12 = new DynamicSprite("res/Green.bmp",480, 60,render);
	DynamicSprite* sprite13 = new DynamicSprite("res/Enemy.bmp",340, 50,render);
	DynamicSprite* sprite14 = new DynamicSprite("res/Green.bmp",90,340,render);
	DynamicSprite* sprite15 = new DynamicSprite("res/Enemy.bmp",175,200,render);


	//create static sprites for the topp and bottom
	StaticSprite* ground = new StaticSprite("res/mark.bmp",0,440,render);
	StaticSprite* top = new StaticSprite("res/mark.bmp",0,0,render);


	Player* player_one = new Player("Adam",pSprite);
	GameController* controller = new GameController(player_one->getPlayerSprite());
	
	std::vector<PlatformController*> platforms;

	//Create platforms
	PlatformController* platform1 = new PlatformController(sprite1,4,350,40,true,false);
	PlatformController* platform2 = new PlatformController(sprite2,3,200,40,false,true);
	PlatformController* platform3 = new PlatformController(sprite3,3,560,380,true,false);
	PlatformController* platform4 = new PlatformController(sprite4,5,500,250,true,true);
	PlatformController* platform5 = new PlatformController(sprite5,2,350,80,true,false);
	PlatformController* platform6 = new PlatformController(sprite6,3,600,250,true,false);
	PlatformController* platform7 = new PlatformController(sprite7,4,400,80,true,true);
	PlatformController* platform8 = new PlatformController(sprite8,5,450,200,true,false);
	PlatformController* platform9 = new PlatformController(sprite9,3,640,350,true,true);
	PlatformController* platform10 = new PlatformController(sprite10,2,600,250,true,true);
	PlatformController* platform11 = new PlatformController(sprite11,3,350,100,false,true);
	PlatformController* platform12 = new PlatformController(sprite12,2,500,250,true,false);
	PlatformController* platform13 = new PlatformController(sprite13,3,350,40,true,true);
	PlatformController* platform14 = new PlatformController(sprite14,2,360,100,false,true);
	PlatformController* platform15 = new PlatformController(sprite15,4,550,80,true,true);


	//Add platforms to vector
	platforms.push_back(platform1);
	platforms.push_back(platform2);
	platforms.push_back(platform3);
	platforms.push_back(platform4);
	platforms.push_back(platform5);
	platforms.push_back(platform6);
	platforms.push_back(platform7);
	platforms.push_back(platform8);
	platforms.push_back(platform9);
	platforms.push_back(platform10);
	platforms.push_back(platform11);
	platforms.push_back(platform12);
	platforms.push_back(platform13);
	platforms.push_back(platform14);
	platforms.push_back(platform15);
	


	level->addLevelController(controller);

	level->addBackground(background);
	level->addDynamicSprite(player_one->getPlayerSprite());
	


	//Add all platforms to level
	for(int i = 0; i < platforms.size(); i++)
	{
		level->addLevelController(platforms[i]);
	}
	
	level->addDynamicSprite(sprite1);
	level->addDynamicSprite(sprite2);
	level->addDynamicSprite(sprite3);
	level->addDynamicSprite(sprite4);
	level->addDynamicSprite(sprite5);
	level->addDynamicSprite(sprite6);
	level->addDynamicSprite(sprite7);
	level->addDynamicSprite(sprite8);
	level->addDynamicSprite(sprite9);
	level->addDynamicSprite(sprite10);
	level->addDynamicSprite(sprite11);
	level->addDynamicSprite(sprite12);
	level->addDynamicSprite(sprite13);
	level->addDynamicSprite(sprite14);
	level->addDynamicSprite(sprite15);
	//level->addStaticSprite(staticSprite);
	//level->addStaticSprite(spritefive);
	level->addStaticSprite(ground);
	level->addStaticSprite(top);

	std::cout << ground->getSpriteWidth() << " - " << ground->getSpriteHeight() << std::endl;

	gameEngine->setWindowLevel(level);

	gameEngine->run();

	delete gameEngine;

	return 0;
}