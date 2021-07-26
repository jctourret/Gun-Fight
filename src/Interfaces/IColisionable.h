#pragma once
#include "raylib.h"

namespace GunFight {

	class IColisionable
	{
	public:
		virtual Rectangle GetBody() = 0;

		virtual void OnCollision(IColisionable other) = 0;

}