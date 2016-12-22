#include "core_engine.h"
#include <SDL.h>
#include <SDL_image.h>

using std::string;

Entity player;
extern SDL_Window *window;
extern SDL_Renderer *screen;

bool MOVE_UP=false, MOVE_DOWN=false, MOVE_LEFT=false, MOVE_RIGHT=false;

Engine::Engine(string path, int width, int height)
{
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		output("[!!!] Failed to initialize SDL.");
		return;
	}
    if(!IMG_Init(IMG_INIT_PNG))
    {
        output("[!!!] Failed to initialize SDL_image.");
        return;
    }
    window = SDL_CreateWindow(path.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window==NULL)
	{
		output("[!!!] Failed to initialize window.");
		return;
	}
	screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(screen==NULL)
    {
        output("[!!!] Failed to initialize renderer.");
        return;
    }
    SDL_SetRenderDrawColor(screen, 0x00,0x00,0x00,0xff);
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
		//Get events
		getEvents();
		//Do logic
		double speed = 0.1;
		if(MOVE_LEFT)
        {
            player.scale.x -= speed;
            player.scale.y -= speed;
        }
		if(MOVE_RIGHT)
        {
            player.scale.x += speed;
            player.scale.y += speed;
        }
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
		world[i]->render();
	}
	SDL_UpdateWindowSurface(window);
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

void Engine::clearScreen() {return;}
