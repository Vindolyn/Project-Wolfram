#include <SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[])
{
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        std::cout << "SDL could not be initiated." << std::endl;
        return -1;
    }
    else
    {
        window = SDL_CreateWindow("Project Wolfram", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window==NULL)
        {
            std::cout << "SDL window could not be created." << std::endl;
            return -2;
        }
        else
        {
            surface = SDL_GetWindowSurface(window);
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }
    }
    SDL_Quit();
    return 0;
}
