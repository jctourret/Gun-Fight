#include "Screen.h"

Screen::Screen(){
	_resolution.width=screenWidth;
	_resolution.height=screeenHeight;
}

Screen::~Screen(){
}
void Screen::setResolutionWidth(int width){
	_resolution.width = width;
}
void Screen::setResolutionHeight(int height){
	_resolution.height = height;
}
int Screen::getResolutionWidth(){
	return _resolution.width;
}
int Screen::getResolutionHeight() {
	return _resolution.height;
}