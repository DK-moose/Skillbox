#include "square.h"

Square::Square(Point *center, string color, double width)
{
    this->center = center;
    this->SetColor(color);
    this->width = width;
}

double Square::GetWidth()
{
	return width;
}

double Square::GetSquare()
{
    return width * width;
}

void Square::GetDescribedRectangle()
{
	Figure::GetDescribedRectangle(width / 2, width / 2);
}
