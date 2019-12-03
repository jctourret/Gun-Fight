#pragma once
#include "raylib.h"



class Arbol{
private:
	Rectangle _body;
	int _health;
	Texture2D _F1_Full;
	Texture2D _F1_Half;
	Texture2D _F1_Base;
public:
	Arbol(float x, float y);
	~Arbol();
	void setBody(Rectangle body);
	void setBodyWidth(float width);
	void setBodyHeight(float hieght);
	Rectangle getBody();
	float getBodyWidth();
	float getBodyHeight();
	void isHit(bool& hitTree);
	void draw();
};

