#include "core_engine.h"

#include <sstream>
using std::stringstream;
using std::string;

Entity player;

bool MOVE_UP=false, MOVE_DOWN=false, MOVE_LEFT=false, MOVE_RIGHT=false;

Engine::Engine(string path, int width, int height)
{
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		output("[!!!] Failed to initialize SDL.");
		return;
	}

    window = SDL_CreateWindow(path.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window==NULL)
	{
		output("[!!!] Failed to initialize window.");
		return;
	}
	screen = SDL_GetWindowSurface(window);
}
Engine::~Engine()
{
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Engine::init()
{
	while(IS_RUNNING)
	{
		//Get events
		getEvents();
		//Do logic
		double speed = 2.5;
		if(MOVE_UP) player.shift(0, -speed);
		if(MOVE_DOWN) player.shift(0, speed);
		if(MOVE_LEFT) player.shift(-speed, 0);
		if(MOVE_RIGHT) player.shift(speed, 0);
		//Render
		render();
	}
}

void Engine::render()
{
	clearScreen();
	int len = world.size();
	for(int i=0; i<len; i++)
	{
		world[i]->render(this->screen);
	}
	SDL_UpdateWindowSurface(this->window);
	sleep(10);
}

void Engine::getEvents()
{
    while(SDL_PollEvent(&event) != 0)
	{
		if(event.type==SDL_QUIT)
		{
			IS_RUNNING = false;
			break;
		}
		else if(event.type==SDL_KEYDOWN)
		{
			switch(event.key.keysym.sym)
			{
			case SDLK_w:
				MOVE_UP = true;
				break;
			case SDLK_a:
				MOVE_LEFT = true;
				break;
			case SDLK_s:
				MOVE_DOWN = true;
				break;
			case SDLK_d:
				MOVE_RIGHT = true;
				break;
			}
		}
		else if(event.type==SDL_KEYUP)
		{
			switch(event.key.keysym.sym)
			{
			case SDLK_w:
				MOVE_UP = false;
				break;
			case SDLK_a:
				MOVE_LEFT = false;
				break;
			case SDLK_s:
				MOVE_DOWN = false;
				break;
			case SDLK_d:
				MOVE_RIGHT = false;
			}
		}
	}
}

void Engine::clearScreen() {SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));}
