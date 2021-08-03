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
		void SetToMenu(bool toMenu);
		void SetToGameplay(bool toGameplay);
		bool GetToMenu();
		bool GetToGameplay();
		void Run();
		void Update();
		void Draw();
	};
}
#endif