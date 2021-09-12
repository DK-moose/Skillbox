#pragma once
#include <iostream>
#include <string>

using namespace std;
class Record
{
private:
	string number;
	string name;

public:
	string GetNumber();
	string GetName();
	void SetNumber(string number);
	void SetName(string name);
};
