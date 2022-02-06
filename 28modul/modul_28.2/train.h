#pragma once

#include <iostream>
#include <string>

using namespace std;
class Train
{
private:
	char name;
	int travelTime;

public:
	Train(char name, int travelTime);
	char GetName();
	int GetTravelTime();
};