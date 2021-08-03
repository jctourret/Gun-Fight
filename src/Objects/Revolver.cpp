#include "Revolver.h"

namespace GunFight {

	float revolverBulletWidth = 10.0f;
	float revolverBulletHeight = 5.0f;

	Revolver::Revolver() : Weapon("res/assets/snd/LittleRobotSoundFactory_RevolverShot.wav") {
		_maxBullets = 6;
		_bulletsLeft = _maxBullets;
		for (int i = 0; i < _maxBullets; i++)
		{
			_bullets.push_back(new Bullet(revolverBulletWidth, revolverBulletHeight));
		}
	}

	Revolver::~Revolver() {

	}

	void Revolver::FireBullet(Vector2 shootPosition, Vector2 direction)
	{
		if (_bulletsLeft > 0)
		{

			for (int i = 0; i < _bullets.size(); i++)
			{

				if (!_bullets[i]->GetIsActive())
				{

					if (!IsSoundPlaying(_shotSFX))
					{
						PlaySound(_shotSFX);
					}

					_bullets[i]->SetIsActive(true);
					_bullets[i]->SetBodyX(shootPosition.x);
					_bullets[i]->SetBodyY(shootPosition.y);
					_bullets[i]->SetDirectionX(direction.x);
					_bullets[i]->SetDirectionY(direction.y);
					_bulletsLeft--;
					return;
				}
			}
		}
	}
}