#ifndef CHARACTER_H
#define CHARACTER_H
#include "Revolver.h"
#include "Interfaces/IColisionable.h"

namespace GunFight {


	class Character : public IColisionable
	{
	protected:
		string _tag;
		Rectangle _body;
		Vector2 _pos;
		Weapon* _currentWeapon;
		Aim _aim;
		int _score;
		Texture2D _spriteSheet;
		int _sheetColumns;
		int _sheetRows;
		Rectangle _frameRec;
		float _frameTime;
		Sound _deathScream;
	public:
		Character();
		Character(Vector2 pos, string sheetPath);
		~Character();
		void setBody(Rectangle body);
		void setX(float x);
		void setY(float y);
		void setWidth(float width);
		void setHeight(float height);
		void setScore(int score);
		virtual void update();
		virtual void move();
		virtual void fireWeapon();
		void draw();
		Rectangle GetBody() override;
		string GetTag() override;
		virtual void OnCollisionStay(std::shared_ptr<IColisionable> other) = 0;
		virtual void OnCollisionEnter(std::shared_ptr<IColisionable> other) = 0;
		virtual void OnCollisionExit(std::shared_ptr<IColisionable> other) = 0;
	};
}


#endif