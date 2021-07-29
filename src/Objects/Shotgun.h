#pragma once
#include "Weapon.h"
namespace GunFight {
	class Shotgun: public Weapon
	{

	public:
		Shotgun();
		virtual void fireBullet(Rectangle body, Vector2 direction);
	};
}