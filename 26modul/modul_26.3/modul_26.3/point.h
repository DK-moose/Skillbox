#pragma once
#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;

public:
	Point();
	Point(int x, int y);
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
};