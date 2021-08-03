#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "Interfaces/IColisionable.h"
#include "Character.h"

namespace GunFight {

	enum class playerConfig { player1, player2 };


	class Player : public Character
	{
		Animation* _idleRevolverAimUp;
		Animation* _idleRevolverAimMid;
		Animation* _idleRevolverAimDown;
		Animation* _idleShotgunAimUp;
		Animation* _idleShotgunAimMid;
		Animation* _idleShotgunAimDown;
		Animation* _moveRevolverAimUp;
		Animation* _moveRevolverAimMid;
		Animation* _moveRevolverAimDown;
		Animation* _moveShotgunAimUp;
		Animation* _moveShotgunAimMid;
		Animation* _moveShotgunAimDown;
		Animation* _death;
		playerConfig _player;
		Vector2 moveXLimits;
		Vector2 moveYLimits;
	public:
		Player(string tag, playerConfig player,  Vector2 pos);
		~Player();
		virtual void Update();
		virtual void Draw();
		virtual void Move();
		virtual void FireWeapon();
		void UpdateAnimation();
		void UpdateWeapon();
		virtual void OnCollisionStay(IColisionable* other);
		virtual void OnCollisionEnter(IColisionable*  other);
		virtual void OnCollisionExit(IColisionable* other);
	};
}
#endif