#include "Menu.h"

#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {
	
	const int titlePosX = 500;
	const int titlePosY = 50;
	const int titleFontSize = 50;
	const int textFontSize = 20;
	const int playPosX = 500;
	const int playPosY = 150;
	const int controlsPosX = 20;
	const int controlsPosY = 500;
	const int movePosX = 20;
	const int movePosY = 540;
	const int shootUpPosX = 20;
	const int shootUpPosY = 580;
	const int shootMidPosX = 20;
	const int shootMidPosY = 620;
	const int shootDownPosX = 20;
	const int shootDownPosY = 660;

	const Color textColor = YELLOW;
	
	Menu::Menu() {
		_menuOn = true;
		_toGameplay = false;
		_toCredits = false;
		_background = LoadTexture("res/assets/img/BKDawn.png");
	}

	Menu::~Menu() {
	}

	void Menu::SetToGameplay(bool toGameplay) {
		_toGameplay = toGameplay;
	}

	void Menu::SetToCredits(bool toCredits) {
		_toCredits = toCredits;
	}

	bool Menu::GetToCredits() {
		return _toCredits;
	}
	bool Menu::GetToGameplay() {
		return _toGameplay;
	}

	void Menu::Run() {
		Update();
		Draw();
	}

	void Menu::Update() {
		if (IsKeyPressed(KEY_ENTER)) {
			_menuOn = false;
			_toGameplay = true;
		}
	}

	void Menu::Draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(_background,0,0,WHITE);
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