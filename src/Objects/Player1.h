#ifndef PLAYER1_H
#define PLAYER1_H
#include "raylib.h"
#include "Bullet.h"

namespace GunFight {

	const int p1MaxBullets = 6;

	extern enum Aim {
		Up,
		Mid,
		Down,
	};

	class Player1 {
	private:
		Rectangle _body;
		Vector2 _pos;
		Bullet* _p1Bullets[p1MaxBullets];
		int _bulletsLeft;
		int _score;
		Aim _aim;
		bool _isDead;
		bool _isMoving;
		Texture2D _spriteSheet;
		int _sheetColumns;
		int _sheetRows;
		Rectangle _frameRec;
		float _frameTime;
		Sound _deathScream;
	public:
		Player1(Vector2 pos, float width, float height);
		~Player1();
		void setBody(Rectangle body);
		void setX(float x);
		void setY(float y);
		void setWidth(float width);
		void setHeight(float height);
		void setScore(int score);
		Rectangle getBody();
		int getBulletsLeft();
		int getScore();
		bool getIsDead();
		void draw();
		void move();
		void fireBullet();
		void moveBullet();
		void checkP2BulletCollision(Rectangle body);
		void die(bool& die);
		void reload();
		bool p2Dies = false;
	};
}
#endif