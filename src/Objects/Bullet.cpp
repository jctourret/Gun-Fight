#include "Bullet.h"
#include "System/Screen.h"

const float bulletSpeed = 2000.0f;

Bullet::Bullet(float x, float y, float width, float height){
	_body.x = x;
	_body.y = y;
	_body.width = width;
	_body.height = height;
	_speed = bulletSpeed;
	_direction.x=NULL;
	_direction.y=NULL;
	_hasScored = false;
}

Bullet::~Bullet(){
}

void Bullet::setBody(Rectangle body) {
	_body = body;
}

void Bullet::setBodyX(float x) {
	_body.x=x;
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

void Bullet::setHasScored(bool hasScored) {
	_hasScored = hasScored;
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

bool Bullet::getHasScored(){
	return _hasScored;
}

void Bullet::draw() {
	DrawRectangleRec(_body, RAYWHITE);
}