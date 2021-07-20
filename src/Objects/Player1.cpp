#include "Player1.h"
#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {
	
	int currentFrame = 0;

	float animTimer = 0.0f;
	float frameTimer = 0.0f;
	float p1DeadTime = 2.0f;

	const int playerSpeed = 500;
	const int textFontSize = 20;

	const float bulletAimRate = 0.35f;
	const float bulletWidth = 20;
	const float bulletHeight = 10;
	const float resetP1DeadTime = p1DeadTime;
	const float animTime = 1.0f;

	Player1::Player1(Vector2 pos, float width, float height) {
		_body.x = pos.x;
		_body.y = pos.y;
		_pos = pos;
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
		_spriteSheet = LoadTexture("../res/assets/img/rightCharacter.png");
		_sheetColumns = 4;
		_sheetRows = 3;
		_frameRec.x = 0;
		_frameRec.y = 0;
		_frameRec.width = _spriteSheet.width / _sheetColumns;
		_frameRec.height = _spriteSheet.height / _sheetRows;
		_frameTime = animTime/_sheetColumns;
		_deathScream = LoadSound("../res/assets/snd/wScream.ogg");
	}

	Player1::~Player1() {
		for (int i = 0; i < p1MaxBullets; i++) {
			if (_p1Bullets[i] != NULL) {
				delete _p1Bullets[i];
			}
		}
		UnloadTexture(_spriteSheet);
		UnloadSound(_deathScream);
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
		if (!_isDead) {
			DrawTextureRec(_spriteSheet,_frameRec,_pos,WHITE);
		}
		else {
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
		animTimer += time;
		frameTimer += time;
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

		if (_isMoving) {
			if (frameTimer > _frameTime)
			{
				currentFrame++;
				_frameRec.x = currentFrame * _frameRec.width;
				frameTimer = 0.0f;
			}
			if (animTimer > animTime) {
				animTimer = 0.0f;
			}
		}
		else {
			currentFrame = 0;
		}
		switch (_aim) {
		case Up:
			_frameRec.y = 0;
			break;
		case Mid:
			_frameRec.y = _frameRec.height;
			break;
		case Down:
			_frameRec.y = _frameRec.height * 2;
			break;
		}
		_pos = { _body.x,_body.y };
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
					PlaySound(_deathScream);
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
}