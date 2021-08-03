#pragma once
#include "Weapon.h"
namespace GunFight {
	class Shotgun: public Weapon
	{

	public:
		Shotgun();
		virtual void FireBullet(Vector2 shootPosition, Vector2 direction);
	};
}