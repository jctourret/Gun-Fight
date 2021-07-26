#include "Character.h"

namespace GunFight {
	int currentCharacterFrame = 0;

	int animTime = 1;

	int textFontSize = 18;

	Character::Character() {

	}

	Character::Character(string sheetPath, int sheetColumns, int sheetRows) {
		_body.x = 0;
		_body.y = 0;
		_pos = {0.0f,0.0f};
		_body.width = 500;
		_body.height = 500;
		_currentWeapon = new Weapon();
		_score = 0;
		_isDead = false;
		_isMoving = false;
		_spriteSheet = LoadTexture(sheetPath.c_str());
		_sheetColumns = sheetColumns;
		_sheetRows = sheetRows;
		_frameRec.x = 0;
		_frameRec.y = 0;
		_frameRec.width = (float)_spriteSheet.width / _sheetColumns;
		_frameRec.height = (float)_spriteSheet.height / _sheetRows;
		_frameTime = (float) animTime / _sheetColumns;
		_deathScream = LoadSound("../res/assets/snd/wScream.ogg");
	}
	Character::~Character() {
		UnloadTexture(_spriteSheet);
	}


	void Character::setBody(Rectangle body) {
		_body = body;
	}

	void Character::setX(float x) {
		_body.x = x;
	}

	void Character::setY(float y) {
		_body.y = y;
	}

	void Character::setWidth(float width) {
		_body.width = width;
	}

	void Character::setHeight(float height) {
		_body.height = height;
	}

	void Character::setScore(int score) {
		_score = score;
	}
	void Character::update() {
		move();
	}

	void Character::draw() {
		if (!_isDead) {
			DrawTextureRec(_spriteSheet, _frameRec, _pos, WHITE);
		}
		else {
			DrawRectangle((int)(_body.x - _body.height + _body.width), (int)(_body.y + _body.height - _body.width), (int)_body.height, (int)_body.width, MAROON);
			DrawText("YOU GOT ME!", (int)_body.x, (int)_body.y, textFontSize, MAROON);
		}
	}

	void Character::move() {

	}

	void Character::fireWeapon() {

	}

	
}