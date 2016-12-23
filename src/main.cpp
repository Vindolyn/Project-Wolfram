#include "core_engine.h"

extern Entity player;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char *args[])
{
	Engine engine("Project Wolfram", SCREEN_WIDTH, SCREEN_HEIGHT);
	player.sprite.loadSheet("assets/coin.png");
	player.sprite.setFrameCount(6);
	player.sprite.calcFrames(0, 0, 16, 16, HORIZONTAL);
	player.sprite.offset.x = -8;
	player.sprite.offset.y = -8;
	player.loc.x = SCREEN_WIDTH/2;
	player.loc.y = SCREEN_HEIGHT/2;
	player.sprite.delay = 50;
	player.setScale(20,20);
	engine.init();
    return 0;
}
