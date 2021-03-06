#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool CorrectDateString(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (!isDigit(s[i]) && s[i] != '.')
			return false;
	return true;
}

vector<string> Split(string s, char sep)
{
	vector<string> vec;
	int startIndex = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == sep || i == s.length() - 1)
		{
			vec.push_back(s.substr(startIndex, i + 1));
			startIndex = i + 1;
		}
	}
	return vec;
}

bool CorrectDate(string s)
{
	if (s.length() < 10 || !CorrectDateString(s))
		return false;
	vector<string> date = Split(s, '.');
	if (stoi(date[2]) >= 1900 && stoi(date[2]) <= 2021)
	{
		if (stoi(date[1]) >= 0 || stoi(date[1]) <= 12)
		{
			if (stoi(date[1]) == 2 && stoi(date[2]) % 4 == 0)
			{
				if (stoi(date[0]) <= 29)
					return true;
				return false;
			}
			else if (stoi(date[1]) == 2)
			{
				if (stoi(date[0]) <= 28)
					return true;
				return false;
			}
			else if (stoi(date[0]) <= 31)
				return true;
			return false;
		}
		return false;
	}
	return false;
}

bool DigitsString(string s)
{
	if (s.length() == 0) return false;
	for (int i = 0; i < s.length(); i++)
		if (!isDigit(s[i]))
			return false;
	return true;
}

int main()
{
	char userAnswer;
	ofstream file;
	string name, surname, date, sum;
	while (true)
	{
		date = sum = "";
		cout << "Do you want to input a new record? (y/n) ";
		cin >> userAnswer;
		if (userAnswer == 'y')
		{
			file.open("data.txt", ios::out | ios::app);
			if (file.is_open())
			{
				cout << "\nInput name: ";
				cin >> name;
				cout << "\nInput surname: ";
				cin >> surname;
				while (!CorrectDate(date))
				{
					cout << "\nInput date: ";
					cin >> date;
				}
				while (!DigitsString(sum))
				{
					cout << "\nInput sum: ";
					cin >> sum;
				}
				file << name << " " << surname << " " << date << " " << sum << endl;
				file.close();
			}
			else cout << "Error: couldn't open this file!";
		}
		else if (userAnswer == 'n')
			return 0;
		else cout << "\nInvalid answer! Try again\n";
	}
	return 0;
}