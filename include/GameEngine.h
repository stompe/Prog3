#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <string>
#include "SDL2/SDL.h"
#include <vector>
#include "Level.h"

//Class GameEngine is the class running the game loop, initializing SDL2 and sends calls to the current level.
class GameEngine
{
public:

	GameEngine(std::string game_title, int window_width, int window_height, int fps);
	~GameEngine();

	void run();

	//Get and set functions for the window title
	inline std::string getWindowTitle(){return title;}
	inline void setWindowTitle(std::string new_title){title = new_title;}

	//Get and set functions for the current level of the window
	inline Level* getWindowLevel(){return level;}
	inline void setWindowLevel(Level* new_level){level = new_level;}

	//Get functions for both the windows width and height
	inline int getWindowWidth(){return width;}
	inline int getWindowHeight(){return height;}

	//Set functions for both the windows width and height
	inline void setWindowWidth(int new_width){width = new_width;}
	inline void setWindowHeight(int new_height){height = new_height;}

	//Get functions for values of frame_start, frame_end and delta_time
	inline int getWindowFrameStart(){return frame_start;}
	inline int getWindowFrameEnd(){return frame_end;}
	inline int getWindowDeltaTime(){return delta_time;}

	//Set functions for values of frame_start, frame_end and delta_time
	inline void setWindowFrameStart(int new_frame_start){frame_start = new_frame_start;}
	inline void setWindowFrameEnd(int new_frame_end){frame_end = new_frame_end;}
	inline void setWindowDeltaTime(int new_delta_time){delta_time = new_delta_time;}

	//Get functions for values of frame_ms and delay_ms
	inline float getWindowFrameMs(){return frame_ms;}
	inline float getWindowDelayMs(){return delay_ms;}

	//Get and set functions for gravity variable affecting DynamicSprites
	inline int getGravity(){return gravity;};
	inline int setGravity(int gravity){this->gravity = gravity;}

	//Set functions for variables frame_ms and delay_ms
	inline void setWindowFrameMs(float new_frame_ms){frame_ms = new_frame_ms;}
	inline void setWindowDelayMs(float new_delay_ms){delay_ms = new_delay_ms;}

	//Get functions for window and renderer
	inline SDL_Window* getWindow(){return window;}
	inline SDL_Renderer* getWindowRenderer(){return render;}

	//Set functions for window and renderer
	inline void setWindow(SDL_Window* new_window){window = new_window;}
	inline void setWindowRenderer(SDL_Renderer* new_render){render = new_render;}

private:
	//Caption of the window
	std::string title;

	//Level being played in the window
	Level* level;

	//Dimensions of the application window
	int width;
	int height;

	//Requested framerate of the application
	int frames_per_second;

	//Variables used to calculate time elapsed in one frame
	int frame_start;
	int frame_end;

	//To be used for calculations over time, not yet implemented
	int delta_time;

	//Variables for time elapsed in a frame and time to be delayed in a frame
	float delay_ms;
	float frame_ms;

	//Gravity variable
	int gravity;

	//SDL_Window and SDL_Renderer used in the application
	SDL_Window* window;
	SDL_Renderer* render;

	//initialization, input, update and draw functions used throuout the applications
	bool init();
	void handleInput();
	void update();
	void draw();
};

#endif 	