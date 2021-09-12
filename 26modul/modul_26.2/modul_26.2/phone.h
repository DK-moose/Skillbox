#pragma once
#include <iostream>
#include <string>
#include <map>
#include "record.h"
#define ERROR_INPUT "Error: invalid input!"

using namespace std;
class Phone
{
private:
	map<string, string> directory;

public:
	static bool IsDigit(char c);
	static bool IsNumber(string number);

	map<string, string>* GetDirectory();
	void SetDirectory(map<string, string> &directory);
	void Add(Record &record);
	void Call(string nameOrPhone);
	void Sms(string nameOrPhone);
};