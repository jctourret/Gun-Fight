#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "raylib.h"
#include "Objects/Character.h"
#include "Objects/Player2.h"
#include "Objects/Player1.h"
#include "Objects/Arbol.h"
#include "Objects/Carreta.h"
namespace GunFight {
	class Gameplay {
	private:
		bool _gameplayOn;
		bool _toMenu;
		bool _toCredits;
		bool _p1wins;
		bool _p2wins;
		Character* _character;
		Player* _player1;
		Player2* _player2;
		int _timer;
	public:
		Gameplay();
		~Gameplay();
		void setToMenu(bool toMenu);
		void setToCredits(bool toCredits);
		bool getToMenu();
		bool getToCredits();
		void run();
		void update();
		void draw();
		void runTimer();
		void checkWinner();
		void toCredits();
	};
}
#endif