#include "Player1.h"
#include "System/Screen.h"
#include <vector>

using namespace GunFight;

namespace GunFight {
	
	enum class Status {Idle,Moving,Dead};

	Vector2 auxCoords;
	Status status;

	const int playerSpeed = 500;
	const int shootingXOffset = 11;

	const int textFontSize = 20;

	const int sheetColumns = 9;
	const int sheetRows = 4;

	const float halfFireArc = 0.1f;


	Player::Player(string tag, playerConfig player, Vector2 pos)
		: Character(pos, "res/assets/img/AngryPlayerSheet.png", "res/assets/img/PlayerDead.png", sheetColumns, sheetRows)
	{
		_player = player;

		switch (player)
		{
		case playerConfig::player1:
			_idleRevolverAimUp = new Animation(1.0f,true);
			_idleRevolverAimUp->AddFrameCoords(0,0);

			_idleRevolverAimMid = new Animation(1.0f, true);
			_idleRevolverAimMid->AddFrameCoords(3, 0);

			_idleRevolverAimDown = new Animation(1.0f, true);
			_idleRevolverAimDown->AddFrameCoords(6, 0);

			_idleShotgunAimUp = new Animation(1.0f, true);
			_idleShotgunAimUp->AddFrameCoords(0, 2);

			_idleShotgunAimMid = new Animation(1.0f, true);
			_idleShotgunAimMid->AddFrameCoords(3, 2);

			_idleShotgunAimDown = new Animation(1.0f, true);
			_idleShotgunAimDown->AddFrameCoords(6, 2);

			_moveRevolverAimUp = new Animation(1.0f, true);
			_moveRevolverAimUp->AddFrameCoords(0, 0);
			_moveRevolverAimUp->AddFrameCoords(1, 0);
			_moveRevolverAimUp->AddFrameCoords(2, 0);
			_moveRevolverAimUp->AddFrameCoords(1, 0);

			_moveRevolverAimMid = new Animation(1.0f, true);
			_moveRevolverAimMid->AddFrameCoords(3, 0);
			_moveRevolverAimMid->AddFrameCoords(4, 0);
			_moveRevolverAimMid->AddFrameCoords(5, 0);
			_moveRevolverAimMid->AddFrameCoords(4, 0);

			_moveRevolverAimDown = new Animation(1.0f, true);
			_moveRevolverAimDown->AddFrameCoords(6, 0);
			_moveRevolverAimDown->AddFrameCoords(7, 0);
			_moveRevolverAimDown->AddFrameCoords(8, 0);
			_moveRevolverAimDown->AddFrameCoords(7, 0);

			_moveShotgunAimUp = new Animation(1.0f, true);
			_moveShotgunAimUp->AddFrameCoords(0, 2);
			_moveShotgunAimUp->AddFrameCoords(1, 2);
			_moveShotgunAimUp->AddFrameCoords(2, 2);
			_moveShotgunAimUp->AddFrameCoords(1, 2);

			_moveShotgunAimMid = new Animation(1.0f, true);
			_moveShotgunAimMid->AddFrameCoords(3, 2);
			_moveShotgunAimMid->AddFrameCoords(4, 2);
			_moveShotgunAimMid->AddFrameCoords(5, 2);
			_moveShotgunAimMid->AddFrameCoords(4, 2);

			_moveShotgunAimDown = new Animation(1.0f, true);
			_moveShotgunAimDown->AddFrameCoords(6, 2);
			_moveShotgunAimDown->AddFrameCoords(7, 2);
			_moveShotgunAimDown->AddFrameCoords(8, 2);
			_moveShotgunAimDown->AddFrameCoords(7, 2);

			_death = new Animation(1.0f, true);
			_death->AddFrameCoords(0,1);

			moveXLimits = {0,screenWidth/3-_body.width};
			moveYLimits = {screenHeight/4,screenHeight-_body.height};
				break;
		case playerConfig::player2:
			_idleRevolverAimUp = new Animation(1.0f, true);
			_idleRevolverAimUp->AddFrameCoords(0, 1);

			_idleRevolverAimMid = new Animation(1.0f, true);
			_idleRevolverAimMid->AddFrameCoords(3, 1);

			_idleRevolverAimDown = new Animation(1.0f, true);
			_idleRevolverAimDown->AddFrameCoords(6, 1);

			_idleShotgunAimUp = new Animation(1.0f, true);
			_idleShotgunAimUp->AddFrameCoords(0, 3);

			_idleShotgunAimMid = new Animation(1.0f, true);
			_idleShotgunAimMid->AddFrameCoords(3, 3);

			_idleShotgunAimDown = new Animation(1.0f, true);
			_idleShotgunAimDown->AddFrameCoords(6, 3);

			_moveRevolverAimUp = new Animation(1.0f, true);
			_moveRevolverAimUp->AddFrameCoords(0, 1);
			_moveRevolverAimUp->AddFrameCoords(1, 1);
			_moveRevolverAimUp->AddFrameCoords(2, 1);
			_moveRevolverAimUp->AddFrameCoords(1, 1);

			_moveRevolverAimMid = new Animation(1.0f, true);
			_moveRevolverAimMid->AddFrameCoords(3, 1);
			_moveRevolverAimMid->AddFrameCoords(4, 1);
			_moveRevolverAimMid->AddFrameCoords(5, 1);
			_moveRevolverAimMid->AddFrameCoords(4, 1);

			_moveRevolverAimDown = new Animation(1.0f, true);
			_moveRevolverAimDown->AddFrameCoords(6, 1);
			_moveRevolverAimDown->AddFrameCoords(7, 1);
			_moveRevolverAimDown->AddFrameCoords(8, 1);
			_moveRevolverAimDown->AddFrameCoords(7, 1);

			_moveShotgunAimUp = new Animation(1.0f, true);
			_moveShotgunAimUp->AddFrameCoords(0, 3);
			_moveShotgunAimUp->AddFrameCoords(1, 3);
			_moveShotgunAimUp->AddFrameCoords(2, 3);
			_moveShotgunAimUp->AddFrameCoords(1, 3);

			_moveShotgunAimMid = new Animation(1.0f, true);
			_moveShotgunAimMid->AddFrameCoords(3, 3);
			_moveShotgunAimMid->AddFrameCoords(4, 3);
			_moveShotgunAimMid->AddFrameCoords(5, 3);
			_moveShotgunAimMid->AddFrameCoords(4, 3);

			_moveShotgunAimDown = new Animation(1.0f, true);
			_moveShotgunAimDown->AddFrameCoords(6, 3);
			_moveShotgunAimDown->AddFrameCoords(7, 3);
			_moveShotgunAimDown->AddFrameCoords(8, 3);
			_moveShotgunAimDown->AddFrameCoords(7, 3);

			_death = new Animation(1.0f,true);
			_death->AddFrameCoords(0.0f,0.0f);

			moveXLimits = { screenWidth-screenWidth/3,screenWidth -_body.width};
			moveYLimits = { screenHeight / 4,screenHeight - _body.height };
			break;
		}
		_tag = tag;
		_frameRec.x = 0;
		_frameRec.y = 0;
		_frameRec.width = _spriteSheet.width / (float)_sheetColumns;
		_frameRec.height = _spriteSheet.height / (float)_sheetRows;
		status = GunFight::Status::Idle;
	}

