#ifndef CREDITS_H
#define CREDITS_H
#include "raylib.h"
namespace GunFight {
	class Credits {
	private:
		bool _creditsOn;
		bool _toMenu;
		bool _toGameplay;
	public:
		Credits();
		~Credits();
		void setToMenu(bool toMenu);
		void setToGameplay(bool toGameplay);
		bool getToMenu();
		bool getToGameplay();
		void run();
		void update();
		void draw();
	};
}
#endif