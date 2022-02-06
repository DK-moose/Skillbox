#include "swimmer.h"

Swimmer::Swimmer(string name, double speed)
{
	this->name = name;
	this->speed = speed;
}

double Swimmer::GetFinishTime()
{
	return round((currentDistance / speed) * 10) / 10;
}

string Swimmer::GetName()
{
	return name;
}

double Swimmer::GetSpeed()
{
	return speed;
}

double Swimmer::GetDistance()
{
	return currentDistance;
}

void Swimmer::SetDistance(double currentDistance)
{
	this->currentDistance = currentDistance;
}

void Swimmer::PrintInfo()
{
	if (currentDistance < 100)
		cout << name << " swam " << currentDistance << " m " << endl;
	else cout << name << " finished!" << endl;
}

void Swimmer::PrintResult()
{
	cout << name << "\t|\t" << this->GetFinishTime() << " sec" << endl;
}