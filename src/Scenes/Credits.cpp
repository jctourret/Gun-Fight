#include "Credits.h"

using namespace GunFight;

namespace GunFight {

	int creditsX = 500;
	int creditsY = 100;
	int titleFontSize = 50;
	int creditsFontsize = 20;

	int bxanCreditsX = 100;
	int bxanCreditsY = 300;

	int musicCreditsX = 100;
	int musicCreditsY = 450;

	int SFXCreditsX = 100;
	int SFXCreditsY = 400;

	int deathSFXCreditsX = 100;
	int deathSFXCreditsY = 500;

	int hitSFXCreditsX = 100;
	int hitSFXCreditsY = 550;

	int inspiredByCreditsX = 100;
	int inspiredByCreditsY = 600;

	int programmerCreditsX = 700;
	int programmerCreditsY = 300;

	int libraryCreditsX = 700;
	int libraryCreditsY = 350;

	int artToolCreditsX = 700;
	int artToolCreditsY = 400;

	Color textColor = YELLOW;

	Credits::Credits()
	{
		_creditsOn = false;
		_toGameplay = false;
		_toMenu = false;
	}

	Credits::~Credits()
	{
	}

	void Credits::SetToMenu(bool toMenu)
	{
		_toMenu = toMenu;
	}

	void Credits::SetToGameplay(bool toGameplay)
	{
		_toGameplay = toGameplay;
	}

	bool Credits::GetToGameplay()
	{
		return _toGameplay;
	}

	bool Credits::GetToMenu()
	{
		return _toMenu;
	}

	void Credits::Run()
	{
		Update();
		Draw();
	}

	void Credits::Update() 
	{
		if (IsKeyPressed(KEY_ENTER)) {
			_creditsOn = false;
			_toMenu = true;
		}
	}

	void Credits::Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Credits", creditsX, creditsY, titleFontSize, textColor);
		DrawText("Backgrounds by Bxan at artbxan.itch.io/",bxanCreditsX,bxanCreditsY,creditsFontsize,textColor);
		DrawText("Fastest Gun in the 8-bit West by OkamiDeluxe at youtube.com", musicCreditsX, musicCreditsY, creditsFontsize, textColor);
		DrawText("Funeral March(8-bit) by jkfite01 at OpenGameArt.org", deathSFXCreditsX, deathSFXCreditsY, creditsFontsize, textColor);
		DrawText("hitSFX by LittleRobotSoundFactory at freeSound.org", hitSFXCreditsX, hitSFXCreditsY, creditsFontsize, textColor);
		DrawText("Inspired by Gun Fight(1975) by Tomohiro Nishikado.", inspiredByCreditsX, inspiredByCreditsY, creditsFontsize, textColor);
		DrawText("Made with Raylib by Ray.", libraryCreditsX, libraryCreditsY, creditsFontsize, textColor);
		DrawText("Programmed by Juan Cruz Tourret.", programmerCreditsX, programmerCreditsY, creditsFontsize, textColor);
		DrawText("Art made with Piskel at piskelapp.com.", artToolCreditsX, artToolCreditsY, creditsFontsize, textColor);
		DrawText("All Assets under Creative Commons by Atribution.",GetScreenWidth()/2,GetScreenHeight()-GetScreenHeight()/20,creditsFontsize,textColor);
		EndDrawing();
	}
}