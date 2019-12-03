#include "Arbol.h"

const float treeWidth = 50;

float fullHeight = 100;
float halfHeight = 50;
float baseHeight = 25;

Arbol::Arbol(float x, float y) {
	_body.x = x;
	_body.y = y;
	_body.width = treeWidth;
	_body.height = fullHeight;
	_health = 3;
	_F1_Full = LoadTexture("../res/assets/img/P1_F1_Up.png");
	_F1_Half = LoadTexture("../res/assets/img/P1_F1_Mid.png");
	_F1_Base = LoadTexture("../res/assets/img/P1_F1_Down.png");
}

Arbol::~Arbol(){
	UnloadTexture(_F1_Full);
	UnloadTexture(_F1_Half);
	UnloadTexture(_F1_Base);
}

void Arbol::setBody(Rectangle body) {
	_body = body;
}

void Arbol::setBodyWidth(float width) {
	_body.width = width;
}

void Arbol::setBodyHeight(float hieght){
	_body.height = hieght;
}

Rectangle Arbol::getBody(){
	return _body;
}

float Arbol::getBodyWidth(){
	return _body.width;
}

float Arbol::getBodyHeight(){
	return _body.height;
}

void Arbol::isHit(bool& hitTree) {
	_health--;
	if (_health==2){
		_body.height = halfHeight;
	}
	if (_health == 1) {
		_body.height = baseHeight;
	}
	hitTree = false;
}

void Arbol::draw(){
	switch (_health){
	case 1:
		DrawTexture(_F1_Base,_body.x,_body.y,RAYWHITE);
		break;
	case 2:
		DrawTexture(_F1_Half, _body.x, _body.y, RAYWHITE);
		break;
	case 3:
		DrawTexture(_F1_Full, _body.x, _body.y, RAYWHITE);
		break;
	}
	DrawRectangleRec(_body, MAROON);
}