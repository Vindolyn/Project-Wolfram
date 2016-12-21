#include "entity.h"

using std::string;

ent_list world;

Entity::Entity()
{
	loc.x=0;
	loc.y=0;
	world.push_back(this);
}

Entity::Entity(string path="")
{
	if(path!="") image = SDL_LoadBMP(path.c_str());
	loc.x=0;
	loc.y=0;
	world.push_back(this);
}

Entity::Entity(string path="", double x=0, double y=0)
{
    if(path!="") image = SDL_LoadBMP(path.c_str());
    loc.x = x;
    loc.y = y;
    world.push_back(this);
}

Entity::~Entity()
{
    SDL_FreeSurface(image);
    image = NULL;
}

bool Entity::setImage(string path)
{
	image = SDL_LoadBMP(path.c_str());
	if(image==NULL) return 0;
	return 1;
}

void Entity::render(SDL_Surface *screen)
{
	if(image==NULL) return;
	SDL_Rect rect;
	rect.x = loc.x;
	rect.y = loc.y;
	//rect.w = image->w;
	//rect.h = image->h;
	SDL_BlitSurface(image, NULL, screen, &rect);
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
