#include "Menu.h"
using namespace GunFight;

namespace GunFight {
	Menu::Menu() {
		_menuOn = true;
		_toGameplay = false;
		_toCredits = false;
	}

	Menu::~Menu() {
	}

	void Menu::setToGameplay(bool toGameplay) {
		_toGameplay = toGameplay;
	}

	void Menu::setToCredits(bool toCredits) {
		_toCredits = toCredits;
	}

	bool Menu::getToCredits() {
		return _toCredits;
	}
	bool Menu::getToGameplay() {
		return _toGameplay;
	}

	void Menu::run() {
		_menuOn = true;
		while (_menuOn) {
			update();
			draw();
		}
	}

	void Menu::update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_menuOn = false;
			_toGameplay = true;
		}
	}

	void Menu::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Menu", 200, 500, 50, MAROON);
		EndDrawing();
	}
}