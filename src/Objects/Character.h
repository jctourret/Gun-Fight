#ifndef CHARACTER_H
#define CHARACTER_H
#include "System/Animation.h"
#include "Revolver.h"
#include "Shotgun.h"
#include "Interfaces/IColisionable.h"

namespace GunFight {

	class Character : public IColisionable
	{
	protected:
		string _tag;
		Weapon* _currentWeapon;
		Aim _aim;
		Rectangle _body;
		Rectangle _frameRec;
		Rectangle _deathFrameRec;
		Vector2 _pos;
		Texture2D _spriteSheet;
		Texture2D _deathSheet;
		Sound _deathScream;
		int _sheetColumns;
		int _sheetRows;
		float _frameTime;
		bool _isDead;
	public:
		Character(Vector2 pos, string sheetPath, string deathPath, int sheetColumns, int sheetRows);
		~Character();
		Weapon* GetWeapon();
		bool GetIsDead();
		void SetBody(Rectangle body);
		void SetX(float x);
		void SetY(float y);
		void SetWidth(float width);
		void SetHeight(float height);
		void SetCurrentWeapon(Weapon* weapon);
		void SetIsDead(bool isDead);
		virtual void Update();
		virtual void Move();
		virtual void FireWeapon();
		virtual void Draw();
		Rectangle GetBody() override;
		string GetTag() override;
		virtual void OnCollisionStay(IColisionable* other);
		virtual void OnCollisionEnter(IColisionable* other);
		virtual void OnCollisionExit(IColisionable* other);
	};
}
#endif