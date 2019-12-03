#include <iostream>
#include "System/Game_loop.h"
#include "raylib.h"
using namespace std;
using namespace GunFight;
void main() {
	Game_loop* play = NULL;
	play = new Game_loop;
	if (play != NULL)
		play->game_loop();
	if (play != NULL)
		delete play;
}