#include "record.h"

string Record::GetNumber()
{
	return number;
}

string Record::GetName()
{
	return name;
}

void Record::SetNumber(string number)
{
	this->number = number;
}

void Record::SetName(string name)
{
	this->name = name;
}