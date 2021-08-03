#pragma once
#include "raylib.h"
#include <vector>
#include <string>

namespace GunFight {

	class IColisionable
	{
	public:

		IColisionable();

		virtual Rectangle GetBody();

		virtual std::string GetTag();

		virtual void OnCollisionStay(IColisionable* other);

		virtual void OnCollisionEnter(IColisionable* other);

		virtual void OnCollisionExit(IColisionable* other);

	};
}