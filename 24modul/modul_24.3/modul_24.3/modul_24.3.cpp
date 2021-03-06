#include "pch.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	int timeInSec;
	time_t t = time(nullptr);
	tm* input_t = localtime(&t);
	cout << "Input time (MM:SS): ";
	cin >> get_time(input_t, "%M:%S");	
	t = time(nullptr);
	timeInSec = input_t->tm_min * 60 + input_t->tm_sec;
	while (timeInSec > 0)
	{
		time_t now_t = time(nullptr);
		if (now_t != t)
		{
			t = now_t;
			timeInSec--;
			system("cls");
			cout << to_string(timeInSec / 60) << ":" << to_string(timeInSec % 60) << endl;
		}		
	}
	cout << "DING! DING! DING!" << endl;
	return 0;
}