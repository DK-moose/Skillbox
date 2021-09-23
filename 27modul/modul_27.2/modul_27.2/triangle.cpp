#include "triangle.h"

Triangle::Triangle(Point *center, string color, double width)
{
    this->center = center;
    this->SetColor(color);
    this->width = width;
}

double Triangle::GetWidth()
{
	return width;
}

double Triangle::GetSquare()
{
    return width * width / 2;
}

void Triangle::GetDescribedRectangle()
{
	Figure::GetDescribedRectangle(width / 2, width / 2);
}