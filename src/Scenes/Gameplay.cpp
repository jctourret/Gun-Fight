#include "Gameplay.h"
#include "System/Game_loop.h"
#include "System/Screen.h"

const int player1PosX = screenWidth / 10;
const int player1PosY = screeenHeight / 2;
const int player2PosX = screenWidth-screenWidth / 10;
const int player2PosY = screeenHeight / 2;

float gameTimer = 0.0f;

const float playersWidth = 50.0f;
const float playersHeight = 150.0f;

Gameplay::Gameplay(){
	_gameplayOn = false;
	_toMenu = false;
	_toCredits = false;
	_player1 = new Player1(player1PosX, player1PosY, playersWidth, playersHeight);
	_player2 = new Player2(player2PosX-playersWidth, player2PosY, playersWidth, playersHeight);
	_timer = 60.0f;
}

Gameplay::~Gameplay(){
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
	if (IsKeyPressed(KEY_ENTER)) {
		_gameplayOn = false;
		_toCredits = true;
	}
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
		_player1->reload();
		_player2->reload();
	}
	if (_player1->getBulletsFired() == 6 && _player2->getBulletsFired() == 6) {
		_player1->reload();
		_player2->reload();
	}
}

void Gameplay::draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("Gameplay", 300, 500, 50, MAROON);
	DrawText("Gameplay", 300, 500, 50, MAROON);
	DrawText(FormatText("SCORE: %i", _player1->getScore()), 100, 50, 40, MAROON);
	DrawText(FormatText("SCORE: %i", _player2->getScore()), 900, 50, 40, MAROON);
	DrawText(FormatText("%i", _timer), screenWidth/2, 50, 40, MAROON);
	_player1->draw();
	_player2->draw();
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
		_toCredits = true;
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
