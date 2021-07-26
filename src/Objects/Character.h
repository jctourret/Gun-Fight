#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "Revolver.h"
#include "Interfaces/IColisionable.h"
#include <string>

using namespace std;

namespace GunFight {


	class Character : IColisionable
	{
	protected:
		Rectangle _body;
		Vector2 _pos;
		Weapon* _currentWeapon;
		Aim _aim;
		int _score;
		bool _isDead;
		bool _isMoving;
		Texture2D _spriteSheet;
		int _sheetColumns;
		int _sheetRows;
		Rectangle _frameRec;
		float _frameTime;
		Sound _deathScream;
	public:
		Character();
		Character(string sheetPath, int sheetColumns, int sheetRows);
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
		virtual Rectangle GetBody();
		void draw();
	};
}


#endif // !1
