#include "Weapon.h"
#include "System/Screen.h"
#include <iostream>

namespace GunFight {

	Weapon::Weapon(string soundPath)
	{
		_maxBullets = 0;
		_bulletsLeft = 0;
		_shotSFX = LoadSound(soundPath.c_str());
	}
	Weapon::~Weapon()
	{
		if (_bullets.size() != 0)
		{
			for (int i = _bullets.size() - 1; i > 0; i--)
			{
				if (_bullets[i] != NULL)
				{
					delete _bullets[i];
					_bullets.pop_back();
				}
			}
		}
	}

	float Weapon::GetBulletsLeft()
	{
		return _bulletsLeft;
	}

	vector<Bullet*> Weapon::GetBullets()
	{
		return _bullets;
	}

	void Weapon::FireBullet(Vector2 shootPosition, Vector2 direction) {

	}

	void Weapon::Update() {
		for (int i = 0 ; i < _bullets.size() ; i++) {
			_bullets[i]->Update();
		}
	}

	void Weapon::Draw() {
		for (int i = 0; i < _bullets.size(); i++) {
			_bullets[i]->Draw();
		}
	}
	void Weapon::Reload() {
		_bulletsLeft = _maxBullets;
	}
}