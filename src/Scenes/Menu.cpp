#include "Menu.h"

#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {
	
	static const int titlePosX = screenWidth/3;
	static const int titlePosY = 200;
	static const int titleFontSize = 50;
	static const int textFontSize = 20;
	static const int playPosX = screenWidth/3;
	static const int playPosY = 400;
	static const int controlsPosX = screenWidth / 3;
	static const int controlsPosY = 500;
	static const int movePosX = screenWidth / 3;
	static const int movePosY = 540;
	static const int shootUpPosX = screenWidth / 3;
	static const int shootUpPosY = 580;
	static const int shootMidPosX = screenWidth / 3;
	static const int shootMidPosY = 620;
	static const int shootDownPosX = screenWidth / 3;
	static const int shootDownPosY = 660;

	static const Color textColor = YELLOW;
	
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
		update();
		draw();
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
		DrawText("GUN FIGHT!", titlePosX, titlePosY, titleFontSize, textColor);
		DrawText("Press ENTER to GUN FIGHT!", playPosX, playPosY, textFontSize, textColor);
		DrawText("CONTROLS: PLAYER 1 / PLAYER 2", controlsPosX, controlsPosY, textFontSize, textColor);
		DrawText("MOVEMENT: W S A D / UP DOWN LEFT RIGHT ", movePosX, movePosY, textFontSize, textColor);
		DrawText("SHOOT UP: J / 1-KEYPAD", shootUpPosX, shootUpPosY, textFontSize, textColor);
		DrawText("SHOOT MIDDLE: K / 2-KEYPAD", shootMidPosX, shootMidPosY, textFontSize, textColor);
		DrawText("SHOOT DOWN: L / 3-KEYPAD", shootDownPosX, shootDownPosY, textFontSize, textColor);
		EndDrawing();
	}
}