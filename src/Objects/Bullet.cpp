#include "Bullet.h"
#include "Obstacles.h"

using namespace GunFight;

namespace GunFight {

	static const float bulletSpeed = 500.0f;

	Bullet::Bullet(float width, float height) {
		_tag = "Bullet";
		_body.x = 0;
		_body.y = 0;
		_body.width = width;
		_body.height = height;
		_speed = bulletSpeed;
		_direction.x = NULL;
		_direction.y = NULL;
		_isActive = false;
		_hitSFX = LoadSound("res/assets/snd/LittleRobotSoundFactory_BulletHit.wav");
	}

	Bullet::~Bullet() {
	}

	void Bullet::SetBody(Rectangle body) {
		_body = body;
	}

	void Bullet::SetBodyX(float x) {
		_body.x = x;
	}

	void Bullet::SetBodyY(float y) {
		_body.y = y;
	}

	void Bullet::SetSpeed(float speed) {
		_speed = speed;
	}

	void Bullet::SetDirectionX(float x) {
		_direction.x = x;
	}

	void Bullet::SetDirectionY(float y) {
		_direction.y = y;
	}

	void Bullet::SetIsActive(bool isActive)
	{
		_isActive = isActive;
	}

	std::string Bullet::GetTag()
	{
		return _tag;
	}

	Rectangle Bullet::GetBody()
	{
		return _body;
	}

	float Bullet::GetBodyX() {
		return _body.x;
	}

	float Bullet::GetBodyY() {
		return _body.y;
	}

	float Bullet::GetBodyHeight() {
		return _body.height;
	}

	float Bullet::GetSpeed() {
		return _speed;
	}

	float Bullet::GetDirectionX() {
		return _direction.x;
	}

	float Bullet::GetDirectionY() {
		return _direction.y;
	}

	bool Bullet::GetIsActive()
	{
		return _isActive;
	}

	void Bullet::OnCollisionEnter(IColisionable* other)
	{

		if (other->GetTag() == "Player1" || other->GetTag() == "Player2")
		{
			_isActive = false;
			if (!IsSoundPlaying(_hitSFX))
			{
				PlaySound(_hitSFX);
			}
		}
		if (dynamic_cast<Obstacles*>(other) != NULL)
		{
			if (dynamic_cast<Obstacles*>(other)->getIsActive())
			{
				_isActive = false;
				if (!IsSoundPlaying(_hitSFX))
				{
					PlaySound(_hitSFX);
				}
			}
		}
	}

	void Bullet::OnCollisionStay(IColisionable* other)
	{
		if (dynamic_cast<Obstacles*>(other) != NULL)
		{
			if (dynamic_cast<Obstacles*>(other)->getIsActive())
			{
				_body.x = 0;
				_body.y = 0;
			}
		}
	}

	void Bullet::OnCollisionExit(IColisionable* other)
	{

	}

	void Bullet::Update() {
		Move();
	}

	void Bullet::Move() {
		float time = GetFrameTime();

		if (_isActive)
		{
			if (_body.x <= GetScreenWidth() && _body.x >= 0 &&
				_body.y <= GetScreenHeight() - _body.height && _body.y >= 0) {
				_body.x = (_body.x + _speed * time * _direction.x);
				_body.y = (_body.y + _speed * time * _direction.y);
			}
			else
			{
				_isActive = false;
			}
		}
	}

	void Bullet::Draw() {
		if (_isActive)
		{
			DrawRectangleRec(_body, RAYWHITE);
		}
	}
}