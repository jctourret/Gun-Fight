#include "Gameplay.h"
#include "System/Game_loop.h"

using namespace GunFight;

namespace GunFight {

	enum class Stage
	{
		weaponSelection,
		gameplay
	};

	enum class PlayerChoice{revolver, shotgun};

	const Vector2 player1Pos = { screenWidth / 10 , screenHeight / 2 };
	const Vector2 player2Pos = { screenWidth - screenWidth / 10,screenHeight / 2 };
	const Vector2 obstacleUpLeftPos = { 540.0f, 250.0f };
	const Vector2 obstacleUpRightPos = { 680.0f, 250.0f };
	
	const Vector2 obstacleMidLeftPos = { 530.0f, 400.0f };
	const Vector2 obstacleMidRightPos = { 700.0f, 400.0f };

	const Vector2 obstacleDownLeftPos = { 480.0f, 550.0f };
	const Vector2 obstacleDownRightPos = { 760.0f, 550.0f };

	const int p1BulletsXposition = screenWidth / 9;
	const int p2BulletsXposition = screenWidth - screenWidth / 4;

	const int bulletsYposition = screenHeight - screenWidth / 20;
	const int bulletsXOffset = 30;

	const int p1ScorePosX = 100;
	const int p1ScorePosY = 50;
	const int p2ScorePosX = 900;
	const int p2ScorePosY = 50;
	const int reloadingPosX = screenWidth /2;
	const int reloadingPosY = 100;
	const int timerPosX = screenWidth /2;
	const int timerPosY = 50;
	const int winTextPosX = screenWidth / 2 - 100;
	const int winTextPosY = 200;
	const int toCreditsPosX = screenWidth / 3;
	const int toCreditsPosy = 400;
	const int textFontSize = 40;

	const Color textColor = YELLOW;

	bool reloading = false;
	bool addingScore = false;
	PlayerChoice p1choice = PlayerChoice::revolver;
	PlayerChoice p2choice = PlayerChoice::revolver;

	const float peaceTime = 2.00f;
	const float reloadTime = 1.99f;
	const float deadTime = 2.0f;
	const float gameTime = 2.0f;

	float peaceTimer = 0.0f;
	float reloadTimer = 0.0f;
	float deadTimer = 0.0f;
	float gameTimer = 0.0f;

	int stagesPlayed = 0;
	int currentBackground = 0;
	Stage currenStage = Stage::weaponSelection;

	void restoreObstacles(vector<Obstacles*> obstacles);
	void deactivateObstacles(vector<Obstacles*> obstacles);

	Gameplay::Gameplay()
	{
		_gameplayOn = false;
		_toMenu = false;
		_toCredits = false;
		
		_p1Score = 0;
		_p2Score = 0;
		
		_background.push_back(LoadTexture("res/assets/img/BKDawn.png"));
		_background.push_back(LoadTexture("res/assets/img/BKHighNoon.png"));
		_background.push_back(LoadTexture("res/assets/img/BKSunDown.png"));

		_bulletUI = LoadTexture("res/assets/img/bulletUI.png");

		_deathJingle = LoadSound("res/assets/snd/Funeral March.wav");

		SetSoundVolume(_deathJingle,0.7f);
		SetSoundPitch(_deathJingle,3.0f);
		
		_player1 = new Player("Player1", GunFight::playerConfig::player1, player1Pos);
		_colManager.AddToCollisionManager(_player1);
		_player2 = new Player("Player2", GunFight::playerConfig::player2, player2Pos);
		_colManager.AddToCollisionManager(_player2);
		
		Vector2 wagonPos = { screenWidth / 2, screenHeight };
		_wagon = new Wagon(wagonPos);
		_colManager.AddToCollisionManager(_wagon);
		
		_obstacles.push_back(new Tree(obstacleUpLeftPos));
		_colManager.AddToCollisionManager(_obstacles.back());

		_obstacles.push_back(new Tree(obstacleUpRightPos));
		_colManager.AddToCollisionManager(_obstacles.back());
		
		_obstacles.push_back(new Cactus(obstacleMidLeftPos));
		_colManager.AddToCollisionManager(_obstacles.back());

		_obstacles.push_back(new Cactus(obstacleMidRightPos));
		_colManager.AddToCollisionManager(_obstacles.back());

		_obstacles.push_back(new Tree(obstacleDownLeftPos));
		_colManager.AddToCollisionManager(_obstacles.back());

		_obstacles.push_back(new Tree(obstacleDownRightPos));
		_colManager.AddToCollisionManager(_obstacles.back());

		_timer = gameTime;
	}

	Gameplay::~Gameplay()
	{
		if (_player1 != NULL) {
			delete _player1;
		}
		if (_player2 != NULL)
		{
			delete _player2;
		}
		if (_wagon != NULL)
		{
			delete _wagon;
		}
	}

