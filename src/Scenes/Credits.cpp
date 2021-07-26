#include "Credits.h"

using namespace GunFight;

namespace GunFight {

	Credits::Credits() {
		_creditsOn = false;
		_toGameplay = false;
		_toMenu = false;
	}

	Credits::~Credits() {
	}

	void Credits::setToMenu(bool toMenu) {
		_toMenu = toMenu;
	}

	void Credits::setToGameplay(bool toGameplay) {
		_toGameplay = toGameplay;
	}

	bool Credits::getToGameplay() {
		return _toGameplay;
	}

	bool Credits::getToMenu() {
		return _toMenu;
	}

	void Credits::run() {
		update();
		draw();
	}

	void Credits::update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_creditsOn = false;
			_toMenu = true;
		}
	}

	void Credits::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("credits", 200, 500, 50, MAROON);
		EndDrawing();
	}
}