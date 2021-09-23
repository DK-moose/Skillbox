#pragma once
#include "figure.h"

class Rectangle : Figure
{
private:
    double width;
    double height;

public:
    Rectangle(Point *center, string color, double width, double height);
	double GetWidth();
	double GetHeight();
	double GetSquare();
	void GetDescribedRectangle();
};
