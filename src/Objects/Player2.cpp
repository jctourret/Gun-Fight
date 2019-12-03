#include "Player2.h"
#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {

	static const int playerSpeed = 500;
	static const int textFontSize = 20;

	static float p2AnimTimer = 0.0f;
	static float p2DeadTime = 2.0f;

	static const float bulletAimRate = 0.35f;
	static const float bulletWidth = 20;
	static const float bulletHeight = 10;
	static const float resetP2DeadTime = p2DeadTime;
	static const float p2AnimTime = 1.0f;

	void runP2AnimTimer();

	Player2::Player2(float x, float y, float width, float height) {
		_body.x = x;
		_body.y = y;
		_body.width = width;
		_body.height = height;
		for (int i = 0; i < p2MaxBullets; i++) {
			if (_p2Bullets[i] != NULL) {
				_p2Bullets[i] = NULL;
			}
		}
		_bulletsLeft = p2MaxBullets;
		_score = NULL;
		_aim = Mid;
		_isDead = false;
		_isMoving = false;
		_F1_Up = LoadTexture("../res/assets/img/P2_F1_Up.png");
		_F1_Mid = LoadTexture("../res/assets/img/P2_F1_Mid.png");
		_F1_Down = LoadTexture("../res/assets/img/P2_F1_Down.png");
		_F2_Up = LoadTexture("../res/assets/img/P2_F2_Up.png");
		_F2_Mid = LoadTexture("../res/assets/img/P2_F2_Mid.png");
		_F2_Down = LoadTexture("../res/assets/img/P2_F2_Down.png");
		_F3_Up = LoadTexture("../res/assets/img/P2_F3_Up.png");
		_F3_Mid = LoadTexture("../res/assets/img/P2_F3_Mid.png");
		_F3_Down = LoadTexture("../res/assets/img/P2_F3_Down.png");
		_wScream = LoadSound("../res/assets/snd/wScream.ogg");
	}

	Player2::~Player2() {
		for (int i = 0; i < p2MaxBullets; i++) {
			if (_p2Bullets[i] != NULL) {
				delete _p2Bullets[i];
			}
		}
		UnloadTexture(_F1_Up);
		UnloadTexture(_F1_Mid);
		UnloadTexture(_F1_Down);
		UnloadTexture(_F2_Up);
		UnloadTexture(_F2_Mid);
		UnloadTexture(_F2_Down);
		UnloadTexture(_F3_Up);
		UnloadTexture(_F3_Mid);
		UnloadTexture(_F3_Down);
		UnloadSound(_wScream);
	}

	void Player2::setBody(Rectangle body) {
		_body = body;
	}

	void Player2::setX(float x) {
		_body.x = x;
	}

	void Player2::setY(float y) {
		_body.y = y;
	}

	void Player2::setWidth(float width) {
		_body.width = width;
	}

	void Player2::setHeight(float height) {
		_body.height = height;
	}

	void Player2::setScore(int score) {
		_score = score;
	}

	Rectangle Player2::getBody() {
		return _body;
	}

	int Player2::getBulletsLeft() {
		return _bulletsLeft;
	}

	int Player2::getScore() {
		return _score;
	}

	bool Player2::getIsDead() {
		return _isDead;
	}

	void Player2::draw() {
		for (int i = 0; i < p2MaxBullets; i++) {
			if (_p2Bullets[i] != NULL) {
				_p2Bullets[i]->draw();
			}
		}
		runP2AnimTimer();
		if (!_isDead) {
			switch (_aim) {
			case Up:
				if (_isMoving) {
					if (p2AnimTimer <= p2AnimTime / 4) {
						DrawTexture(_F1_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime / 4 && p2AnimTimer <= p2AnimTime / 2) {
						DrawTexture(_F2_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime / 2 && p2AnimTimer <= p2AnimTime - p2AnimTime / 4) {
						DrawTexture(_F3_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime - p2AnimTime / 4 && p2AnimTimer <= p2AnimTime) {
						DrawTexture(_F2_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime) {
						p2AnimTimer = 0.0f;
					}
				}
				else {
					DrawTexture(_F1_Up, _body.x, _body.y, RAYWHITE);
				}
				break;
			case Mid:
				if (_isMoving) {
					if (p2AnimTimer <= p2AnimTime / 4) {
						DrawTexture(_F1_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime / 4 && p2AnimTimer <= p2AnimTime / 2) {
						DrawTexture(_F2_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime / 2 && p2AnimTimer <= p2AnimTime - p2AnimTime / 4) {
						DrawTexture(_F3_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime - p2AnimTime / 4 && p2AnimTimer <= p2AnimTime) {
						DrawTexture(_F2_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime) {
						p2AnimTimer = 0.0f;
					}
				}
				else {
					DrawTexture(_F1_Mid, _body.x, _body.y, RAYWHITE);
				}
				break;
			case Down:
				if (_isMoving) {
					if (p2AnimTimer <= p2AnimTime / 4) {
						DrawTexture(_F1_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime / 4 && p2AnimTimer <= p2AnimTime / 2) {
						DrawTexture(_F2_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime / 2 && p2AnimTimer <= p2AnimTime - p2AnimTime / 4) {
						DrawTexture(_F3_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime - p2AnimTime / 4 && p2AnimTimer <= p2AnimTime) {
						DrawTexture(_F2_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p2AnimTimer > p2AnimTime) {
						p2AnimTimer = 0.0f;
					}
				}
				else {
					DrawTexture(_F1_Down, _body.x, _body.y, RAYWHITE);
				}
				break;
			}
		}
		if (_isDead) {
			DrawRectangle(_body.x, _body.y + _body.height - _body.width, _body.height, _body.width, MAROON);
			DrawText("YOU GOT ME!", _body.x, _body.y, textFontSize, MAROON);
		}
		for (int i = 0; i < _bulletsLeft; i++) {
			DrawRectangle(screenWidth - (screenWidth / 20 + (i*(bulletHeight * 2))), screeenHeight - screeenHeight / 20 - bulletWidth, bulletHeight, bulletWidth, RAYWHITE);
		}
	}

	void Player2::move() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_UP) && _body.y > 0 && !_isDead) {
			_body.y -= playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_DOWN) && _body.y < screeenHeight - _body.height && !_isDead) {
			_body.y += playerSpeed * time;
			_isMoving = true;

		}
		if (IsKeyDown(KEY_LEFT) && _body.x > screenWidth - screenWidth / 4 - _body.width && !_isDead) {
			_body.x -= playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_RIGHT) && _body.x <= screenWidth - _body.width && !_isDead) {
			_body.x += playerSpeed * time;
			_isMoving = true;
		}
		if (!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN) && !IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
			_isMoving = false;
		}
	}

	void Player2::fireBullet() {
		for (int i = 0; i < p2MaxBullets; i++) {
			if (_p2Bullets[i] == NULL && !_isDead) {
				if (IsKeyPressed(KEY_KP_1)) {
					_p2Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
					_p2Bullets[i]->setDirectionX(1 - bulletAimRate);
					_p2Bullets[i]->setDirectionY((-1 * bulletAimRate));
					_aim = Up;
					_bulletsLeft--;
					break;
				}
				if (IsKeyPressed(KEY_KP_2)) {
					_p2Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
					_p2Bullets[i]->setDirectionX(1);
					_p2Bullets[i]->setDirectionY(0);
					_aim = Mid;
					_bulletsLeft--;
					break;
				}
				if (IsKeyPressed(KEY_KP_3)) {
					_p2Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
					_p2Bullets[i]->setDirectionX(1 - bulletAimRate);
					_p2Bullets[i]->setDirectionY(bulletAimRate);
					_aim = Down;
					_bulletsLeft--;
					break;
				}
			}
		}
	}
	void Player2::moveBullet() {
		float time = GetFrameTime();
		for (int i = 0; i < p2MaxBullets; i++) {
			if (_p2Bullets[i] != NULL) {
				if (_p2Bullets[i]->getBodyX() < screenWidth) {
					_p2Bullets[i]->setBodyX(_p2Bullets[i]->getBodyX() - ((_p2Bullets[i]->getSpeed() * time) * _p2Bullets[i]->getDirectionX()));
					_p2Bullets[i]->setBodyY(_p2Bullets[i]->getBodyY() + ((_p2Bullets[i]->getSpeed() * time) * _p2Bullets[i]->getDirectionY()));
				}
				if (_p2Bullets[i]->getBodyY() > screeenHeight - _p2Bullets[i]->getBodyHeight() || _p2Bullets[i]->getBodyY() < 0) {
					_p2Bullets[i]->setDirectionY(-1 * (_p2Bullets[i]->getDirectionY()));
				}
			}
		}
	}
	void Player2::checkP1BulletCollision(Rectangle body) {
		for (int i = 0; i < p2MaxBullets; i++) {
			if (_p2Bullets[i] != NULL && !_isDead) {
				if (CheckCollisionRecs(_p2Bullets[i]->getBody(), body) && !_p2Bullets[i]->getHasScored() && !p1Dies) {
					_score = _score + 1;
					_p2Bullets[i]->setHasScored(true);
					p1Dies = true;
					PlaySound(_wScream);
				}
				if (!CheckCollisionRecs(_p2Bullets[i]->getBody(), body)) {
					_p2Bullets[i]->setHasScored(false);
				}
			}
		}
	}
	void Player2::die(bool& die) {
		if (die) {
			_isDead = true;
			p2DeadTime -= GetFrameTime();
			if (p2DeadTime <= 0) {
				p2DeadTime = resetP2DeadTime;
				_isDead = false;
				die = false;
			}
		}
	}
	void Player2::reload() {
		for (int i = 0; i < p2MaxBullets; i++) {
			if (_p2Bullets[i] != NULL) {
				_p2Bullets[i] = NULL;
			}
		}
		_bulletsLeft = p2MaxBullets;
	}
	void runP2AnimTimer() {
		p2AnimTimer += GetFrameTime();
	}
}