#pragma once
#include <iostream>

using namespace std;

void Scalpel(Point a, Point b)
{
    cout << "The CUT was made from point (" << a.x << ", " << a.y << ") to point (" << b.x << ", " << b.y << ")!" << endl;
}

void Hemostat(Point a)
{
    cout << "The CLAMP was made at point (" << a.x << ", " << a.y << ")!" << endl;
}

void Tweezers(Point a)
{
    cout << "The TWEEZERS are applied at point (" << a.x << ", " << a.y << ")!" << endl;
}

void Suture(Point a, Point b)
{
    cout << "The SEAM id made from point (" << a.x << ", " << a.y << ") to point (" << b.x << ", " << b.y << ")!" << endl;
}
