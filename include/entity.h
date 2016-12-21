#ifndef WOLFRAM_ENTITY_H
#define WOLFRAM_ENTITY_H

#include "toolkit.h"

struct coords
{
    double x=0;
    double y=0;
};

class Entity
{
public:
    //variables
    coords loc;
    SDL_Surface *image = NULL;

    //functions
    Entity();
    Entity(std::string path);
    Entity(std::string path, double x, double y);
    ~Entity();
    bool setImage(std::string path);
    void setLoc(double x, double y);
	void render(SDL_Surface *surface);
	void shift(double x, double y);
};

typedef std::vector<Entity*> ent_list;
extern ent_list world;

#endif // WOLFRAM_ENTITY_H
