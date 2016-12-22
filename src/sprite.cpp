#include "sprite.h"
#include "defs.h"

Sprite::Sprite(){}

Sprite::Sprite(std::string path)
{
	loadSheet(path);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(sheet);
	sheet = NULL;
}

void Sprite::loadSheet(std::string path)
{
	sheet = loadTexture(path);
}

#include <sstream>

void Sprite::render(coord loc)
{
	SDL_Rect rect;
	rect.x = loc.x;
	rect.y = loc.y;

	if(animation_delay)
	{
		while(animation_timer >= animation_delay)
		{
			animation_timer -= animation_delay;
			animation_frame++;
			if(animation_frame>=frame_count) animation_frame = 0;
		}
		SDL_Rect curframe = frame[animation_frame];
		rect.w = frame_w*scale.x;
		rect.h = frame_h*scale.y;

		SDL_RenderCopy(screen, sheet, &curframe, &rect);
		animation_timer += 1000/LOGIC_PER_SECOND;
	}
	else
	{
		SDL_QueryTexture(sheet, NULL, NULL, &rect.w, &rect.h);
		rect.w *= scale.x;
		rect.h *= scale.y;

		SDL_RenderCopy(screen, sheet, NULL, &rect);
	}
}

void Sprite::calcFrames(int x, int y, int w, int h, int flag)
{
	setFrameSize(w, h);
	frame.clear();
	if(!frame_count)
	{
		SDL_Rect ss;
		SDL_QueryTexture(sheet, NULL, NULL, &ss.w, &ss.h);
		if(flag==HORIZONTAL)
		{
			for(int pos=x; pos<ss.w; pos+=w)
			{
				SDL_Rect rect = {pos, y, w, h};
				frame.push_back(rect);
				frame_count++;
			}
		}
		else if(flag==VERTICAL)
		{
			for(int pos=y; pos<ss.h; pos+=h)
			{
				SDL_Rect rect = {x, pos, w, h};
				frame.push_back(rect);
				frame_count++;
			}
		}
	}
	else
	{
		if(flag==HORIZONTAL)
		{
			int pos = x;
			for(int i=0; i<frame_count; i++)
			{
				SDL_Rect rect = {pos, y, w, h};
				frame.push_back(rect);
				pos+=w;
			}
		}
		else if(flag==VERTICAL)
		{
			int pos = y;
			for(int i=0; i<frame_count; i++)
			{
				SDL_Rect rect = {x, pos, w, h};
				frame.push_back(rect);
				pos+=h;
			}
		}
	}
}

void Sprite::setFrameSize(int h, int w)
{
	frame_w = w;
	frame_h = h;
}

void Sprite::setFrameCount(int f) {frame_count = f;}

void Sprite::clearFrames()
{
	setFrameCount(0);
	setFrameSize(0,0);
	frame.clear();
}
