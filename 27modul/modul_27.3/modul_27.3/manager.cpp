#include "manager.h"

Manager::Manager(int serial_number, Group *group)
{
	this->serial_number = serial_number;
	this->group = group;
}

int Manager::GetSerialNumber()
{
	return serial_number;
}

Group* Manager::GetGroup()
{
	return group;
}