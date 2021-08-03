#ifndef GAME_LOOP_H
#define GAME_LOOP_H
#include "Screen.h"
#include "Scenes/Menu.h"
#include "Scenes/Gameplay.h"
#include "Scenes/Credits.h"
#include "Music/music.h"

namespace GunFight {

	enum class Gamestate {
		onMenu,
		onGameplay,
		onCredits,
	};

	class Game_loop {
	private:
		bool _gameOn;
		Screen* _screen;
		GameMusic* _music;
		Gamestate _gameState;
		Menu* _menu;
		Gameplay* _gameplay;
		Credits* _credits;
	public:
		Game_loop();
		~Game_loop();
		void GameLoop();
	};
}

#endif