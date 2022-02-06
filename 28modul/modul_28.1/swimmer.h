#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Swimmer
{
private:
	string name;
	double speed;
	double currentDistance = 0;

public:
	Swimmer(string name, double speed);
	string GetName();
	double GetSpeed();
	double GetDistance();
	void SetDistance(double currentDistance);
	double GetFinishTime();
	void PrintInfo();
	void PrintResult();
};