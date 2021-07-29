#include "Gameplay.h"
#include "System/Game_loop.h"
#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {

	const Vector2 player1Pos = { screenWidth / 10 , screeenHeight / 2 };
	const int player2PosX = screenWidth - screenWidth / 10;
	const int player2PosY = screeenHeight / 2;
	const int p1ScorePosX = 100;
	const int p1ScorePosY = 50;
	const int p2ScorePosX = 900;
	const int p2ScorePosY = 50;
	const int reloadingPosX = screenWidth/2;
	const int reloadingPosY = 100;
	const int timerPosX = screenWidth/2;
	const int timerPosY = 50;
	const int winTextPosX = screenWidth / 2 - 100;
	const int winTextPosY = 200;
	const int toCreditsPosX = screenWidth / 3;
	const int toCreditsPosy = 400;
	const int textFontSize = 40;

	const Color textColor = YELLOW;

	bool reloading = false;

	float reloadTimer = 0.0f;
	float gameTimer = 0.0f;

	const float reloadtime = 1.99f;
	const float gameTime = 60.0f;
	const float maxTreeSpawnHeight = screenWidth - 100;

	Gameplay::Gameplay() {
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
		_player1 = new Player(player1Pos);
		_timer = gameTime;
	}

	Gameplay::~Gameplay() {
		if (_player1 != NULL) {
			delete _player1;
		}
	}

	void Gameplay::setToMenu(bool toMenu) {
		_toMenu = toMenu;
	}

	void Gameplay::setToCredits(bool toCredits) {
		_toCredits = toCredits;
	}

	bool Gameplay::getToCredits() {
		return _toCredits;
	}

	bool Gameplay::getToMenu() {
		return _toMenu;
	}

	void Gameplay::run() {
		update();
		draw();
	}

	void Gameplay::update() {
		runTimer();
		_player1->update();
		if (_player1->getIsDead()) {
			if (reloadTimer <= reloadtime) {
				reloading = true;
				reloadTimer += GetFrameTime();
			}
			else {
				_player1->reload();
			}
		}
		//if (_player1.) {
		//	if (reloadTimer <= reloadtime) {
		//		reloading = true;
		//		reloadTimer += GetFrameTime();
		//	}
		//	else {
		//		_player1->reload();
		//		_player2->reload();
		//	}
		//}
		//if (_player1->getBulletsLeft() == p1MaxBullets && _player2->getBulletsLeft() == p2MaxBullets) {
		//	reloading = false;
		//	reloadTimer = 0.0f;
		//}
	}

	void Gameplay::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(FormatText("SCORE: %i", _player1->getScore()), p1ScorePosX, p1ScorePosY, textFontSize, textColor);
		DrawText(FormatText("%i", _timer), timerPosX, timerPosY, textFontSize, textColor);
		_player1->draw();
		if (reloading) {
			DrawText("Reload!", reloadingPosX, reloadingPosY, textFontSize, textColor);
		}

		//if (_p1wins) {
		//	DrawText("Player 1 Wins!", winTextPosX, winTextPosY, textFontSize, textColor);
		//	DrawText("Press enter to go to credits.", toCreditsPosX, toCreditsPosy, textFontSize, textColor);
		//}
		//if (_p2wins) {
		//	DrawText("Player 2 Wins!", winTextPosX, winTextPosY, textFontSize, textColor);
		//	DrawText("Press enter to go to credits.", toCreditsPosX, toCreditsPosy, textFontSize, textColor);
		//}
		EndDrawing();
	}

	void Gameplay::runTimer() {
		gameTimer += GetFrameTime();
		if (gameTimer >= 1.0f) {
			_timer -= 1;
			gameTimer = 0.0f;
		}
		if (_timer <= 0) {
			_gameplayOn = false;
			checkWinner();
			toCredits();
		}
	}

	void Gameplay::checkWinner() {
		
	}

	void Gameplay::toCredits() {
		if (IsKeyPressed(KEY_ENTER)) {
			_toCredits = true;
			_timer = gameTime;
		}
	}
}