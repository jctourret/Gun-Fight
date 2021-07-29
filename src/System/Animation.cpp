#include "Animation.h"

Animation::Animation(float animTime, bool looping) {
	_frameCoords = new std::vector<Vector2>();
	_animTime = animTime;
	_animTimer = 0;
	_currentFrame = 0;
}

void Animation::runAnimation()
{
	_animTimer += GetFrameTime();
	if (_animTimer >= _animTime/_frameCoords->size())
	{
		_currentFrame++;
		if (_currentFrame++ >= _frameCoords->size())
		{
			 
		}
	}
}

std::vector<Vector2> Animation::addFrameCoords(Vector2 frameCoords)
{
	_frameCoords->push_back(frameCoords);
}