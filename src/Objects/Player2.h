#ifndef PLAYER2_H
#define PLAYER2_H
#include "raylib.h"
#include "Bullet.h"
#include "Player1.h"

namespace GunFight {

	const int p2MaxBullets = 6;

	class Player2 {
	private:
		Rectangle _body;
		Bullet* _p2Bullets[p2MaxBullets];
		int _bulletsLeft;
		int _score;
		Aim _aim;
		bool _isDead;
		bool _isMoving;
		Texture2D _F1_Up;
		Texture2D _F1_Mid;
		Texture2D _F1_Down;
		Texture2D _F2_Up;
		Texture2D _F2_Mid;
		Texture2D _F2_Down;
		Texture2D _F3_Up;
		Texture2D _F3_Mid;
		Texture2D _F3_Down;
		Sound _deathScream;
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
		int getBulletsLeft();
		bool getIsDead();
		void draw();
		void move();
		void fireBullet();
		void moveBullet();
		void die(bool& die);
		void reload();
		bool p1Dies = false;
	};
}
#endif
