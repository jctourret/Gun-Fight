#include "Shotgun.h"

namespace GunFight{
	int bulletsPerShot = 3;
	Vector2 shotgunSpread = { 0.0f,1.f };

	Shotgun::Shotgun() {
		_maxBullets = 2;
		_bulletsLeft = _maxBullets;
	}

	void Shotgun::fireBullet(Rectangle body, Vector2 direction) {
		if (_bullets.size()/bulletsPerShot < _maxBullets && _bulletsLeft > 0) {
			Bullet* bullet = new Bullet(body.x + body.width, body.y + (body.height / 2), _bulletWidth, _bulletHeight);
			_bullets.push_back(bullet);
			_bullets.back()->setDirectionX(direction.x-shotgunSpread.x);
			_bullets.back()->setDirectionY(direction.y-shotgunSpread.y);


			bullet = new Bullet(body.x + body.width, body.y + (body.height / 2), _bulletWidth, _bulletHeight);
			_bullets.push_back(bullet);
			_bullets.back()->setDirectionX(direction.x);
			_bullets.back()->setDirectionY(direction.y);

			bullet = new Bullet(body.x + body.width, body.y + (body.height / 2), _bulletWidth, _bulletHeight);
			_bullets.push_back(bullet);
			_bullets.back()->setDirectionX(direction.x-shotgunSpread.x);
			_bullets.back()->setDirectionY(direction.y+shotgunSpread.y);

			_bulletsLeft--;
		}
	}
}