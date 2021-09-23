#pragma once
#include <iostream>

using namespace std;
class Point
{
private:
    double x;
    double y;

public:
    Point(int x, int y);
    double GetX();
    double GetY();
};
