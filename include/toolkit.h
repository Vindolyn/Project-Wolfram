#ifndef WOLFRAM_TOOLKIT_H
#define WOLFRAM_TOOLKIT_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

void sleep(int ms);
void output(std::string s);
void SDL_Crash(std::string msg);
SDL_Texture *loadTexture(std::string path);

#endif //WOLFRAM_TOOLKIT_H
