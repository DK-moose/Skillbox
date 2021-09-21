#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;
class Track
{
private:
	string name;
	tm dateOfCreate;
	int durationInSeconds;

public:
	Track(string name, tm* dateOfCreate, int durationInSeconds);
	string GetName();
	tm* GetDateOfCreate();
	int GetDuration();
	//void SetName(string name);
	//void SetDateOfCreate(tm &dateOfCreate);
	//void SetDuration(int durationInSeconds);
};
