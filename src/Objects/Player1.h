#ifndef PLAYER1_H
#define PLAYER1_H
#include "raylib.h"
#include "Interfaces/IColisionable.h"
#include "Character.h"

namespace GunFight {

	const int p1MaxBullets = 6;

	class Player : public Character, IColisionable
	{
	public:
		Player(Vector2 pos);
		~Player();
		Rectangle getBody();
		int getScore();
		bool getIsDead();
		void update();
		void draw();
		void move();
		void updateAnimation();
		void fireWeapon();
		void updateWeapon();
		void die(bool& die);
		void reload();
	};
}
#endif