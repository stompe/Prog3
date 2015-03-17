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

	inline std::string getWindowTitle(){return title;}
	inline void setWindowTitle(std::string new_title){title = new_title;}

	inline Level* getWindowLevel(){return level;}
	inline void setWindowLevel(Level* new_level){level = new_level;}

	inline int getWindowWidth(){return width;}
	inline int getWindowHeight(){return height;}

	inline void setWindowWidth(int new_width){width = new_width;}
	inline void setWindowHeight(int new_height){height = new_height;}

	inline int getWindowFrameStart(){return frame_start;}
	inline int getWindowFrameEnd(){return frame_end;}
	inline int getWindowDeltaTime(){return delta_time;}

	inline void setWindowFrameStart(int new_frame_start){frame_start = new_frame_start;}
	inline void setWindowFrameEnd(int new_frame_end){frame_end = new_frame_end;}
	inline void setWindowDeltaTime(int new_delta_time){delta_time = new_delta_time;}

	inline float getWindowFrameMs(){return frame_ms;}
	inline float getWindowDelayMs(){return delay_ms;}

	inline void setWindowFrameMs(float new_frame_ms){frame_ms = new_frame_ms;}
	inline void setWindowDelayMs(float new_delay_ms){delay_ms = new_delay_ms;}

	inline SDL_Window* getWindow(){return window;}
	inline SDL_Surface* getWindowScreenSurface(){return screen_surface;}
	inline SDL_Texture* getWindowTexture(){return screen_texture;}
	inline SDL_Renderer* getWindowRenderer(){return render;}

	inline void setWindow(SDL_Window* new_window){window = new_window;}
	inline void setWindowScreenSurface(SDL_Surface* new_screen_surface){screen_surface = new_screen_surface;}
	inline void setWindowTexture(SDL_Texture* new_screen_texture){screen_texture = new_screen_texture;}
	inline void setWindowRenderer(SDL_Renderer* new_render){render = new_render;}

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
	SDL_Surface* screen_surface;
	SDL_Texture* screen_texture;
	SDL_Renderer* render;

	void init();
	void handleInput();
	void update();
	void draw();
};

#endif 	