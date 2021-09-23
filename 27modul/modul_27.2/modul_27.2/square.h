#pragma once
#include "figure.h"

class Square : Figure
{
private:
    double width;

public:
    Square(Point *center, string color, double width);
	double GetWidth();
	double GetSquare();
	void GetDescribedRectangle();
};
