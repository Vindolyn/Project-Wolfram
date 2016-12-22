#include "entity.h"
#include "defs.h"
#include <SDL_image.h>

using std::string;

Entity::Entity()
{
	setLoc(0,0);
	setScale(1,1);
	world.push_back(this);
}

Entity::Entity(double x=0, double y=0)
{
    loc.x = x;
    loc.y = y;
    world.push_back(this);
}

Entity::~Entity()
{
    SDL_DestroyTexture(image);
    image = NULL;
}

bool Entity::setImage(string path)
{
	image = loadTexture(path);
	if(image==NULL) return 0;
	return 1;
}

void Entity::render()
{
	if(image==NULL) return;
	SDL_Rect rect;
	rect.x = loc.x;
	rect.y = loc.y;
	SDL_BlitScaled(image, NULL, screen, &rect);
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
}
