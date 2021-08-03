#pragma once
#include "Obstacles.h"

namespace GunFight {
	
	class Wagon : public Obstacles
	{
		Rectangle _frameRec;
	public:
		Wagon(Vector2 pos);
		virtual void update();
		virtual void draw();
		virtual void OnCollisionEnter(IColisionable* other);
		virtual void OnCollisionStay(IColisionable* other);
		virtual void OnCollisionExit(IColisionable* other);
	};

}