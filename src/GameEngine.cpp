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
	screenSurface = NULL;
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
	SDL_Quit();
	printf("\nWindow deconstructed");
}

void GameEngine::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize SDL_ERROR: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window 
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if(window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}
	}
	render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void GameEngine::run()
{
	init();

	bool quit = false;

	while(!quit)
	{
		frame_start = SDL_GetTicks();

		update();

		draw();

		frame_end = SDL_GetTicks();

		delay_ms = frame_ms - (frame_end - frame_start);

		if(delay_ms > 0)
		{
			SDL_Delay(delay_ms);
		}

		std::cout << delay_ms << std::endl;

		while(SDL_PollEvent(&event) != 0)
		{
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}
}

void GameEngine::update()
{
	level->update();
}

void GameEngine::draw()
{
	level->draw(screenSurface);
	screen_texture = SDL_CreateTextureFromSurface(render,screenSurface);
	//SDL_FreeSurface(screenSurface);
	SDL_SetRenderDrawColor(render, 0,255,0,255);
	SDL_RenderClear(render);
	SDL_RenderCopy(render,screen_texture,NULL,NULL);
	SDL_RenderPresent(render);
	//SDL_UpdateWindowSurface(window);
}