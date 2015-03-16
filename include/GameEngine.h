#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include "SDL2/SDL.h"
#include <vector>
#include "Level.h"

class GameEngine
{
public:

	GameEngine(std::string game_title, int window_width, int window_height, int fps);
	~GameEngine();

	void run();

	inline void setLevel(Level* level){this->level = level;}

private:

	//LevelManager level_manager;
	std::string title;

	Level* level;

	int width;
	int height;

	int frames_per_second;

	int frame_start;
	int frame_end;

	int delta_time;

	float delay_ms;
	float frame_ms;

	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Texture* screen_texture;
	SDL_Renderer* render;

	void init();
	void update();
	void draw();
};

#endif 	