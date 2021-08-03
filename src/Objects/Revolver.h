#pragma once
#include "Weapon.h"

namespace GunFight {

	class Revolver : public Weapon
	{
	public:
		Revolver();
		~Revolver();
	    virtual void FireBullet(Vector2 shootPosition, Vector2 direction);
	};

}
