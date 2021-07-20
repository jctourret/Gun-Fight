#include "Gameplay.h"
#include "System/Game_loop.h"
#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {

	const int player1PosX = screenWidth / 10;
	const int player1PosY = screeenHeight / 2;
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
	const float playersWidth = 50.0f;
	const float playersHeight = 100.0f;
	const float maxTreeSpawnHeight = screenWidth - 100;

	Gameplay::Gameplay() {
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
		_player1 = new Player1(player1PosX, player1PosY, playersWidth, playersHeight);
		_player2 = new Player2(player2PosX - playersWidth, player2PosY, playersWidth, playersHeight);
		_timer = gameTime;
	}

	Gameplay::~Gameplay() {
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
		_gameplayOn = true;
		while (_gameplayOn) {
			update();
			draw();
		}
	}

	void Gameplay::update() {
		runTimer();
		if (_gameplayOn) {
			if (!_player1->getIsDead() && !_player2->getIsDead()) {
				_player1->fireBullet();
				_player2->fireBullet();
				_player1->move();
				_player2->move();
			}
			_player1->moveBullet();
			_player2->moveBullet();
			_player1->checkP2BulletCollision(_player2->getBody());
			_player2->checkP1BulletCollision(_player1->getBody());
			_player1->die(_player2->p1Dies);
			_player2->die(_player1->p2Dies);
			if (_player1->getIsDead() || _player2->getIsDead()) {
				if (reloadTimer <= reloadtime) {
					reloading = true;
					reloadTimer += GetFrameTime();
				}
				else {
					_player1->reload();
					_player2->reload();
				}
			}
			if (_player1->getBulletsLeft() == 0 && _player2->getBulletsLeft() == 0) {
				if (reloadTimer <= reloadtime) {
					reloading = true;
					reloadTimer += GetFrameTime();
				}
				else {
					_player1->reload();
					_player2->reload();
				}
			}
			if (_player1->getBulletsLeft() == p1MaxBullets && _player2->getBulletsLeft() == p2MaxBullets) {
				reloading = false;
				reloadTimer = 0.0f;
			}
		}
	}

	void Gameplay::draw() {
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText(FormatText("SCORE: %i", _player1->getScore()), p1ScorePosX, p1ScorePosY, textFontSize, textColor);
		DrawText(FormatText("SCORE: %i", _player2->getScore()), p2ScorePosX, p2ScorePosY, textFontSize, textColor);
		DrawText(FormatText("%i", _timer), timerPosX, timerPosY, textFontSize, textColor);
		if (_gameplayOn) {
			_player1->draw();
			_player2->draw();
			if (reloading) {
				DrawText("Reload!", reloadingPosX, reloadingPosY, textFontSize, textColor);
			}
		}
		if (_p1wins) {
			DrawText("Player 1 Wins!", winTextPosX, winTextPosY, textFontSize, textColor);
			DrawText("Press enter to go to credits.", toCreditsPosX, toCreditsPosy, textFontSize, textColor);
		}
		if (_p2wins) {
			DrawText("Player 2 Wins!", winTextPosX, winTextPosY, textFontSize, textColor);
			DrawText("Press enter to go to credits.", toCreditsPosX, toCreditsPosy, textFontSize, textColor);
		}
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
		if (_player1->getScore() > _player2->getScore()) {
			_p1wins = true;
		}
		if (_player2->getScore() > _player1->getScore()) {
			_p2wins = true;
		}
	}

	void Gameplay::toCredits() {
		if (IsKeyPressed(KEY_ENTER)) {
			_toCredits = true;
			_timer = gameTime;
		}
	}
}