#include "Game_loop.h"

using namespace GunFight;

namespace GunFight {
	Game_loop::Game_loop() {
		_screen = new Screen();
		InitWindow(_screen->GetResolutionWidth(), _screen->GetResolutionHeight(), "Gun Fight!");
		InitAudioDevice();
		_gameState = Gamestate::onMenu;
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

	void Game_loop::GameLoop() {
		while (!WindowShouldClose()) {
			switch (_gameState) {
			case Gamestate::onMenu:
				_menu->Run();
				_music->updateMusic();
				if (_menu->GetToGameplay()) {
					_gameState = Gamestate::onGameplay;
					_menu->SetToGameplay(false);
				}
				if (_menu->GetToCredits()) {
					_gameState = Gamestate::onCredits;
					_menu->SetToCredits(false);
				}
				break;
			case Gamestate::onGameplay:
				_gameplay->Run();
				_music->updateMusic();
				if (_gameplay->GetToMenu()) {
					_gameState = Gamestate::onMenu;
					_gameplay->SetToMenu(false);
				}
				if (_gameplay->GetToCredits()) {
					_gameState = Gamestate::onCredits;
					_gameplay->SetToCredits(false);
				}
				break;
			case Gamestate::onCredits:
				_credits->Run();
				_music->updateMusic();
				if (_credits->GetToGameplay()) {
					_gameState = Gamestate::onGameplay;
					_credits->SetToGameplay(false);
				}
				if (_credits->GetToMenu()) {
					_gameState = Gamestate::onMenu;
					_credits->SetToMenu(false);
				}
				break;
			default:
				break;
			}
		}
	}
}