	void Gameplay::SetToMenu(bool toMenu)
	{
		_toMenu = toMenu;
	}

	void Gameplay::SetToCredits(bool toCredits)
	{
		_toCredits = toCredits;
	}

	bool Gameplay::GetToCredits()
	{
		return _toCredits;
	}

	bool Gameplay::GetToMenu()
	{
		return _toMenu;
	}

	void Gameplay::Run()
	{
		switch (currenStage)
		{
		case Stage::weaponSelection:
			SelectWeapon();
			ToNextStage();
			break;
		case Stage::gameplay:
			Update();
			break;
		}
		Draw();
	}


	void Gameplay::Update()
	{
		if (peaceTimer < peaceTime)
		{
			peaceTimer += GetFrameTime();
		}
		else
		{
			_player1->Update();
			_player2->Update();
			_wagon->update();

			//Recargar armas cuando ambos esten sin balas
			if (_player1->GetWeapon()->GetBulletsLeft() == 0 &&
				_player2->GetWeapon()->GetBulletsLeft() == 0)
			{
				_player1->GetWeapon()->Reload();
				_player2->GetWeapon()->Reload();
			}

			_colManager.CheckCollisions();
			//Verificar muertes y dar puntos

			if (_player1->GetIsDead() || _player2->GetIsDead())
			{
				if (!IsSoundPlaying(_deathJingle))
				{
					PlaySound(_deathJingle);
				}
				deadTimer += GetFrameTime();
				if (deadTimer >= deadTime)
				{
					if (_player1->GetIsDead() && !_player2->GetIsDead())
					{
						_p2Score++;
					}
					else if (!_player1->GetIsDead() && _player2->GetIsDead())
					{
						_p1Score++;
					}
					_player1->SetIsDead(false);
					_player2->SetIsDead(false);
					deadTimer = 0;
					ToNextStage();
				}
			}
			RunTimer();
		}
	}

