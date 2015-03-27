#include "../include/GameEngine.h"
#include <stdio.h>
#include <iostream>

SDL_Event event;

GameEngine::GameEngine(std::string game_title, int window_width, int window_height, int fps)
{
	title = game_title;
	width = window_width;
	height = window_height;
	frames_per_second = fps;

	frame_ms = 1000.0 / frames_per_second;
	window = NULL;

	if(init() == false)
	{
		printf("initialize failed!\n");
	}
}

GameEngine::~GameEngine()
{
	delete level;
	SDL_DestroyTexture(screen_texture);
	screen_texture = NULL;
	printf("\nTexture deconstructed");

	SDL_DestroyRenderer(render);
	render = NULL;
	printf("\nRenderer deconstructed");

	SDL_DestroyWindow(window);
	window = NULL;

	Mix_Quit();

	SDL_Quit();
	printf("\nWindow deconstructed");
}

bool GameEngine::init()
{
	bool successful_init = true;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize SDL_ERROR: %s\n", SDL_GetError() );
		successful_init = false;
	}
	else
	{
		//Create window 
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if(window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			successful_init = false;
		}
		if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			printf("Mixer could not be initialized! SDL_Error: %s\n", SDL_GetError());
			successful_init = false;
		}
	}

	render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if(render == NULL)
	{
		printf("Render could not be created! SDL_Error: %s\n", SDL_GetError());
		successful_init = false;
	}

	SDL_SetRenderDrawColor(render, 0,255,0,255);

	return successful_init;
}

void GameEngine::run()
{

	bool quit = false;

	while(!quit)
	{
		frame_start = SDL_GetTicks();

		handleInput();

		update();

		draw();

		frame_end = SDL_GetTicks();

		delay_ms = frame_ms - (frame_end - frame_start);

		if(delay_ms > 0)
		{
			SDL_Delay(delay_ms);
		}

		//std::cout << delay_ms << std::endl;

		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
}

void GameEngine::handleInput()
{
	level->handleInput();
}

void GameEngine::update()
{
	level->update(gravity);
}

void GameEngine::draw()
{
	SDL_SetWindowTitle(window, level->getLevelName().c_str());
	SDL_RenderClear(render);
	level->draw(render);
	SDL_RenderPresent(render);
}