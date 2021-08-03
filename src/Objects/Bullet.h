#ifndef BULLET_H
#define BULLET_H
#include "raylib.h"
#include "Interfaces/IColisionable.h"

namespace GunFight {

	class Bullet : public IColisionable {
	private:
		std::string _tag;
		Rectangle _body;
		float _speed;
		Vector2 _direction;
		bool _isActive;
		Sound _hitSFX;
	public:
		Bullet(float width, float height);
		~Bullet();
		float GetBodyX();
		float GetBodyY();
		float GetBodyHeight();
		float GetSpeed();
		float GetDirectionX();
		float GetDirectionY();
		bool GetIsActive();
		void SetBody(Rectangle body);
		void SetBodyX(float x);
		void SetBodyY(float y);
		void SetSpeed(float speed);
		void SetDirectionX(float x);
		void SetDirectionY(float y);
		void SetIsActive(bool isActive);
		virtual std::string GetTag();
		virtual Rectangle GetBody();
		virtual void OnCollisionEnter(IColisionable* other);
		virtual void OnCollisionStay(IColisionable* other);
		virtual void OnCollisionExit(IColisionable* other);
		void Update();
		void Draw();
		void Move();
	};
}
#endif