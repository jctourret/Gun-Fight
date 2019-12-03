#ifndef MENU_H
#define MENU_H
#include "raylib.h"

namespace GunFight {

	class Menu {
	private:
		bool _menuOn;
		bool _toGameplay;
		bool _toCredits;
	public:
		Menu();
		~Menu();
		void setToGameplay(bool toGameplay);
		void setToCredits(bool toCredits);
		bool getToGameplay();
		bool getToCredits();
		void run();
		void update();
		void draw();
	};
}
#endif