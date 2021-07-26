#include "Weapon.h"
#include "System/Screen.h"

namespace GunFight {

	Weapon::Weapon() {
		_maxBullets = 6;
		_bulletsLeft = _maxBullets;
		_bulletWidth = 10;
		_bulletHeight = 5;
	}
	Weapon::~Weapon() {
		for (int i = _bullets.size()-1; i < 0; i--)
		{
			if (_bullets[i] != NULL)
			{
				delete _bullets[i];
				_bullets.pop_back();
			}
		}
	}

	void Weapon::fireBullet(Rectangle body, Vector2 direction) {
		
	}

	void Weapon::update() {
		for (int i = 0 ; i < _bullets.size() ; i++) {
			_bullets[i]->update();
		}
	}

	void Weapon::draw() {
		for (int i = 0; i < _bullets.size(); i++) {
			_bullets[i]->draw();
		}
	}
}