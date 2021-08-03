#pragma once
#include "Obstacles.h"

namespace GunFight {
	
	class Cactus : public Obstacles
	{
		Rectangle _frameRec;
	public:
		Cactus(Vector2 pos);
		void restoreCactus();
		virtual void draw();
		virtual void OnCollisionEnter(IColisionable* other);
		virtual void OnCollisionStay(IColisionable* other);
		virtual void OnCollisionExit(IColisionable* other);
	};

}