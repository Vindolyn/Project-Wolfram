#include "toolkit.h"
#include <vector>
#include <SDL_image.h>
#include <sstream>
#include "defs.h"
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::stringstream;

void sleep(int ms) {SDL_Delay(ms);}
void output(string s) {cout << s << endl;}
void SDL_Crash(string msg) {output("[!!!] "+msg+" :: "+"\n"+string(SDL_GetError()));}
SDL_Texture* loadTexture(std::string path)
{
    return SDL_CreateTextureFromSurface(screen, IMG_Load(path.c_str()));
}

void drawRect(SDL_Rect *rect, int drawset, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    SDL_SetRenderDrawColor(screen, red, green, blue, alpha);
	if(drawset==FILL) SDL_RenderFillRect(screen, rect);
	else if(drawset==OUTLINE) SDL_RenderDrawRect(screen, rect);
}

void drawLine(int x_start, int y_start, int x_end, int y_end, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	SDL_SetRenderDrawColor(screen, red, green, blue, alpha);
	SDL_RenderDrawLine(screen, x_start, y_start, x_end, y_end);
}

void drawPoint(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
	SDL_SetRenderDrawColor(screen, red, green, blue, alpha);
	SDL_RenderDrawPoint(screen, x, y);
}

string numToString(int num)
{
	stringstream s;
	s << num;
	return s.str();
}

int rand(int mn, int mx)
{
    return std::rand()%(mx-mn)+mn;
}
