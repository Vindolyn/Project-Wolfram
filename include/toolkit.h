#ifndef WOLFRAM_TOOLKIT_H
#define WOLFRAM_TOOLKIT_H

#include <SDL.h>
#include <iostream>
#include <vector>
#include <iterator>

enum KeyPress
{
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D
};

void sleep(int ms);
void output(std::string s);

#endif //WOLFRAM_TOOLKIT_H
