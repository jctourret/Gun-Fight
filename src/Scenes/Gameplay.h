#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "System/ColisionManager.h"
#include "Objects/Player1.h"
namespace GunFight {
	class Gameplay {
	private:
		bool _gameplayOn;
		bool _toMenu;
		bool _toCredits;
		Player* _player1;
		ColisionManager colManager;
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