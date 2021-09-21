#include "record.h"

Record::Record(string number, string name)
{
	this->number = number;
	this->name = name;
}
string Record::GetNumber()
{
	return number;
}

string Record::GetName()
{
	return name;
}

//void Record::SetNumber(string number)
//{
//	this->number = number;
//}
//
//void Record::SetName(string name)
//{
//	this->name = name;
//}