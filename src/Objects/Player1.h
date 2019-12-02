#pragma once
#include "raylib.h"
#include "Bullet.h"

const int p1MaxBullets = 6;

class Player1 {
private:
	Rectangle _body;
	Bullet* _p1Bullets[p1MaxBullets];
	int _bulletsFired;
	int _score;
	bool _isDead;
public:
	Player1(float x, float y, float width, float height);
	~Player1();
	void setBody(Rectangle body);
	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float height);
	void setScore(int score);
	Rectangle getBody();
	int getBulletsFired();
	int getScore();
	bool getIsDead();
	void draw();
	void move();
	void fireBullet();
	void moveBullet();
	void checkP2BulletCollision(Rectangle body);
	bool p2Dies = false;
	void die(bool& die);
	void reload();
};

