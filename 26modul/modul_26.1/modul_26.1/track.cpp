#include "track.h"

string Track::GetName()
{
	return name;
}

tm* Track::GetDateOfCreate()
{
	return &dateOfCreate;
}

int Track::GetDuration()
{
	return durationInSeconds;
}

void Track::SetName(string name)
{
	this->name = name;
}

void Track::SetDateOfCreate(tm &dateOfCreate)
{
	this->dateOfCreate = dateOfCreate;
}

void Track::SetDuration(int durationInSeconds)
{
	this->durationInSeconds = durationInSeconds;
}
	