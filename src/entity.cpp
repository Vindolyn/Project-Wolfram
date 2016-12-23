#include "entity.h"
#include "toolkit.h"
#include "defs.h"
#include "sprite.h"

ent_list world;

Entity::Entity()
{
	setLoc(0,0);
	setScale(1,1);
	world.push_back(this);
}

void Entity::render()
{
    //Setup render positions
	SDL_Rect rect;
	rect.x = loc.x+(sprite.offset.x*scale.x);
	rect.y = loc.y+(sprite.offset.y*scale.y);

	//If the sprite has an animation delay, consider it having multiple frames
	if(sprite.delay)
	{
		while(animation_timer >= sprite.delay)
		{
			animation_timer -= sprite.delay;
			animation_frame++;
			if(animation_frame>=sprite.frame_count) animation_frame = 0;
		}
		SDL_Rect curframe = sprite.frame[animation_frame];
		rect.w = sprite.frame_w*scale.x;
		rect.h = sprite.frame_h*scale.y;

		SDL_RenderCopy(screen, sprite.sheet, &curframe, &rect);
		animation_timer += 1000/LOGIC_PER_SECOND;
	}
	else
	{
		SDL_QueryTexture(sprite.sheet, NULL, NULL, &rect.w, &rect.h);
		rect.w = sprite.frame_w*scale.x;
		rect.h = sprite.frame_h*scale.y;

		if(sprite.frame.size()) SDL_RenderCopy(screen, sprite.sheet, &sprite.frame[0], &rect);
        else SDL_RenderCopy(screen, sprite.sheet, NULL, &rect);
	}
}

void Entity::setLoc(double x, double y)
{
	loc.x = x;
	loc.y = y;
}

void Entity::shift(double x, double y)
{
	loc.x += x;
	loc.y += y;
}

void Entity::setScale(double x, double y)
{
    scale.x = x;
    scale.y = y;
    if(scale.x<0) scale.x = 0;
    if(scale.y<0) scale.y = 0;
}

void Entity::shiftScale(double x, double y)
{
    scale.x += x;
	scale.y += y;
	if(scale.x<0) scale.x = 0;
    if(scale.y<0) scale.y = 0;
}
