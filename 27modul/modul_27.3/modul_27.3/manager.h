#pragma once
#include "director.h"
#include <cstdlib>

class Manager
{
private: 
	int serial_number;
	Director *director;

public:
	Manager(int serial_number, Director *director);
	int GetSerialNumber();
	Director* GetDirector();
	void GetCoreForSrand();
};