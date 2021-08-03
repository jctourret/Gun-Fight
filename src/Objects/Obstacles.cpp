#include "Obstacles.h"

namespace GunFight
{
	Obstacles::Obstacles(Vector2 pos, std::string tag, std::string texturePath)
	{
		_tag = tag;
		_sheet = LoadTexture(texturePath.c_str());
		_pos = pos;
		_body.x = pos.x;
		_body.y = pos.y;
		_body.width = _sheet.width;
		_body.height = _sheet.height;
		_isActive = false;
	}
	void Obstacles::update()
	{
	}
	void Obstacles::draw()
	{
	}
	bool Obstacles::getIsActive()
	{
		return _isActive;
	}
	void Obstacles::setIsActive(bool isActive)
	{
		_isActive = isActive;
	}
	Rectangle Obstacles::GetBody()
	{
		return _body;
	}
	std::string Obstacles::GetTag()
	{
		return _tag;
	}
	void Obstacles::OnCollisionEnter(IColisionable* other)
	{
	}
	void Obstacles::OnCollisionStay(IColisionable* other)
	{
	}
	void Obstacles::OnCollisionExit(IColisionable* other)
	{
	}
}