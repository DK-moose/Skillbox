#include "circle.h"

Circle::Circle(Point *center, string color, double radius)
{
    this->center = center;
    this->SetColor(color);
    this->radius = radius;
}

double Circle::GetRadius() 
{
	return radius;
}

double Circle::GetSquare() 
{
    return radius * M_PI;
}

void Circle::GetDescribedRectangle()
{
	Figure::GetDescribedRectangle(radius, radius);
}