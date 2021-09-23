#pragma once
#include "figure.h"

class Circle : Figure
{
private:
    double radius;

public:
    Circle(Point *center, string color, double radius);
	double GetRadius();
	double GetSquare();
	void GetDescribedRectangle();
};
