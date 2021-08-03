#include "Cactus.h"

namespace GunFight
{

	enum class CactusStages { whole, damaged, destroyed};

	float damagedHeight = 30;
	float destroyedHeight = 8;

	const int sheetColumns = 3;
	const int sheetRows = 1;
	CactusStages currentStage = CactusStages::whole;

	Cactus::Cactus(Vector2 pos) : Obstacles(pos,"Cactus","res/assets/img/CactusSheet.png")
	{
		_frameRec.y = 0;
		_frameRec.width = _sheet.width/sheetColumns;
		_frameRec.x = (int)currentStage * _frameRec.width;
		_body.width = _frameRec.width;
		_frameRec.height = _sheet.height / sheetRows;
		_body.height = _frameRec.height;

		_startingPointX = _body.x;
		_startingPointY = _body.y;
		_startingSizeX = _body.width;
		_startingSizeY = _body.height;
	}

	void Cactus::restoreCactus() {
		currentStage = CactusStages::whole;
		_frameRec.x = (int)currentStage * _frameRec.width;
		_body.x = _startingPointX;
		_body.y = _startingPointY;
		_body.width = _startingSizeX;
		_body.height = _startingSizeY;
	}

	void Cactus::draw()
	{
		if (_isActive)
		{
			DrawTextureRec(_sheet, _frameRec, _pos, WHITE);
		}
	}

	void Cactus::OnCollisionEnter(IColisionable* other)
	{
		
	}

	void Cactus::OnCollisionStay(IColisionable* other)
	{
		
	}

	void Cactus::OnCollisionExit(IColisionable* other)
	{
		if (_isActive && other->GetTag() == "Bullet")
		{
			switch (currentStage)
			{
			case GunFight::CactusStages::whole:
				currentStage = CactusStages::damaged;
				_frameRec.x = (int)currentStage * _frameRec.width;
				_body.y = _body.y + _body.height - damagedHeight;
				_body.height = damagedHeight;
				break;
			case GunFight::CactusStages::damaged:
				currentStage = CactusStages::destroyed;
				_frameRec.x = (int)currentStage * _frameRec.width;
				_body.y = _body.y + _body.height - destroyedHeight;
				_body.height = destroyedHeight;
				break;
			case GunFight::CactusStages::destroyed:
				break;
			}
		}
	}
}