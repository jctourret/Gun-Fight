#include "Character.h"

namespace GunFight {
	int currentCharacterFrame = 0;

	int animTime = 1;

	int textFontSize = 18;

	const float charWidth = 50.0f;
	const float charHeight = 100.0f;

	Character::Character(Vector2 pos, string sheetPath, string deathPath, int sheetColumns, int sheetRows) : IColisionable() {
		_body.x = pos.x;
		_body.y = pos.y;
		_pos = pos;
		_body.width = charWidth;
		_body.height = charHeight;
		_isDead = false;
		_currentWeapon = NULL;
		_aim = GunFight::Aim::Mid;
		_sheetColumns = sheetColumns;
		_sheetRows = sheetRows;
		_frameRec = { 0.0f, 0.0f, 0.0f, 0.0f };
		_frameTime = 0;
		_spriteSheet = LoadTexture(sheetPath.c_str());
		_deathSheet = LoadTexture(deathPath.c_str());
		_deathFrameRec = { 0.0f, 0.0f, (float)_deathSheet.width, (float)_deathSheet.height/2};
		_deathScream = LoadSound("res/assets/snd/wScream.ogg");
	}
	Character::~Character() {
		UnloadTexture(_spriteSheet);
		UnloadTexture(_deathSheet);
	}

	Weapon* Character::GetWeapon()
	{
		return _currentWeapon;
	}

	bool Character::GetIsDead()
	{
		return _isDead;
	}


	void Character::SetBody(Rectangle body) {
		_body = body;
	}

	void Character::SetX(float x) {
		_body.x = x;
	}

	void Character::SetY(float y) {
		_body.y = y;
	}

	void Character::SetWidth(float width) {
		_body.width = width;
	}

	void Character::SetHeight(float height) {
		_body.height = height;
	}
	void Character::SetCurrentWeapon(Weapon* weapon)
	{
		if (_currentWeapon != NULL)
		{
			delete _currentWeapon;
		}
		_currentWeapon = weapon;
	}
	void Character::SetIsDead(bool isDead)
	{
		_isDead = isDead;
	}
	void Character::Update() {
		Move();
	}

	void Character::Draw() {
		if (!_isDead)
		{
			DrawTextureRec(_spriteSheet, _frameRec, _pos, WHITE);
		}
		else
		{
			_pos.y = _body.y + _body.height - _deathFrameRec.height;
			DrawTextureRec(_deathSheet, _deathFrameRec, _pos, WHITE);
			_pos.y = _body.y;
		}
	}

	void Character::Move() {

	}

	void Character::FireWeapon() {

	}

	Rectangle Character::GetBody() {
		return _body;
	}
	
	string Character::GetTag()
	{
		return _tag;
	}

	void Character::OnCollisionStay(IColisionable* other)
	{
	}

	void Character::OnCollisionEnter(IColisionable* other)
	{
	}

	void Character::OnCollisionExit(IColisionable* other)
	{
	}


}