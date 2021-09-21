#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "record.h"
#define ERROR_INPUT "Error: invalid input!"

using namespace std;
class Phone
{
private:
	vector<Record*> directory;

public:
	static bool IsDigit(char c);
	static bool IsNumber(string number);

	void RemoveDir();
	void Add(Record *record);
	void Call(string nameOrPhone);
	void Sms(string nameOrPhone);
};