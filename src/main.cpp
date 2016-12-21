#include "toolkit.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

bool init();
bool loadMedia();
void exit();
void output(string s);
void sleep(int ms);

SDL_Window *window = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *image = NULL;

int main(int argc, char *args[])
{
    if(!init()) return -1;
    if(!loadMedia()) return -2;

    SDL_BlitSurface(image, NULL, screen, NULL);
    SDL_UpdateWindowSurface(window);
    sleep(2000);

    exit();
    return 0;
}

bool init()
{
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        output("Could not initialize SDL. "+string(SDL_GetError()));
        return 0;
    }
    else
    {
        window = SDL_CreateWindow("Project Wolfram", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window==NULL)
        {
            output("Could not initialize SDL Window. "+string(SDL_GetError()));
            return 0;
        }
        screen = SDL_GetWindowSurface(window);
    }
    return 1;
}

bool loadMedia()
{
    image = SDL_LoadBMP("assets/ahri.bmp");
    if(image==NULL)
    {
        output("Failed to load Bitmap file. "+string(SDL_GetError()));
        return 0;
    }
    return 1;
}

void exit()
{
    SDL_FreeSurface(image);
    image = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();
}
