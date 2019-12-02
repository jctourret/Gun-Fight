#include "Player1.h"
#include "System/Screen.h"
#include "Player2.h"

const int playerSpeed = 1000;

float p1DeadTime = 2.0f;

const float bulletAimRate = 0.25f;
const float bulletWidth = 20;
const float bulletHeight = 10;
const float resetP1DeadTime = p1DeadTime;

Player1::Player1(float x, float y, float width, float height){
	_body.x = x;
	_body.y = y;
	_body.width = width;
	_body.height = height;
	for (int i = 0; i < p1MaxBullets; i++) {
		if (_p1Bullets[i] != NULL) {
			_p1Bullets[i] = NULL;
		} 
	}
	_bulletsFired = 0;
	_score = NULL;
	_isDead = false;
}

Player1::~Player1(){
	for (int i = 0; i < p1MaxBullets; i++) {
		if (_p1Bullets[i] != NULL) {
			delete _p1Bullets[i];
		}
	}
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

int Player1::getBulletsFired() {
	return _bulletsFired;
}

int Player1::getScore() {
	return _score;
}

bool Player1::getIsDead() {
	return _isDead;
}

void Player1::draw() {
	if (!_isDead) {
		DrawRectangleRec(_body, MAROON);
	}
	if (_isDead) {
		DrawRectangle(_body.x, _body.y + _body.height - _body.width, _body.height, _body.width, MAROON);
		DrawText("YOU GOT ME!", _body.x, _body.y, 20, MAROON);
	}
	for (int i = 0; i < p1MaxBullets; i++) {
		if (_p1Bullets[i] != NULL) {
			_p1Bullets[i]->draw();
		}
	}
}
void Player1::move() {
	float time = GetFrameTime();
	if (IsKeyDown(KEY_W)&&_body.y>0){
		_body.y -= playerSpeed * time;
	}
	if (IsKeyDown(KEY_S)&&_body.y<screeenHeight-_body.height) {
		_body.y += playerSpeed * time;
	}
}
void Player1::fireBullet() {
	for (int i = 0; i < p1MaxBullets; i++) {
		if (_p1Bullets[i] == NULL) {
			if (IsKeyPressed(KEY_J)) {
				_p1Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
				_p1Bullets[i]->setDirectionX(1 - bulletAimRate);
				_p1Bullets[i]->setDirectionY((-1 * bulletAimRate));
				_bulletsFired++;
				break;
			}
			if (IsKeyPressed(KEY_K)) {
				_p1Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
				_p1Bullets[i]->setDirectionX(1);
				_p1Bullets[i]->setDirectionY(0);
				_bulletsFired++;
				break;
			}
			if (IsKeyPressed(KEY_L)) {
				_p1Bullets[i] = new Bullet(_body.x + _body.width, _body.y + (_body.height / 2), bulletWidth, bulletHeight);
				_p1Bullets[i]->setDirectionX(1 - bulletAimRate);
				_p1Bullets[i]->setDirectionY(bulletAimRate);
				_bulletsFired++;
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
	_bulletsFired = 0;
}