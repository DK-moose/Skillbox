#include "train.h"

Train::Train(char name, int travelTime)
{
	this->name = name;
	this->travelTime = travelTime;
}

char Train::GetName()
{
	return name;
}

int Train::GetTravelTime()
{
	return travelTime;
}