#pragma once
#include "raylib.h"
class Menu{
private:
	bool _menuOn;
	bool _toGameplay;
	bool _toCredits;
public:
	Menu();
	~Menu();
	void run();
	void update();
	void draw();
	void setToGameplay(bool toGameplay);
	void setToCredits(bool toCredits);
	bool getToGameplay();
	bool getToCredits();
};
