#ifndef WOLFRAM_SPRITE_H
#define WOLFRAM_SPRITE_H

#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "toolkit.h"

enum sheet_dir
{
	HORIZONTAL,
	VERTICAL
};

class Sprite
{
public:
	int frame_w = 0;
	int frame_h = 0;
	unsigned int frame_count = 0;
	unsigned int delay = 0;
	std::vector<SDL_Rect> frame;
	SDL_Texture *sheet;
	coord offset;

	Sprite();
	Sprite(std::string path);
	~Sprite();
	void loadSheet(std::string path);
	void pushFrame(int x, int y, int w, int h);
	void calcFrames(int x, int y, int w, int h, int flag);
	void setFrameSize(int w, int h);
	void setFrameCount(int f);
	void clearFrames();
};

#endif // WOLFRAM_SPRITE_H
