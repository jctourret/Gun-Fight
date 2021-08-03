#pragma once
#include "Obstacles.h"

namespace GunFight {
	class Tree : public Obstacles
	{
		Rectangle _frameRec;
	public:
		Tree(Vector2 pos);
		void restoreTree();
		virtual void draw();
		virtual void OnCollisionEnter(IColisionable* other);
		virtual void OnCollisionStay(IColisionable* other);
		virtual void OnCollisionExit(IColisionable* other);
	};

}