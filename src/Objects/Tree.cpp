#include "Tree.h"

namespace GunFight
{
	enum class TreeStages {whole, halfDamaged, damaged, destroyed};

	TreeStages currentStage = TreeStages::whole;

	const int halfHeight = 64;
	const int damagedHeight = 42;
	const int destroyedHeight = 30;
	const int sheetColumns = 4;
	const int sheetRows = 1;

	Tree::Tree(Vector2 pos) : Obstacles(pos,"Tree","res/assets/img/TreeSheet.png")
	{
		_frameRec.y = 0;
		_frameRec.width = _sheet.width / sheetColumns;
		_frameRec.x = (int)currentStage * _frameRec.width;
		_body.width = _frameRec.width;
		
		_frameRec.height = _sheet.height / sheetRows;
		_body.height = _frameRec.height;

		_startingPointX = _body.x;
		_startingPointY = _body.y;
		_startingSizeX = _body.width;
		_startingSizeY = _body.height;
	}

	void Tree::restoreTree() {
		currentStage = TreeStages::whole;
		_frameRec.x = (int)currentStage * _frameRec.width;
		_body.x = _startingPointX;
		_body.y = _startingPointY;
		_body.width = _startingSizeX;
		_body.height = _startingSizeY;
	}

	void Tree::draw()
	{
		if (_isActive)
		{
			DrawTextureRec(_sheet, _frameRec, _pos, WHITE);
		}
	}
	void Tree::OnCollisionEnter(IColisionable* other)
	{
		
	}
	void Tree::OnCollisionStay(IColisionable* other)
	{
		
	}
	void Tree::OnCollisionExit(IColisionable* other)
	{
		if (_isActive && other->GetTag() == "Bullet")
		{
			switch (currentStage)
			{
			case GunFight::TreeStages::whole:
				currentStage = TreeStages::halfDamaged;
				_frameRec.x = (int)currentStage * _frameRec.width;
				_body.y = _body.y + _body.height - halfHeight;
				_body.height = halfHeight;
				break;
			case GunFight::TreeStages::halfDamaged:
				currentStage = TreeStages::damaged;
				_frameRec.x = (int)currentStage * _frameRec.width;
				_body.y = _body.y + _body.height - damagedHeight;
				_body.height = damagedHeight;
				break;
				break;
			case GunFight::TreeStages::damaged:
				currentStage = TreeStages::destroyed;
				_frameRec.x = (int)currentStage * _frameRec.width;
				_body.y = _body.y + _body.height - destroyedHeight;
				_body.height = destroyedHeight;
				break;
			case GunFight::TreeStages::destroyed:
				break;
			}
		}
	}
}