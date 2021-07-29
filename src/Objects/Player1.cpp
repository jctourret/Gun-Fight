#include "Player1.h"
#include "System/Screen.h"
#include <list>

using namespace GunFight;

namespace GunFight {
	
	enum class Status {Idle,Moving,Dead};

	list<list<Vector2>> animations;
	int currentFrame = 0;
	float animTimer = 0.0f;
	float frameTimer = 0.0f;

	const int playerSpeed = 500;
	
	const int textFontSize = 20;

	const float halfFireArc = 0.35f;
	const float animTime = 1.0f;

	Player::Player(Vector2 pos, string texturePath) : Character(pos, texturePath) {
		_frameRec.x = _pos.x;
		_frameRec.y = _pos.y;
		_frameRec.width = _spriteSheet.width / _sheetColumns;
		_frameRec.height = _spriteSheet.height / _sheetRows;
		_frameTime = animTime/_sheetColumns;
		_deathScream = LoadSound("../res/assets/snd/wScream.ogg");
	}

	Player::~Player() {
		UnloadTexture(_spriteSheet);
		UnloadSound(_deathScream);
	}

	Rectangle Player::getBody() {
		return _body;
	}

	int Player::getScore() {
		return _score;
	}

	void Player::update() {
			move();
			updateAnimation();
			fireWeapon();
			updateWeapon();
	}

	void Player::draw() {
		DrawTextureRec(_spriteSheet,_frameRec,_pos,WHITE);
	}

	void Player::move() {
		float time = GetFrameTime();
		animTimer += time;
		frameTimer += time;
		if (IsKeyDown(KEY_W)) {
			_body.y -= playerSpeed * time;
		}
		if (IsKeyDown(KEY_S)) {
			_body.y += playerSpeed * time;
		}
		if (IsKeyDown(KEY_A)) {
			_body.x -= playerSpeed * time;
		}
		if (IsKeyDown(KEY_D)) {
			_body.x += playerSpeed * time;
		}
		if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S) &&
			!IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {

		}
		_pos = { _body.x,_body.y };
	}

	void Player::updateAnimation() {
		switch (_aim)
		{
		case GunFight::Aim::Up:
			break;
		case GunFight::Aim::Mid:
			break;
		case GunFight::Aim::Down:
			break;
		default:
			break;
		}
	}

	void Player::fireWeapon() {
		Vector2 direction;
		if (IsKeyPressed(KEY_J)) {
			_aim = GunFight::Aim::Up;
			direction = {1-halfFireArc,-halfFireArc};
			_currentWeapon->fireBullet(_body,direction);
		}
		if (IsKeyPressed(KEY_K)) {
			_aim = GunFight::Aim::Up;
			direction = {1,0};
			_currentWeapon->fireBullet(_body, direction);
		}
		if (IsKeyPressed(KEY_L)) {
			_aim = GunFight::Aim::Up;
			direction = {1-halfFireArc,halfFireArc};
			_currentWeapon->fireBullet(_body, direction);
		}
	}

	void Player::updateWeapon() {
		_currentWeapon->update();
	}

	void Player::reload() {
	}

	void Player::OnCollisionStay(std::shared_ptr<IColisionable> other) {

	}
	void Player::OnCollisionEnter(std::shared_ptr<IColisionable> other)
	{
		if (other->GetTag() == "Bullet")
		{
			//player Muere
		}
	}
	void Player::OnCollisionExit(std::shared_ptr<IColisionable> other)
	{
	}
}