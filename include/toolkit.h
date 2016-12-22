#ifndef WOLFRAM_TOOLKIT_H
#define WOLFRAM_TOOLKIT_H

#include <iostream>
#include <SDL.h>
#include "defs.h"

enum DrawSets
{
	FILL,
	OUTLINE
};

struct coord
{
    double x=0;
    double y=0;
};

void sleep(int ms);
void output(std::string s);
void SDL_Crash(std::string msg);
SDL_Texture *loadTexture(std::string path);

void drawRect(SDL_Rect *rect, int drawset, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
void drawLine(int x_start, int y_start, int x_end, int y_end, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
void drawPoint(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

std::string numToString(int num);

#endif //WOLFRAM_TOOLKIT_H
