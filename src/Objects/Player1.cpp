#include "Player1.h"
#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {
	static const int playerSpeed = 500;
	static const int textFontSize = 20;

	static float p1AnimTimer = 0.0f;
	static float p1DeadTime = 2.0f;

	static const float bulletAimRate = 0.35f;
	static const float bulletWidth = 20;
	static const float bulletHeight = 10;
	static const float resetP1DeadTime = p1DeadTime;
	static const float p1AnimTime = 1.0f;

	void runP1AnimTimer();

	Player1::Player1(float x, float y, float width, float height) {
		_body.x = x;
		_body.y = y;
		_body.width = width;
		_body.height = height;
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] != NULL) {
				_p1Bullets[i] = NULL;
			}
		}
		_bulletsLeft = p1MaxBullets;
		_score = NULL;
		_aim = Mid;
		_isDead = false;
		_isMoving = false;
		_F1_Up = LoadTexture("../res/assets/img/P1_F1_Up.png");
		_F1_Mid = LoadTexture("../res/assets/img/P1_F1_Mid.png");
		_F1_Down = LoadTexture("../res/assets/img/P1_F1_Down.png");
		_F2_Up = LoadTexture("../res/assets/img/P1_F2_Up.png");
		_F2_Mid = LoadTexture("../res/assets/img/P1_F2_Mid.png");
		_F2_Down = LoadTexture("../res/assets/img/P1_F2_Down.png");
		_F3_Up = LoadTexture("../res/assets/img/P1_F3_Up.png");
		_F3_Mid = LoadTexture("../res/assets/img/P1_F3_Mid.png");
		_F3_Down = LoadTexture("../res/assets/img/P1_F3_Down.png");
		_wScream = LoadSound("../res/assets/snd/wScream.ogg");
	}

	Player1::~Player1() {
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] != NULL) {
				delete _p1Bullets[i];
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

	void Player1::setBody(Rectangle body) {
		_body = body;
	}

	void Player1::setX(float x) {
		_body.x = x;
	}

	void Player1::setY(float y) {
		_body.y = y;
	}

	void Player1::setWidth(float width) {
		_body.width = width;
	}

	void Player1::setHeight(float height) {
		_body.height = height;
	}

	void Player1::setScore(int score) {
		_score = score;
	}

	Rectangle Player1::getBody() {
		return _body;
	}

	int Player1::getBulletsLeft() {
		return _bulletsLeft;
	}

	int Player1::getScore() {
		return _score;
	}

	bool Player1::getIsDead() {
		return _isDead;
	}

	void Player1::draw() {
		runP1AnimTimer();
		if (!_isDead) {
			switch (_aim) {
			case Up:
				if (_isMoving) {
					if (p1AnimTimer <= p1AnimTime / 4) {
						DrawTexture(_F1_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime / 4 && p1AnimTimer <= p1AnimTime / 2) {
						DrawTexture(_F2_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime / 2 && p1AnimTimer <= p1AnimTime - p1AnimTime / 4) {
						DrawTexture(_F3_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime - p1AnimTime / 4 && p1AnimTimer <= p1AnimTime) {
						DrawTexture(_F2_Up, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime) {
						p1AnimTimer = 0.0f;
					}
				}
				else {
					DrawTexture(_F1_Up, _body.x, _body.y, RAYWHITE);
				}
				break;
			case Mid:
				if (_isMoving) {
					if (p1AnimTimer <= p1AnimTime / 4) {
						DrawTexture(_F1_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime / 4 && p1AnimTimer <= p1AnimTime / 2) {
						DrawTexture(_F2_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime / 2 && p1AnimTimer <= p1AnimTime - p1AnimTime / 4) {
						DrawTexture(_F3_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime - p1AnimTime / 4 && p1AnimTimer <= p1AnimTime) {
						DrawTexture(_F2_Mid, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime) {
						p1AnimTimer = 0.0f;
					}
				}
				else {
					DrawTexture(_F1_Mid, _body.x, _body.y, RAYWHITE);
				}
				break;
			case Down:
				if (_isMoving) {
					if (p1AnimTimer <= p1AnimTime / 4) {
						DrawTexture(_F1_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime / 4 && p1AnimTimer <= p1AnimTime / 2) {
						DrawTexture(_F2_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime / 2 && p1AnimTimer <= p1AnimTime - p1AnimTime / 4) {
						DrawTexture(_F3_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime - p1AnimTime / 4 && p1AnimTimer <= p1AnimTime) {
						DrawTexture(_F2_Down, _body.x, _body.y, RAYWHITE);
					}
					if (p1AnimTimer > p1AnimTime) {
						p1AnimTimer = 0.0f;
					}
				}
				else {
					DrawTexture(_F1_Down, _body.x, _body.y, RAYWHITE);
				}
				break;
			}
		}
		if (_isDead) {
			DrawRectangle(_body.x - _body.height + _body.width, _body.y + _body.height - _body.width, _body.height, _body.width, MAROON);
			DrawText("YOU GOT ME!", _body.x, _body.y, textFontSize, MAROON);
		}
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] != NULL) {
				_p1Bullets[i]->draw();
			}
		}
		for (int i = 0; i < _bulletsLeft; i++) {
			DrawRectangle(screenWidth / 20 + (i*(bulletHeight * 2)), screeenHeight - screeenHeight / 20 - bulletWidth, bulletHeight, bulletWidth, RAYWHITE);
		}
	}

	void Player1::move() {
		float time = GetFrameTime();
		if (IsKeyDown(KEY_W) && _body.y > 0) {
			_body.y -= playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_S) && _body.y < screeenHeight - _body.height) {
			_body.y += playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_A) && _body.x > 0 && !_isDead) {
			_body.x -= playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_D) && _body.x <= screenWidth / 4 && !_isDead) {
			_body.x += playerSpeed * time;
			_isMoving = true;
		}
		if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
			_isMoving = false;
		}
	}

	void Player1::fireBullet() {
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] == NULL) {
				if (IsKeyPressed(KEY_J)) {
					_p1Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
					_p1Bullets[i]->setDirectionX(1 - bulletAimRate);
					_p1Bullets[i]->setDirectionY((-1 * bulletAimRate));
					_bulletsLeft--;
					_aim = Up;
					break;
				}
				if (IsKeyPressed(KEY_K)) {
					_p1Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
					_p1Bullets[i]->setDirectionX(1);
					_p1Bullets[i]->setDirectionY(0);
					_bulletsLeft--;
					_aim = Mid;
					break;
				}
				if (IsKeyPressed(KEY_L)) {
					_p1Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
					_p1Bullets[i]->setDirectionX(1 - bulletAimRate);
					_p1Bullets[i]->setDirectionY(bulletAimRate);
					_bulletsLeft--;
					_aim = Down;
					break;
				}
			}
		}
	}

	void Player1::moveBullet() {
		float time = GetFrameTime();
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] != NULL) {
				if (_p1Bullets[i]->getBodyX() < screenWidth) {
					_p1Bullets[i]->setBodyX(_p1Bullets[i]->getBodyX() + ((_p1Bullets[i]->getSpeed() * time) * _p1Bullets[i]->getDirectionX()));
					_p1Bullets[i]->setBodyY(_p1Bullets[i]->getBodyY() + ((_p1Bullets[i]->getSpeed() * time) * _p1Bullets[i]->getDirectionY()));
				}
				if (_p1Bullets[i]->getBodyY() > screeenHeight - _p1Bullets[i]->getBodyHeight() || _p1Bullets[i]->getBodyY() < 0) {
					_p1Bullets[i]->setDirectionY(-1 * (_p1Bullets[i]->getDirectionY()));
				}
			}
		}
	}

	void Player1::checkP2BulletCollision(Rectangle body) {
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] != NULL) {
				if (CheckCollisionRecs(_p1Bullets[i]->getBody(), body) && !_p1Bullets[i]->getHasScored() && !p2Dies) {
					_score = _score + 1;
					_p1Bullets[i]->setHasScored(true);
					p2Dies = true;
					PlaySound(_wScream);
				}
				if (!CheckCollisionRecs(_p1Bullets[i]->getBody(), body)) {
					_p1Bullets[i]->setHasScored(false);
				}
			}
		}
	}

	void Player1::die(bool& die) {
		if (die) {
			_isDead = true;
			p1DeadTime -= GetFrameTime();
			if (p1DeadTime <= 0) {
				p1DeadTime = resetP1DeadTime;
				_isDead = false;
				die = false;
			}
		}
	}

	void Player1::reload() {
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] != NULL) {
				_p1Bullets[i] = NULL;
			}
		}
		_bulletsLeft = p1MaxBullets;
	}

	void runP1AnimTimer() {
		p1AnimTimer += GetFrameTime();
	}
}