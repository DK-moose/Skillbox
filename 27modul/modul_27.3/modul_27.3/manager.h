#pragma once
#include "group.h"
#include <cstdlib>

class Manager
{
private: 
	int serial_number;
	Group *group;

public:
	Manager(int serial_number, Group *group);
	int GetSerialNumber();
	Group* GetGroup();
};