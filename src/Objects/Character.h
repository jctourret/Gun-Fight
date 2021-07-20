#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include <string>

using namespace std;

namespace GunFight {


	extern enum Aim {
		Up,
		Mid,
		Down,
	};


	class Character
	{
	private:
		Rectangle _body;
		int _bulletsLeft;
		int _score;
		Aim _aim;
		bool _isDead;
		bool _isMoving;
		Texture2D _spriteSheet;
		Rectangle _frameRec;
		Sound _deathScream;
	public:
		Character(string sheetPath, string soundPath);
		~Character();
	};
}


#endif // !1
