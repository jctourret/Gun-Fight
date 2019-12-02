#pragma once
#include "raylib.h"

class Bullet{
private:
	Rectangle _body;
	float _speed;
	Vector2 _direction;
	bool _hasScored;
public:
	Bullet(float x, float y, float width, float height);
	~Bullet();
	void setBody(Rectangle body);
	void setBodyX(float x);
	void setBodyY(float y);
	void setSpeed(float speed);
	void setDirectionX(float x);
	void setDirectionY(float y);
	void setHasScored(bool hasScored);
	Rectangle getBody();
	float getBodyX();
	float getBodyY();
	float getBodyHeight();
	float getSpeed();
	float getDirectionX();
	float getDirectionY();
	bool getHasScored();
	void draw();
};

