#include "Wagon.h"

namespace GunFight
{
	enum class Distance {close, away, far};

	Distance currentDistance = Distance::close;
	const int sheetColumns = 3;
	const int sheetRows = 1;

	const int awayXOffset = 10;
	const int awayYOffset = 9;
	const int awayHeight = 67;
	const int awayWidth = 64;

	const int farXOffset = 21;
	const int farYOffset = 18;
	const int farHeight = 44;
	const int farWidth = 43;

	float wagonSpeed = 100;

	Wagon::Wagon(Vector2 pos) : Obstacles(pos,"wagon","res/assets/img/WagonSheet.png")
	{
		_isActive = true;

		_frameRec.y = 0;
		_frameRec.width = _sheet.width / sheetColumns;
		_frameRec.x = (int)currentDistance * _frameRec.width;
		_frameRec.height = _sheet.height / sheetRows;

		_body.x = pos.x - _frameRec.width/2;
		_body.width = _frameRec.width;
		_body.height = _frameRec.height;

		_startingPointX = _body.x;
		_startingPointY = _body.y;
		_startingSizeX = _frameRec.width;
		_startingSizeY = _frameRec.height;
	}

	void Wagon::update()
	{
		if (_body.y > GetScreenHeight()/4)
		{
			_body.y -= GetFrameTime() * wagonSpeed;
			_pos.x = _body.x;
			_pos.y = _body.y;
		}
		switch (currentDistance)
		{
		case Distance::close:
			if (_body.y <= GetScreenHeight() - GetScreenHeight() / 4)
			{
				currentDistance = Distance::away;
				_frameRec.x = (int)currentDistance * _startingSizeX + awayXOffset;
				_frameRec.y = (int)currentDistance * _startingSizeY + awayYOffset;
				_frameRec.width = awayWidth;
				_frameRec.height = awayHeight;
				_body.y = _body.y + _body.height - awayHeight;
				_body.height = awayHeight;
				_body.x = _body.x + _body.width - awayWidth - awayXOffset;
				_body.width = awayWidth;
			}
			break;
		case Distance::away:
			if (_body.y <= GetScreenHeight() / 2)
			{
				currentDistance = Distance::far;
				_frameRec.x = (int)currentDistance * _startingSizeX + farXOffset;
				_frameRec.y = (int)currentDistance * _startingSizeY + farYOffset;
				_frameRec.width = farWidth;
				_frameRec.height = farHeight;
				_body.y = _body.y + _body.height - farHeight;
				_body.height = farHeight;
				_body.x = _body.x + _body.width - farWidth - farXOffset;
				_body.width = farWidth;
			}
			break;
		case Distance::far:
			if (_body.y <= GetScreenHeight() /4)
			{
				currentDistance = Distance::close;
				_frameRec.x = (int)currentDistance * _startingSizeX;
				_frameRec.y = 0;
				_frameRec.width = _startingSizeX;
				_frameRec.height = _startingSizeY;
				_body.x = _startingPointX;
				_body.y = _startingPointY;
				_body.width = _startingSizeX;
				_body.height = _startingSizeY;
			}
			break;
		}
		
	}

	void Wagon::draw()
	{
		DrawTextureRec(_sheet, _frameRec, _pos, WHITE);
	}
	void Wagon::OnCollisionEnter(IColisionable* other)
	{

	}
	void Wagon::OnCollisionStay(IColisionable* other)
	{

	}
	void Wagon::OnCollisionExit(IColisionable* other)
	{
	
	}

}