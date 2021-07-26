#include "Player1.h"
#include "System/Screen.h"

using namespace GunFight;

namespace GunFight {
	
	int currentFrame = 0;

	float animTimer = 0.0f;
	float frameTimer = 0.0f;
	float p1DeadTime = 2.0f;

	const int playerSpeed = 500;
	const int textFontSize = 20;

	const float playerWidth = 50.0f;
	const float playerHeight = 100.0f;
	const float halfFireArc = 0.35f;
	const float bulletWidth = 20;
	const float bulletHeight = 10;
	const float resetP1DeadTime = p1DeadTime;
	const float animTime = 1.0f;

	Player::Player(Vector2 pos) : Character() {
		_body.x = pos.x;
		_body.y = pos.y;
		_pos = pos;
		_body.width = playerWidth;
		_body.height = playerHeight;
		_score = NULL;
		_currentWeapon = new Revolver();
		_isDead = false;
		_isMoving = false;
		_spriteSheet = LoadTexture("../res/assets/img/rightCharacter.png");
		_sheetColumns = 4;
		_sheetRows = 3;
		_frameRec.x = 0;
		_frameRec.y = 0;
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

	bool Player::getIsDead() {
		return _isDead;
	}

	void Player::update() {
		if (!getIsDead()) {
			move();
			updateAnimation();
			fireWeapon();
			updateWeapon();
		}
	}

	void Player::draw() {
		if (!_isDead) {
			DrawTextureRec(_spriteSheet,_frameRec,_pos,WHITE);
			_currentWeapon->draw();
		}
		else {
			DrawRectangle(_body.x - _body.height + _body.width, _body.y + _body.height - _body.width, _body.height, _body.width, MAROON);
			DrawText("YOU GOT ME!", _body.x, _body.y, textFontSize, MAROON);
		}
	}

	void Player::move() {
		float time = GetFrameTime();
		animTimer += time;
		frameTimer += time;
		if (IsKeyDown(KEY_W) && _body.y > 0) {
			_body.y -= playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_S) && _body.y < screeenHeight - _body.height) {
			_body.y += playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_A) && _body.x > 0 && !_isDead) {
			_body.x -= playerSpeed * time;
			_isMoving = true;
		}
		if (IsKeyDown(KEY_D) && _body.x <= screenWidth / 4 && !_isDead) {
			_body.x += playerSpeed * time;
			_isMoving = true;
		}
		if (!IsKeyDown(KEY_W) && !IsKeyDown(KEY_S) && !IsKeyDown(KEY_A) && !IsKeyDown(KEY_D)) {
			_isMoving = false;
		}
		_pos = { _body.x,_body.y };
	}

	void Player::updateAnimation() {
		if (_isMoving) {
			if (frameTimer > _frameTime)
			{
				currentFrame++;
				_frameRec.x = currentFrame * _frameRec.width;
				frameTimer = 0.0f;
			}
			if (animTimer > animTime) {
				animTimer = 0.0f;
				currentFrame = 0;
			}
		}
		else {
			currentFrame = 0;
		}
		switch (_aim)
		{
		case Up:
			_frameRec.y = 0;
			break;
		case Mid:
			_frameRec.y = _frameRec.height;
			break;
		case Down:
			_frameRec.y = _frameRec.height*2;
			break;
		default:
			break;
		}
	}

	void Player::fireWeapon() {
		Vector2 direction;
		if (IsKeyPressed(KEY_J)) {
			_aim = Up;
			direction = {1-halfFireArc,-halfFireArc};
			_currentWeapon->fireBullet(_body,direction);
		}
		if (IsKeyPressed(KEY_K)) {
			_aim = Mid;
			direction = {1,0};
			_currentWeapon->fireBullet(_body, direction);
		}
		if (IsKeyPressed(KEY_L)) {
			_aim = Down;
			direction = {1-halfFireArc,halfFireArc};
			_currentWeapon->fireBullet(_body, direction);
		}
	}

	void Player::updateWeapon() {
		_currentWeapon->update();
	}

	void Player::die(bool& die) {
		if (die) {
			_isDead = true;
			p1DeadTime -= GetFrameTime();
			if (p1DeadTime <= 0) {
				p1DeadTime = resetP1DeadTime;
				_isDead = false;
				die = false;
			}
		}
	}

	void Player::reload() {
	}
}