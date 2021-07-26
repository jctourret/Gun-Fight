#include "Game_loop.h"

using namespace GunFight;

namespace GunFight {
	Game_loop::Game_loop() {
		_screen = new Screen();
		InitWindow(_screen->getResolutionWidth(), _screen->getResolutionHeight(), "Gun Fight!");
		InitAudioDevice();
		_gameState = onMenu;
		_gameOn = true;
		_menu = NULL;
		_gameplay = NULL;
		_credits = NULL;
		_menu = new Menu();
		_gameplay = new Gameplay();
		_credits = new Credits();
		_music = new GameMusic();
	}

	Game_loop::~Game_loop() {
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
		while (_gameOn || WindowShouldClose()) {
			switch (_gameState) {
			case onMenu:
				_menu->run();
				_music->updateMusic();
				if (_menu->getToGameplay()) {
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
				_music->updateMusic();
				if (_gameplay->getToMenu()) {
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
				_music->updateMusic();
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
}