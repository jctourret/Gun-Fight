#pragma once
#include "raylib.h"
class Credits{
private:
	bool _creditsOn;
	bool _toMenu;
	bool _toGameplay;
public:
	Credits();
	~Credits();
	void run();
	void update();
	void draw();
	void setToMenu(bool toMenu);
	void setToGameplay(bool toGameplay);
	bool getToMenu();
	bool getToGameplay();
};