
#include "raylib.h"
#include "Bullet.h"

const int p2MaxBullets = 6;

class Player2 {
private:
	Rectangle _body;
	Bullet* _p2Bullets[p2MaxBullets];
	int _bulletsFired;
	int _score;
	bool _isDead;
public:
	Player2(float x, float y, float width, float height);
	~Player2();
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
	void checkP1BulletCollision(Rectangle body);
	bool p1Dies = false;
	void die(bool& die);
	void reload();
};


