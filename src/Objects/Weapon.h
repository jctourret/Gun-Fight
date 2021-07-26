#pragma once
#include "Bullet.h"

#include <vector>

using namespace std;

namespace GunFight
{
	enum Aim {
		Up,
		Mid,
		Down,
	};

	class Weapon
	{
	protected:
		vector<Bullet*> _bullets;
		int _maxBullets;
		float _bulletWidth;
		float _bulletHeight;
		float _bulletsLeft;
	public:
		Weapon();
		~Weapon();
		virtual void fireBullet(Rectangle body, Vector2 direction);
		virtual void update();
		void draw();
	};
}