#include "Credits.h"

Credits::Credits(){
	_creditsOn = false;
	_toGameplay = false;
	_toMenu = false;
}

Credits::~Credits(){
}


void Credits::run() {
	_creditsOn = true;
	while (_creditsOn) {
		update();
		draw();
	}
}

void Credits::update() {
	if (IsKeyPressed(KEY_ENTER)) {
		_creditsOn = false;
		_toMenu = true;
	}
}

void Credits::draw() {
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("credits", 200, 500, 50, MAROON);
	EndDrawing();
}
void Credits::setToMenu(bool toMenu) {
	_toMenu = toMenu;
}
void Credits::setToGameplay(bool toGameplay) {
	_toGameplay = toGameplay;
}
bool Credits::getToGameplay() {
	return _toGameplay;
}
bool Credits::getToMenu() {
	return _toMenu;
}