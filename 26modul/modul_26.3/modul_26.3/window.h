#pragma once
#include "point.h"
#include "screen.h"

class Window
{
private:
	Point start;
	int width;
	int height;

public:
	Window();
	Window(Point start, int width, int height);
	void WindowToScreen(Screen &screen);
	void Move(int x, int y);
	void Resize(int w, int h);
};