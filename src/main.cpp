#include "core_engine.h"

extern Entity player;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char *args[])
{
	Engine engine("Project Wolfram", SCREEN_WIDTH, SCREEN_HEIGHT);
	player.setImage("assets/ahri.bmp");
	engine.init();
    return 0;
}
