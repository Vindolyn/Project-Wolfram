#include "sprite.h"
#include "defs.h"

Texture_map texture_heap;

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

void Sprite::loadSheet(std::string name)
{
    Texture_iter it = texture_heap.find(name);
    if(it != texture_heap.end())
    {
        if(!it->second)
        {
            output("There's nothing here");
            return;
        }
        sheet = it->second;
    }
    else {output("Could not find texture: "+name);}
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
			for(unsigned int i=0; i<frame_count; i++)
			{
				pushFrame(pos, y, w, h);
				pos+=w;
			}
		}
		else if(flag==VERTICAL)
		{
			int pos = y;
			for(unsigned int i=0; i<frame_count; i++)
			{
				pushFrame(x, pos, w, h);
				pos+=h;
			}
		}
	}
}

void Sprite::pushFrame(int x, int y, int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    frame.push_back(rect);
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
