#include "Player2.h"
#include "System/Screen.h"

const int playerSpeed = 1000;

float p2DeadTime = 2.0f;

const float bulletAimRate = 0.15f;
const float bulletWidth = 20;
const float bulletHeight = 10;
const float resetP2DeadTime = 2.0f;

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
	_bulletsFired = 0;
	_score = NULL;
	_isDead = false;
}

Player2::~Player2() {
	for (int i = 0; i < p2MaxBullets; i++) {
		if (_p2Bullets[i] != NULL) {
			delete _p2Bullets[i];
		}
	}
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

int Player2::getBulletsFired() {
	return _bulletsFired;
}

int Player2::getScore() {
	return _score;
}

bool Player2::getIsDead() {
	return _isDead;
}

void Player2::draw() {
	if (!_isDead) {
		DrawRectangleRec(_body, MAROON);
	}
	if (_isDead) {
		DrawRectangle(_body.x,_body.y+_body.height-_body.width,_body.height, _body.width,MAROON);
		DrawText("YOU GOT ME!", _body.x, _body.y, 20, MAROON);
	}
	for (int i = 0; i < p2MaxBullets; i++) {
		if (_p2Bullets[i] != NULL) {
			_p2Bullets[i]->draw();
		}
	}
}

void Player2::move() {
	float time = GetFrameTime();
	if (IsKeyDown(KEY_UP) && _body.y > 0 && !_isDead) {
		_body.y -= playerSpeed * time;
	}
	if (IsKeyDown(KEY_DOWN) && _body.y < screeenHeight - _body.height && !_isDead) {
		_body.y += playerSpeed * time;
	}
}

void Player2::fireBullet() {
	for (int i = 0; i < p2MaxBullets; i++) {
		if (_p2Bullets[i] == NULL&&!_isDead) {
			if (IsKeyPressed(KEY_KP_1)) {
				_p2Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
				_p2Bullets[i]->setDirectionX(1 - bulletAimRate);
				_p2Bullets[i]->setDirectionY((-1 * bulletAimRate));
				break;
				_bulletsFired++;
			}
			if (IsKeyPressed(KEY_KP_2)) {
				_p2Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
				_p2Bullets[i]->setDirectionX(1);
				_p2Bullets[i]->setDirectionY(0);
				_bulletsFired++;
				break;
			}
			if (IsKeyPressed(KEY_KP_3)) {
				_p2Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
				_p2Bullets[i]->setDirectionX(1 - bulletAimRate);
				_p2Bullets[i]->setDirectionY(bulletAimRate);
				_bulletsFired++;
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
		if (_p2Bullets[i] != NULL&& !_isDead) {
			if (CheckCollisionRecs(_p2Bullets[i]->getBody(), body) && !_p2Bullets[i]->getHasScored() && !p1Dies) {
				_score = _score + 1;
				_p2Bullets[i]->setHasScored(true);
				p1Dies = true;
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
	_bulletsFired = 0;
}