	void Gameplay::Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		if (currenStage == Stage::weaponSelection)
		{
			if (_player1 != NULL)
			{
				DrawText("P1 Choose your GUN!", GetScreenWidth() / 10, GetScreenHeight() / 6, textFontSize, textColor);
				if (p1choice == PlayerChoice::revolver)
				{
					DrawText("J >Revolver<", GetScreenWidth() / 6, GetScreenHeight() / 2, textFontSize, textColor);
					DrawText("K Shotgun", GetScreenWidth() / 6, GetScreenHeight() - GetScreenHeight() / 3, textFontSize, textColor);
				}
				else
				{
					DrawText("J Revolver", GetScreenWidth() / 6, GetScreenHeight() / 2, textFontSize, textColor);
					DrawText("K>Shotgun<", GetScreenWidth() / 6, GetScreenHeight() - GetScreenHeight() / 3, textFontSize, textColor);
				}
			}

			if (_player2 != NULL)
			{
				DrawText("P2 Choose your GUN!", GetScreenWidth() - GetScreenWidth() / 2, GetScreenHeight() / 6, textFontSize, textColor);

				if (p2choice == PlayerChoice::revolver)
				{
					DrawText("1 >Revolver<", GetScreenWidth() - GetScreenWidth() / 3, GetScreenHeight() / 2, textFontSize, textColor);
					DrawText("2 Shotgun", GetScreenWidth() - GetScreenWidth() / 3, GetScreenHeight() - screenHeight / 3, textFontSize, textColor);
				}
				else
				{
					DrawText("1 Revolver", GetScreenWidth() - GetScreenWidth() / 3, GetScreenHeight() / 2, textFontSize, textColor);
					DrawText("2 >Shotgun<", GetScreenWidth() - GetScreenWidth() / 3, GetScreenHeight() - GetScreenHeight() / 3, textFontSize, textColor);
				}
			}
			DrawText("Press ENTER to confim", GetScreenWidth() / 3, GetScreenHeight() / 3, textFontSize, textColor);

		}
		else {
			if (peaceTimer < peaceTime/2)
			{
				DrawText("Get Ready!", GetScreenWidth() /2, GetScreenHeight() /4,textFontSize,textColor);
			}
			else if (peaceTimer < peaceTime && peaceTimer >= peaceTime/2)
			{
				DrawText("Draw!", GetScreenWidth() / 2, GetScreenHeight() / 4, textFontSize, textColor);
			}

			DrawTexture(_background[currentBackground],0,0,RAYWHITE);
			DrawText(FormatText("%i", _timer), timerPosX, timerPosY, textFontSize, textColor);
			DrawText(FormatText("SCORE: %i", _p1Score), p1ScorePosX, p1ScorePosY, textFontSize, textColor);
			_player1->Draw();
			DrawText(FormatText("SCORE: %i", _p2Score), p2ScorePosX, p2ScorePosY, textFontSize, textColor);
			_player2->Draw();

			_wagon->draw();

			for (int i = 0; i < _obstacles.size(); i++)
			{
				_obstacles[i]->draw();
			}

			for (int i = 0; i < _player1->GetWeapon()->GetBulletsLeft(); i++)
			{
				DrawTexture(_bulletUI,p1BulletsXposition + bulletsXOffset*(i),bulletsYposition,WHITE);
			}

			for (int i = 0; i < _player2->GetWeapon()->GetBulletsLeft(); i++)
			{
				DrawTexture(_bulletUI, p2BulletsXposition + bulletsXOffset * (i), bulletsYposition, WHITE);
			}
		}
		EndDrawing();
	}

	void Gameplay::SelectWeapon()
	{
		if (_player1 != NULL)
		{
			if (IsKeyPressed(KEY_J))
			{
				p1choice = PlayerChoice::revolver;
			}
			else if (IsKeyPressed(KEY_K))
			{
				p1choice = PlayerChoice::shotgun;
			}
		}
		if (_player2 != NULL)
		{
			if(IsKeyPressed(KEY_KP_1))
			{
				p2choice = PlayerChoice::revolver;
			}
			else if (IsKeyPressed(KEY_KP_2))
			{
				p2choice = PlayerChoice::shotgun;
			}
		}
	}

	void Gameplay::RunTimer()
	{
		gameTimer += GetFrameTime();
		if (gameTimer >= 1.0f) {
			_timer -= 1;
			gameTimer = 0.0f;
		}
		if (_timer <= 0) {
			ToCredits();
		}
	}

	void Gameplay::ToNextStage() {
		switch (currenStage)
		{
		case GunFight::Stage::weaponSelection:
			if (IsKeyPressed(KEY_ENTER))
			{
				// Pasar de Stage y resetear escena
				currenStage = Stage::gameplay;
				currentBackground = stagesPlayed % _background.size();
				
				// Resetear scores por las dudas
				if (_player1 != NULL)
				{
					_p1Score = 0;
				}
				if (_player2 != NULL)
				{
					_p2Score = 0;
				}
				// En base a las elecciones, asignar armas
				if (p1choice == PlayerChoice::revolver)
				{
					_player1->SetCurrentWeapon(new Revolver());
				}
				else if (p1choice == PlayerChoice::shotgun)
				{
					_player1->SetCurrentWeapon(new Shotgun());
				}				
				for (int i = 0; i < _player1->GetWeapon()->GetBullets().size(); i++)
				{
					_colManager.AddToCollisionManager(_player1->GetWeapon()->GetBullets()[i]);
				}

				if (p2choice == PlayerChoice::revolver)
				{
					_player2->SetCurrentWeapon(new Revolver());
				}
				else if (p2choice == PlayerChoice::shotgun)
				{
					_player2->SetCurrentWeapon(new Shotgun());
				}
				for (int i = 0; i < _player2->GetWeapon()->GetBullets().size(); i++)
				{
					_colManager.AddToCollisionManager(_player2->GetWeapon()->GetBullets()[i]);
				}

				gameTimer = gameTime;
			}
				break;
		case Stage::gameplay:
			
			if (!_obstacles[stagesPlayed%_obstacles.size()]->getIsActive())
			{
				_obstacles[stagesPlayed]->setIsActive(true);
			}
			currentBackground = stagesPlayed % _background.size();
			stagesPlayed++;

			restoreObstacles(_obstacles);

			gameTimer = gameTime;
			break;
		}
	}

	void restoreObstacles(vector<Obstacles*> obstacles)
	{
		for (int i = 0; i < obstacles.size(); i++)
		{
			if (dynamic_cast<Cactus*>(obstacles[i]) != NULL)
			{
				dynamic_cast<Cactus*>(obstacles[i])->restoreCactus();
			}
			else if (dynamic_cast<Tree*>(obstacles[i]) != NULL)
			{
				dynamic_cast<Tree*>(obstacles[i])->restoreTree();
			}
		}
	}

	void deactivateObstacles(vector<Obstacles*> obstacles)
	{
		for (int i = 0; i < obstacles.size(); i++)
		{
			if (obstacles[i]->getIsActive())
			{
				obstacles[i]->setIsActive(false);
			}
		}
	}

	void Gameplay::ToCredits()
	{
		stagesPlayed = 0;
		_player1->SetX(player1Pos.x);
		_player1->SetY(player1Pos.y);
		_player2->SetX(player2Pos.x);
		_player2->SetY(player2Pos.y);
		_p1Score = 0;
		_p2Score = 0;
		restoreObstacles(_obstacles);
		deactivateObstacles(_obstacles);
		_toCredits = true;
		_timer = gameTime;
	}
}