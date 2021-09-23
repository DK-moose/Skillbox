#include "manager.h"

Manager::Manager(int serial_number, Director *director)
{
	this->serial_number = serial_number;
	this->director = director;
}

int Manager::GetSerialNumber()
{
	return serial_number;
}

Director* Manager::GetDirector()
{
	return director;
}

void Manager::GetCoreForSrand()
{
	srand(director->GetIdCommand() + serial_number);
}