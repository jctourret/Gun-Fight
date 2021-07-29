#ifndef ANIMATION_H
#define ANIMATION_H
#include "raylib.h"
#include <vector>

class Animation
{
	std::vector<Vector2>* _frameCoords;
	int _currentFrame;
	float _animTime;
	float _animTimer;
	bool _looping;
public:
	Animation(float animTime, bool looping);
	void runAnimation();
	std::vector<Vector2> addFrameCoords(Vector2 frameCoords);
};

#endif