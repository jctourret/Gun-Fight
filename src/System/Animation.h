#ifndef ANIMATION_H
#define ANIMATION_H
#include "raylib.h"
#include <vector>

class Animation
{
	std::vector<Vector2> _frameCoords;
	int _currentFrame;
	float _animTime;
	float _frameTimer;
	bool _looping;
public:
	Animation(float animTime, bool looping);
	bool RunAnimation(Rectangle &rectangle);
	void AddFrameCoords(float x, float y);
};
#endif