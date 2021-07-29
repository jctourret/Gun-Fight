#pragma once
#include "raylib.h"
#include <memory>
#include <string>

namespace GunFight {

	class IColisionable
	{
	public:
		virtual Rectangle GetBody() = 0;

		virtual void OnCollisionStay(std::shared_ptr<IColisionable> other) = 0;

		virtual void OnCollisionEnter(std::shared_ptr<IColisionable> other) = 0;

		virtual void OnCollisionExit(std::shared_ptr<IColisionable> other) = 0;

		virtual std::string GetTag() = 0;
	};
}