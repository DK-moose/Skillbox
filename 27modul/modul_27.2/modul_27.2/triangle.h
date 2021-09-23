#pragma once
#include "figure.h"

class Triangle : Figure
{
private:
    double width;

public:
    Triangle(Point *center, string color, double width);
	double GetWidth();
	double GetSquare();
	void GetDescribedRectangle();
};
