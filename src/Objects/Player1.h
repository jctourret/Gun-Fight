#ifndef PLAYER1_H
#define PLAYER1_H
#include "raylib.h"
#include "Interfaces/IColisionable.h"
#include "Character.h"

namespace GunFight {

	class Player : public Character
	{
	public:
		Player(Vector2 pos, string texturePath);
		~Player();
		Rectangle getBody();
		int getScore();
		void update();
		void draw();
		void move();
		void updateAnimation();
		void fireWeapon();
		void updateWeapon();
		void reload();
		void OnCollisionStay(std::shared_ptr<IColisionable> other) override;
		void OnCollisionEnter(std::shared_ptr<IColisionable> other) override;
		void OnCollisionExit(std::shared_ptr<IColisionable> other) override;
	};
}
#endif