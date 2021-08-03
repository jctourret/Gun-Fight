#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "System/ColisionManager.h"
#include "Objects/Player1.h"
#include "Objects/Cactus.h"
#include "Objects/Tree.h"
#include "Objects/Wagon.h"

namespace GunFight {

	class Gameplay {
	private:
		bool _gameplayOn;
		bool _toMenu;
		bool _toCredits;
		Player* _player1;
		Player* _player2;
		ColisionManager _colManager;
		Texture2D _bulletUI;
		vector<Texture2D> _background;
		vector<Obstacles*> _obstacles;
		Wagon* _wagon;
		Sound _deathJingle;
		int _p1Score;
		int _p2Score;
		int _timer;
	public:
		Gameplay();
		~Gameplay();
		void SetToMenu(bool toMenu);
		void SetToCredits(bool toCredits);
		bool GetToMenu();
		bool GetToCredits();
		void Run();
		void Update();
		void Draw();
		void SelectWeapon();
		void RunTimer();
		void ToNextStage();
		void ToCredits();
	};
}
#endif