#ifndef WOLFRAM_CORE_ENGINE_H
#define WOLFRAM_CORE_ENGINE_H

#include "toolkit.h"
#include "entity.h"

/*
List of all things an engine's core needs to be able to handle...

Graphics
Input/Output
Audio
*/

class Engine
{
private:
	SDL_Event event;
public:
    //variables
    SDL_Window *window;
    SDL_Surface *screen;
    bool IS_RUNNING = true;

    //functions
    Engine(std::string title, int width, int height);
    ~Engine();
    void init();
    void render();
    void getEvents();
    void clearScreen();
};

#endif // WOLFRAM_CORE_ENGINE_H
