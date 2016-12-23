#include <SDL_image.h>
#include "core_engine.h"
#include "toolkit.h"
#include "entity.h"
#include "defs.h"

using std::string;

Entity player;

bool MOVE_UP=false, MOVE_DOWN=false, MOVE_LEFT=false, MOVE_RIGHT=false;

Engine::Engine(string path, int width, int height)
{
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		SDL_Crash("Failed to initialize SDL.");
		return;
	}
    if(!IMG_Init(IMG_INIT_PNG))
    {
        SDL_Crash("Failed to initialize SDL_image.");
        return;
    }
    window = SDL_CreateWindow(path.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window==NULL)
	{
		SDL_Crash("Failed to initialize window.");
		return;
	}
	screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(screen==NULL)
    {
        SDL_Crash("Failed to initialize renderer.");
        return;
    }
}
Engine::~Engine()
{
	SDL_DestroyRenderer(screen);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}

void Engine::init()
{
	while(IS_RUNNING)
	{
		getEvents();
		logic();
		render();
	}
}

void Engine::render()
{
	SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
	SDL_RenderClear(screen);

	//render contents of world;
	int len = world.size();
	for(int i=0; i<len; i++)
	{
		world[i]->render();
	}
	SDL_RenderPresent(screen);
	sleep(1000/LOGIC_PER_SECOND);
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
			case SDLK_ESCAPE:
                IS_RUNNING = false;
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

void Engine::logic()
{
	double speed = 0.25;
	int delay =1;
	if(MOVE_LEFT) {player.shiftScale(-speed,-speed);}
	if(MOVE_RIGHT) {player.shiftScale(speed,speed);}
	if(MOVE_UP) player.sprite.delay += delay;
	if(MOVE_DOWN)
    {
        if(player.sprite.delay-delay <= 0) player.sprite.delay = 0;
        else player.sprite.delay -= delay;
    }
}
