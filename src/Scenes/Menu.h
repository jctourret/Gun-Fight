#ifndef MENU_H
#define MENU_H
#include "raylib.h"

namespace GunFight {

	class Menu {
	private:
		bool _menuOn;
		bool _toGameplay;
		bool _toCredits;
		Texture2D _background;
	public:
		Menu();
		~Menu();
		void SetToGameplay(bool toGameplay);
		void SetToCredits(bool toCredits);
		bool GetToGameplay();
		bool GetToCredits();
		void Run();
		void Update();
		void Draw();
	};
}
#endif