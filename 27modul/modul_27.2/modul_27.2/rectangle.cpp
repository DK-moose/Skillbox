#include "rectangle.h"

Rectangle::Rectangle(Point *center, string color, double width, double height)
{
    this->center = center;
    this->SetColor(color);
    this->width = width;
    this->height = height;
}

double Rectangle::GetWidth()
{
	return width;
}

double Rectangle::GetHeight()
{
	return height;
}

double Rectangle::GetSquare()
{
    return width * height;
}

void Rectangle::GetDescribedRectangle()
{
	Figure::GetDescribedRectangle(width / 2, height / 2);
}