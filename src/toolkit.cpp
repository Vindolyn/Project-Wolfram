#include "toolkit.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

void sleep(int ms) {SDL_Delay(ms);}
void output(string s) {cout << s << endl;}
void SDL_Crash(string msg) {output("[!!!] "+msg+" :: "+string(SDL_GetError()));}
SDL_Texture *loadTexture(std::string path)
{
    return SDL_CreateTextureFromSurface(screen, IMG_Load(path.c_str()));
}
