#pragma once
const int screenWidth = 1280;
const int screeenHeight = 720;
struct Resolution {
	int width;
	int height;
};

class Screen{
private:
	Resolution _resolution;
public:
	Screen();
	~Screen();
	void setResolutionWidth(int width);
	void setResolutionHeight(int height);
	int getResolutionWidth();
	int getResolutionHeight();
};

