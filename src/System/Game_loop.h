#pragma once
#include "Screen.h"
#include "Scenes/Menu.h"
#include "Scenes/Gameplay.h"
#include "Scenes/Credits.h"

enum Gamestate {
	onMenu,
	onGameplay,
	onCredits,
};

class Game_loop{
private:
	Screen* _screen;
	bool _gameOn;
	Gamestate _gameState;
	Menu* _menu;
	Gameplay* _gameplay;
	Credits* _credits;
public:
	Game_loop();
	~Game_loop();
	void game_loop();
};

