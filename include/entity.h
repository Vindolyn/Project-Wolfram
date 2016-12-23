#ifndef WOLFRAM_ENTITY_H
#define WOLFRAM_ENTITY_H

#include <SDL.h>
#include <iostream>
#include <vector>
#include "sprite.h"
#include "toolkit.h"

enum layers
{

	HUD_LAYER //goes above everything
};

class Entity
{
public:
    //variables
    coord loc;
    coord scale;
    Sprite sprite;
    unsigned int animation_timer = 0;
    unsigned int animation_frame = 0;

    //functions
    Entity();
    void setLoc(double x, double y);
	void render();
	void shift(double x, double y);
	void setScale(double x, double y);
	void shiftScale(double x, double y);
};

typedef std::vector<Entity*> ent_list;
extern ent_list world;

#endif // WOLFRAM_ENTITY_H
