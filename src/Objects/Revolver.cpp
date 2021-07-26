#include "Revolver.h"

namespace GunFight {

	Revolver::Revolver() : Weapon() {
		_maxBullets = 6;
		_bulletsLeft = _maxBullets;
	}

	Revolver::~Revolver() {

	}

	void Revolver::fireBullet(Rectangle body, Vector2 direction) {
		if (_bullets.size() < _maxBullets && _bulletsLeft > 0) {
			Bullet* bullet = new Bullet(body.x + body.width, body.y + (body.height / 2), _bulletWidth, _bulletHeight);
			_bullets.push_back(bullet);
			_bullets.back()->setDirectionX(direction.x);
			_bullets.back()->setDirectionY(direction.y);
			_bulletsLeft--;
		}
	}
}