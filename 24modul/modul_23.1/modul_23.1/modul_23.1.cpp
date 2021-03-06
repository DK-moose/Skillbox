#pragma warning(disable : 4996)
#include "pch.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

tm* EndTask(time_t &start, time_t &finish, string currentTask, vector<string> *tasks, vector<int> *difftimes)
{
	finish = time(nullptr);
	tasks->push_back(currentTask);
	difftimes->push_back(difftime(finish, start));
	return localtime(&finish);
}
string GetDiffTimeToString(int dif)
{
	string s = "";
	if (dif >= 3600)
	{
		s += to_string(dif / 3600) + " hours\n";
		dif %= 3600;
	}
	if (dif >= 60)
	{
		s += to_string(dif / 60) + " minutes\n";
		dif %= 60;
	}
	s += to_string(dif) + " seconds";
	return s;
}

int main()
{
	vector<string> tasks;
	vector<int> difftimes;
	time_t start;
	time_t finish;
	tm* localStart = nullptr;
	tm* localFinish;
	string currentTask = "";
	string command;
	while (true)
	{
		cout << "Input command (begin, end, status or exit): ";
		cin >> command;
		if (command == "begin")
		{
			string task;
			cout << "Input task name: ";
			cin >> task;
			if (currentTask != "")
			{
				localFinish = EndTask(start, finish, currentTask, &tasks, &difftimes);
			}
			start = time(nullptr);
			localStart = localtime(&start);
			currentTask = task;
		}
		else if (command == "end" && currentTask != "")
		{
			localFinish = EndTask(start, finish, currentTask, &tasks, &difftimes);
			currentTask = "";
		}
		else if (command == "status")
		{
			for (int i = 0; i < tasks.size(); i++)
			{

				cout << tasks[i] << " " << GetDiffTimeToString(difftimes[i]) << endl;
			}
			if (currentTask != "")
			{
				cout << currentTask << " " << put_time(localStart, "%H:%M:%S") << endl;
			}
		}
		else if (command == "exit")
		{
			break;
		}
		else
		{
			cout << "Error: Invalid command! Try again." << endl;
		}
	}
	return 0;
}
