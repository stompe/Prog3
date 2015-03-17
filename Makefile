all:
	g++ include\GameEngine.h include\Level.h include\Sprite.h include\StaticSprite.h include\DynamicSprite.h
	g++ -o test.exe testmain.cpp src\GameEngine.cpp src\Level.cpp src\Sprite.cpp src\StaticSprite.cpp src\DynamicSprite.cpp -lmingw32 -lSDL2main -lSDL2