#include "Character.h"

namespace GunFight {
	int currentCharacterFrame = 0;

	int animTime = 1;

	int textFontSize = 18;

	const float charWidth = 50.0f;
	const float charHeight = 100.0f;

	Character::Character(Vector2 pos, string sheetPath, int sheetColumns, int sheetRows) {
		_body.x = pos.x;
		_body.y = pos.y;
		_pos = pos;
		_body.width = charWidth;
		_body.height = charHeight;
		_currentWeapon = new Revolver();
		_aim = GunFight::Aim::Mid;
		_score = 0;
		_sheetColumns = NULL;
		_sheetRows = NULL;
		_frameRec = { 0.0f,0.0f,0.0f,0.0f };
		_frameTime = 0;
		_spriteSheet = LoadTexture(sheetPath.c_str());
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
		DrawTextureRec(_spriteSheet, _frameRec, _pos, WHITE);
	}

	void Character::move() {

	}

	void Character::fireWeapon() {

	}

	Rectangle Character::GetBody() {
		return _body;
	}
	
	string Character::GetTag()
	{
		return _tag;
	}


}