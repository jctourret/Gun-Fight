#pragma once
#include "Interfaces/IColisionable.h"

namespace GunFight {
	class Obstacles : public IColisionable
	{
	protected:
		std::string _tag;
		Rectangle _body;
		Vector2 _pos;
		Texture2D _sheet;
		bool _isActive;
		float _startingPointX;
		float _startingPointY;
		float _startingSizeX;
		float _startingSizeY;
	public:
		Obstacles(Vector2 pos, std::string tag, std::string texturePath);
		virtual void update();
		virtual void draw();
		bool getIsActive();
		void setIsActive(bool isActive);
		Rectangle GetBody();
		std::string GetTag();
		virtual void OnCollisionEnter(IColisionable* other);
		virtual void OnCollisionStay(IColisionable* other);
		virtual void OnCollisionExit(IColisionable* other);

	};


}
