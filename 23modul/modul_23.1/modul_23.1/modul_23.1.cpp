#include "pch.h"
#include <iostream>
#define MONDAY "MONDAY"
#define TUESDAY "TUESDAY"
#define WEDNESDAY "WEDNESDAY"
#define THURSDAY "THURSDAY"
#define FRIDAY "FRIDAY"
#define SATURDAY "SATURDAY"
#define SUNDAY "SUNDAY"
#define NUM_MONDAY 1
#define NUM_TUESDAY 2
#define NUM_WEDNESDAY 3
#define NUM_THURSDAY 4
#define NUM_FRIDAY 5
#define NUM_SATURDAY 6
#define NUM_SUNDAY 7
#define DAY(flag, day) flag ## _ ## day

using namespace std;

int main()
{
	int NUM = 0;
	cout << "Input the number day of the week: ";
	cin >> NUM;
	switch (NUM)
	{
	case DAY(NUM, MONDAY):
	{
		cout << MONDAY << endl;
		break;
	}
	case DAY(NUM, TUESDAY):
	{
		cout << TUESDAY << endl;
		break;
	}
	case DAY(NUM, WEDNESDAY):
	{
		cout << WEDNESDAY << endl;
		break;
	}
	case DAY(NUM, THURSDAY):
	{
		cout << THURSDAY << endl;
		break;
	}
	case DAY(NUM, FRIDAY):
	{
		cout << FRIDAY<< endl;
		break;
	}
	case DAY(NUM, SATURDAY):
	{
		cout << SATURDAY << endl;
		break;
	}
	case DAY(NUM, SUNDAY):
	{
		cout << SUNDAY << endl;
		break;
	}
	default:
	{
		cout << "ERROR!";
		break;
	}
	}
	return 0;
}

