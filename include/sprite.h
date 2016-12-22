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
private:
	int frame_w = 0;
	int frame_h = 0;
	int frame_count = 0;
	int animation_timer = 0;
	int animation_frame = 0;
	int animation_delay = 100;
public:
	std::vector<SDL_Rect> frame;
	SDL_Texture *sheet;
	coord offset;
	coord scale;

	Sprite();
	Sprite(std::string path);
	~Sprite();
	void loadSheet(std::string path);
	void setFrames(int x, int y, int w, int h, int index);
	void calcFrames(int x, int y, int w, int h, int flag);
	void render(coord loc);
	void setFrameSize(int w, int h);
	void setFrameCount(int f);
	void clearFrames();
};

#endif // WOLFRAM_SPRITE_H
