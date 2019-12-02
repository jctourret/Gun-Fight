#include "Game_loop.h"


Game_loop::Game_loop(){
	_screen = new Screen();
	InitWindow(_screen->getResolutionWidth(),_screen->getResolutionHeight(), "Bratva's Wrath");
	_gameState = onMenu;
	_gameOn = true;
	_menu = NULL;
	_gameplay = NULL;
	_credits = NULL;
	_menu=new Menu();
	_gameplay=new Gameplay();
	_credits= new Credits();
}

Game_loop::~Game_loop(){
	if (_menu != NULL) {
		delete _menu;
	}
	if (_gameplay != NULL) {
		delete _gameplay;
	}
	if (_credits != NULL) {
		delete _credits;
	}
}

void Game_loop::game_loop() {
	while (_gameOn){
		switch (_gameState) {
		case onMenu:
			_menu->run();
			if (_menu->getToGameplay()){
				_gameState = onGameplay;
				_menu->setToGameplay(false);
			}
			if (_menu->getToCredits()) {
				_gameState = onCredits;
				_menu->setToCredits(false);
			}
			break;
		case onGameplay:
			_gameplay->run();
			if (_gameplay->getToMenu()){
				_gameState = onMenu;
				_gameplay->setToMenu(false);
			}
			if (_gameplay->getToCredits()) {
				_gameState = onCredits;
				_gameplay->setToCredits(false);
			}
			break;
		case onCredits:
			_credits->run();
			if (_credits->getToGameplay()) {
				_gameState = onGameplay;
				_credits->setToGameplay(false);
			}
			if (_credits->getToMenu()) {
				_gameState = onMenu;
				_credits->setToMenu(false);
			}
			break;
		default:
			break;
		}
	}
}