#include "point.h"

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

double Point::GetX()
{
    return x;
}

double Point::GetY()
{
    return y;
}
