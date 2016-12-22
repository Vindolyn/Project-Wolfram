#ifndef WOLFRAM_ENTITY_H
#define WOLFRAM_ENTITY_H

#include "toolkit.h"
#include <vector>
#include <SDL.h>

struct position
{
    double x=0;
    double y=0;
};

class Entity
{
public:
    //variables
    position loc;
    position scale;
    SDL_Texture *image = NULL;

    //functions
    Entity();
    Entity(double x, double y);
    ~Entity();
    bool setImage(std::string path);
    void setLoc(double x, double y);
	void render();
	void shift(double x, double y);
	void setScale(double x, double y);
};

typedef std::vector<Entity*> ent_list;
extern ent_list world;

#endif // WOLFRAM_ENTITY_H