	Player::~Player()
	{
		if (_idleRevolverAimUp != NULL)
		{
			delete _idleRevolverAimUp;
		}
		if (_idleRevolverAimMid != NULL)
		{
			delete _idleRevolverAimMid;
		}
		if (_idleRevolverAimDown != NULL)
		{
			delete _idleRevolverAimDown;
		}
		if (_idleShotgunAimUp != NULL)
		{
			delete _idleShotgunAimUp;
		}
		if (_idleShotgunAimMid != NULL)
		{
			delete _idleShotgunAimMid;
		}
		if (_idleShotgunAimDown != NULL)
		{
			delete _idleShotgunAimDown;
		}
		if (_moveRevolverAimUp != NULL)
		{
			delete _moveRevolverAimUp;
		}
		if (_moveRevolverAimMid != NULL)
		{
			delete _moveRevolverAimMid;
		}
		if (_moveRevolverAimDown != NULL)
		{
			delete _moveRevolverAimDown;
		}
		if (_moveShotgunAimUp != NULL)
		{
			delete _moveShotgunAimUp;
		}
		if (_moveShotgunAimUp != NULL)
		{
			delete _moveShotgunAimMid;
		}
		if (_moveShotgunAimDown != NULL)
		{
			delete _moveShotgunAimDown;
		}
		if (_death)
		{
			delete _death;
		}
	}

	void Player::Update()
	{
		Move();
		UpdateAnimation();
		FireWeapon();
		UpdateWeapon();
	}

	void Player::Draw()
	{
		if (!_isDead)
		{
			DrawTextureRec(_spriteSheet, _frameRec, _pos, WHITE);
		}
		else
		{
			DrawTextureRec(_deathSheet, _deathFrameRec, _pos, WHITE);
		}
		_currentWeapon->Draw();
	}

