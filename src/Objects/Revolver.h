#pragma once
#include "Weapon.h"

namespace GunFight {

	class Revolver : public Weapon
	{

	public:
		Revolver();
		~Revolver();
	    virtual void fireBullet(Rectangle body, Vector2 direction);
	};

}
