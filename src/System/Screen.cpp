#include "Screen.h"

using namespace GunFight;

namespace GunFight {
	Screen::Screen() {
		_resolution.width = screenWidth;
		_resolution.height = screenHeight;
	}

	Screen::~Screen() {
	}
	void Screen::SetResolutionWidth(int width) {
		_resolution.width = width;
	}
	void Screen::SetResolutionHeight(int height) {
		_resolution.height = height;
	}
	int Screen::GetResolutionWidth() {
		return _resolution.width;
	}
	int Screen::GetResolutionHeight() {
		return _resolution.height;
	}
}