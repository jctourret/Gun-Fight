#pragma once
#include "Bullet.h"

#include <vector>

using namespace std;

namespace GunFight
{
	enum class Aim {
		Up,
		Mid,
		Down,
	};

	class Weapon
	{
	protected:
		vector<Bullet*> _bullets;
		int _maxBullets;
		float _bulletsLeft;
		Sound _shotSFX;
	public:
		Weapon(string soundPath);
		~Weapon();
		float GetBulletsLeft();
		vector<Bullet*> GetBullets();
		virtual void FireBullet(Vector2 shootPosition, Vector2 direction);
		virtual void Update();
		void Reload();
		void Draw();
	};
}