	void Player::Move()
	{
		float time = GetFrameTime();
		if(!_isDead)
		{
			switch (_player)
			{
			case GunFight::playerConfig::player1:
				if (IsKeyDown(KEY_W) && _body.y >= moveYLimits.x) {
					_body.y -= playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (IsKeyDown(KEY_S) && _body.y <= moveYLimits.y) {
					_body.y += playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (IsKeyDown(KEY_A) && _body.x > moveXLimits.x) {
					_body.x -= playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (IsKeyDown(KEY_D) && _body.x < moveXLimits.y) {
					_body.x += playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S) &&
					!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
					status = GunFight::Status::Idle;
				}
				break;
			case GunFight::playerConfig::player2:
				if (IsKeyDown(KEY_UP) && _body.y >= moveYLimits.x) {
					_body.y -= playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (IsKeyDown(KEY_DOWN) && _body.y <= moveYLimits.y) {
					_body.y += playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (IsKeyDown(KEY_LEFT) && _body.x > moveXLimits.x){
					_body.x -= playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (IsKeyDown(KEY_RIGHT) && _body.x < moveXLimits.y) {
					_body.x += playerSpeed * time;
					status = GunFight::Status::Moving;
				}
				if (!IsKeyDown(KEY_UP) && !IsKeyDown(KEY_DOWN) &&
					!IsKeyDown(KEY_LEFT) && !IsKeyDown(KEY_RIGHT)) {
					status = GunFight::Status::Idle;
				}
				break;
			default:
				break;
			}
		}
		_pos = { _body.x,_body.y };
	}

	void Player::UpdateAnimation()
	{
		switch (status)
		{
		case GunFight::Status::Idle:
			switch (_aim)
			{
			case GunFight::Aim::Up:
				if (dynamic_cast<Revolver*>(_currentWeapon) != NULL)
				{
					_idleRevolverAimUp->RunAnimation(_frameRec);
				}
				else
				{
					_idleShotgunAimUp->RunAnimation(_frameRec);
				}
				break;
			case GunFight::Aim::Mid:
				if (dynamic_cast<Revolver*>(_currentWeapon) != NULL)
				{
					_idleRevolverAimMid->RunAnimation(_frameRec);
				}
				else
				{
					_idleShotgunAimMid->RunAnimation(_frameRec);
				}
				break;
			case GunFight::Aim::Down:
				if (dynamic_cast<Revolver*>(_currentWeapon) != NULL)
				{
					_idleRevolverAimDown->RunAnimation(_frameRec);
				}
				else
				{
					_idleShotgunAimDown->RunAnimation(_frameRec);
				}
				break;
			default:
				break;
			}
			break;
		case GunFight::Status::Moving:
			switch (_aim)
			{
			case GunFight::Aim::Up:
				if (dynamic_cast<Revolver*>(_currentWeapon) != NULL)
				{
					_moveRevolverAimUp->RunAnimation(_frameRec);
				}
				else
				{
					_moveShotgunAimUp->RunAnimation(_frameRec);
				}
				break;
			case GunFight::Aim::Mid:
				if (dynamic_cast<Revolver*>(_currentWeapon) != NULL)
				{
					_moveRevolverAimMid->RunAnimation(_frameRec);
				}
				else
				{
					_moveShotgunAimMid->RunAnimation(_frameRec);
				}
				break;
			case GunFight::Aim::Down:
				if (dynamic_cast<Revolver*>(_currentWeapon) != NULL)
				{
					_moveRevolverAimDown->RunAnimation(_frameRec);
				}
				else
				{
					_moveShotgunAimDown->RunAnimation(_frameRec);
				}
				break;
			}
			break;
		case GunFight::Status::Dead:
			_death->RunAnimation(_deathFrameRec);
			break;
		default:
			break;
		}
	}

	void Player::FireWeapon()
	{
		Vector2 direction;
		if (!_isDead)
		{
			switch (_player)
			{
			case GunFight::playerConfig::player1:
				auxCoords.x = _body.x + _body.width + shootingXOffset;
				auxCoords.y = _body.y + (_body.height / 2);
				if (IsKeyPressed(KEY_J)) {
					_aim = GunFight::Aim::Up;
					direction = { 1 - halfFireArc,-halfFireArc };
					_currentWeapon->FireBullet(auxCoords, direction);
				}
				if (IsKeyPressed(KEY_K)) {
					_aim = GunFight::Aim::Mid;
					direction = { 1,0 };
					_currentWeapon->FireBullet(auxCoords, direction);
				}
				if (IsKeyPressed(KEY_L)) {
					_aim = GunFight::Aim::Down;
					direction = { 1 - halfFireArc,halfFireArc };
					_currentWeapon->FireBullet(auxCoords, direction);
				}
				break;
			case GunFight::playerConfig::player2:
				auxCoords.x = _body.x - shootingXOffset;
				auxCoords.y = _body.y + (_body.height / 2);
				if (IsKeyPressed(KEY_KP_1)) {
					_aim = GunFight::Aim::Up;
					direction = { -1 + halfFireArc,-halfFireArc };
					_currentWeapon->FireBullet(auxCoords, direction);
				}
				if (IsKeyPressed(KEY_KP_2)) {
					_aim = GunFight::Aim::Mid;
					direction = { -1,0 };
					_currentWeapon->FireBullet(auxCoords, direction);
				}
				if (IsKeyPressed(KEY_KP_3)) {
					_aim = GunFight::Aim::Down;
					direction = { -1 + halfFireArc,halfFireArc };
					_currentWeapon->FireBullet(auxCoords, direction);
				}
				break;
			default:
				break;
			}
		}
	}

	void Player::UpdateWeapon()
	{
		_currentWeapon->Update();
	}
	void Player::OnCollisionStay(IColisionable* other)
	{

	}
	void Player::OnCollisionEnter(IColisionable* other)
	{
		
		if (other->GetTag() == "Bullet")
		{
			if (dynamic_cast<Bullet*>(other)->GetIsActive() && !_isDead)
			{
				_isDead = true;
				status = Status::Dead;
				PlaySound(_deathScream);
			}
		}
	}
	void Player::OnCollisionExit(IColisionable* other)
	{
	}
}