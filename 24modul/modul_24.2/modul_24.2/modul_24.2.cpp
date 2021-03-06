#include "pch.h"
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

bool IsName(string name)
{
	if (name == "end") return true;
	if (name[0] < 'A' || name[0] > 'Z')
		return false;
	for (int i = 1; i < name.length(); i++)
		if (name[i] < 'a' || name[i] > 'z')
			return false;
	return true;
}

int main()
{
	vector<tm> birthdays;
	vector<string> names;
	time_t t = time(nullptr);
	tm birthday = *localtime(&t);
	string name;
	while (true)
	{
		while (true)
		{
			cout << "Input name: ";
			cin >> name;
			if (IsName(name)) 
				break;
			else cout << "Error: invalid name! Try again." << endl;
		}
		if (name == "end") 
			break;
		cout << "Input date of birth (YYYY/MM/DD): ";
		cin >> get_time(&birthday, "%Y/%m/%d");
		names.push_back(name);
		birthdays.push_back(birthday);
		cout << endl;
	}

	time_t today = time(nullptr);
	tm local = *localtime(&today);
	tm localForCheck = local;
	int months = 13;
	int days = 32;
	for (int i = local.tm_mon; i < 12 && i < months; i++)
	{
		for (int j = 0; j < birthdays.size(); j++)
		{
			if (birthdays[j].tm_mon == i && birthdays[j].tm_mday < days)
			{
				months = birthdays[j].tm_mon;
				days = birthdays[j].tm_mday;
			}
		}
	}
	if (local.tm_mon == months && local.tm_mday == days)
		cout << "Today is the birthday: " << endl;
	else cout << "The nearest birthday is at: " << endl;
	int countBirthdayPeople = 0;
	for (int i = 0; i < birthdays.size(); i++)
	{
		if (birthdays[i].tm_mon == months && birthdays[i].tm_mday == days)
		{
			cout << put_time(&birthdays[i], "%Y/%m/%d") << " " << names[i] << endl;
			countBirthdayPeople++;
		}
	}
	if (countBirthdayPeople == 0)
		cout << "There are no birthdays this year!" << endl;
	return 0;
}
