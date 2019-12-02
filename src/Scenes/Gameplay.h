#pragma once
#include "raylib.h"
#include "Objects/Player2.h"
#include "Objects/Player1.h"
class Gameplay{
private:
	bool _gameplayOn;
	bool _toMenu;
	bool _toCredits;
	Player1* _player1;
	Player2* _player2;
	int _timer;
public:
	Gameplay();
	~Gameplay();
	void run();
	void update();
	void draw();
	void runTimer();
	void setToMenu(bool toMenu);
	void setToCredits(bool toCredits);
	bool getToMenu();
	bool getToCredits();
};

