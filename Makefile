all:
	g++ include\GameEngine.h include\Level.h include\Sprite.h include\StaticSprite.h include\DynamicSprite.h include\Enemy.h include\Player.h include\Controller.h
	g++ -o test.exe testmain.cpp src\GameEngine.cpp src\Level.cpp src\Sprite.cpp src\StaticSprite.cpp src\DynamicSprite.cpp src\Enemy.cpp src\Player.cpp src\Controller.cpp -lmingw32 -lSDL2main -lSDL2