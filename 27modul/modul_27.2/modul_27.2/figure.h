#pragma once
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
#include "point.h"

class Figure
{
protected:
    Point *center;
    string color;
	
public:
    void SetColor(string color);
	void GetDescribedRectangle(double _x, double _y);	
};
