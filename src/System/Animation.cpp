#include "Animation.h"

Animation::Animation(float animTime, bool looping)
{
	_frameCoords.clear();
	_animTime = animTime;
	_looping = looping;
	_frameTimer = 0;
	_currentFrame = 0;
}

bool Animation::RunAnimation(Rectangle &rectangle)
{
	_frameTimer += GetFrameTime();
	if (_frameTimer >= _animTime/_frameCoords.size())
	{
		_currentFrame++;
		if (_currentFrame >= _frameCoords.size())
		{
			_currentFrame = 0;
			if (!_looping)
			{
				return false;
			}
		}
		_frameTimer = 0;
	}
	rectangle.x = _frameCoords[_currentFrame].x * rectangle.width ;
	rectangle.y = _frameCoords[_currentFrame].y * rectangle.height;
	return true;
}

void Animation::AddFrameCoords(float x, float y)
{
	Vector2 aux = { x,y };
	_frameCoords.push_back(aux);
}