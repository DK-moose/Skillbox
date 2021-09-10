#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Point
{
    double x;
    double y;
};

void InitPoint(Point &a)
{
    cout << "Input coordinats of point (separated by a space): ";
    cin >> a.x >> a.y;
}

void InitPoint(Point &a, string str_flag)
{
    cout << "Input coordinats of the " << str_flag << " point (separated by a space): ";
    cin >> a.x >> a.y;
}
