#include "core_engine.h"
#include <ctime>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Sprite_ptr coin_icon(new Sprite);
Sprite_ptr rainbow_icon(new Sprite);

void loadSprites()
{
    coin_icon->loadSheet("coin");
    coin_icon->setFrameCount(6);
    coin_icon->calcFrames(0, 0, 16, 16, HORIZONTAL);
    coin_icon->offset.x = -8;
    coin_icon->offset.y = -8;
    coin_icon->delay = 50;

    rainbow_icon->loadSheet("rainbow");
    rainbow_icon->setFrameCount(12);
    rainbow_icon->calcFrames(0, 0, 16, 16, HORIZONTAL);
    rainbow_icon->offset.x = -8;
    rainbow_icon->offset.y = -8;
    rainbow_icon->delay = 50;
}

Entity* makeRainbow()
{
    Entity* coin = new Entity();
    coin->sprite = rainbow_icon;
    coin->setScale(3,3);
    return coin;
}

Entity* makeCoin()
{
    Entity* coin = new Entity();
    coin->sprite = coin_icon;
    return coin;
}

void makeCoinBlock(int row, int col)
{
    int x=0, y=0;
    int w=64, h=64;
    int block_x = (SCREEN_WIDTH/2)-((w*col)/2);
    int block_y = (SCREEN_HEIGHT/2)-((h*row)/2);
    Entity* coin;
    while(y<row)
    {
        x=0;
        while(x<col)
        {
            coin = makeRainbow();
            coin->loc.x = block_x + (w*x);
            coin->loc.y = block_y + (h*y);
            coin->animation_frame = (x+y)%coin->sprite->frame_count;
            ++x;
        }
        ++y;
    }
}

int main(int argc, char *args[])
{
    srand(static_cast<unsigned>(time(NULL)));
	Engine engine("Project Wolfram", SCREEN_WIDTH, SCREEN_HEIGHT);
	loadSprites();
	//makeCoinBlock(8,12);
	Entity* coin;
	for(unsigned int i=0; i<100; i++)
    {
        coin = makeCoin();
        double scale = rand(300,500)/100;
        coin->setScale(scale, scale);
        coin->loc.x = rand(0, SCREEN_WIDTH);
        coin->loc.y = rand(0, SCREEN_HEIGHT);
        coin->animation_frame = rand(0,6);
    }
	engine.init();
    return 0;
}
