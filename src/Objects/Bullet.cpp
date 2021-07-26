#include "Bullet.h"
#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {

	static const float bulletSpeed = 2000.0f;

	Bullet::Bullet(float x, float y, float width, float height) {
		_body.x = x;
		_body.y = y;
		_body.width = width;
		_body.height = height;
		_speed = bulletSpeed;
		_direction.x = NULL;
		_direction.y = NULL;
	}

	Bullet::~Bullet() {
	}

	void Bullet::setBody(Rectangle body) {
		_body = body;
	}

	void Bullet::setBodyX(float x) {
		_body.x = x;
	}

	void Bullet::setBodyY(float y) {
		_body.y = y;
	}

	void Bullet::setSpeed(float speed) {
		_speed = speed;
	}

	void Bullet::setDirectionX(float x) {
		_direction.x = x;
	}

	void Bullet::setDirectionY(float y) {
		_direction.y = y;
	}

	Rectangle Bullet::getBody() {
		return _body;
	}

	float Bullet::getBodyX() {
		return _body.x;
	}

	float Bullet::getBodyY() {
		return _body.y;
	}

	float Bullet::getBodyHeight() {
		return _body.height;
	}

	float Bullet::getSpeed() {
		return _speed;
	}

	float Bullet::getDirectionX() {
		return _direction.x;
	}

	float Bullet::getDirectionY() {
		return _direction.y;
	}

	void Bullet::update() {
		move();
	}

	void Bullet::move() {
		float time = GetFrameTime();
		if (_body.x < screenWidth) {
			_body.x = (_body.x + _speed * time * _direction.x);
			_body.y = (_body.y + _speed * time * _direction.y);
		}
		if (_body.y > screeenHeight - _body.height || _body.y < 0) {
			_direction.y = -_direction.y;
		}
	}

	void Bullet::draw() {
		DrawRectangleRec(_body, RAYWHITE);
	}
}