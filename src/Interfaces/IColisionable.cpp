#include "IColisionable.h"


namespace GunFight {

	IColisionable::IColisionable() {

	}

	Rectangle IColisionable::GetBody()
	{
		return Rectangle();
	}

	void IColisionable::OnCollisionStay(IColisionable* other)
	{
	}

	void IColisionable::OnCollisionEnter(IColisionable* other)
	{
	}

	void IColisionable::OnCollisionExit(IColisionable* other)
	{
	}

	std::string GunFight::IColisionable::GetTag()
	{
		return std::string();
	}
}