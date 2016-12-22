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
	sprite.render(loc);
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
    sprite.scale.x = x;
    sprite.scale.y = y;
    if(sprite.scale.x<0) sprite.scale.x = 0;
    if(sprite.scale.y<0) sprite.scale.y = 0;
}

void Entity::shiftScale(double x, double y)
{
	sprite.scale.x += x;
	sprite.scale.y += y;
	if(sprite.scale.x<0) sprite.scale.x = 0;
    if(sprite.scale.y<0) sprite.scale.y = 0;
}
