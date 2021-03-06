#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool IsDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool IsNumber(string number)
{
	if (number.length() != 8)
		return false;
	for (int i = 0; i < number.length(); i++)
		if (!IsDigit(number[i]) || !IsDigit(number[i + 1]) ||
			(number[i + 2] != '\0' && number[i + 2] != '-'))
			return false;	
	return true;
}

bool IsSurname(string surname)
{
	if (surname[0] < 'A' || surname[0] > 'Z')
		return false;
	for (int i = 0; i < surname.length(); i++)
		if (surname[i] < 'a' || surname[i] > 'z')
			return false;	
	return true;
}

bool IsNumberWithSurname(string nws)
{
	return (IsNumber(nws.substr(0, 8)) && IsSurname(nws.substr(9)));
}

int main()
{
	string record;
	map<string, string> numberToSurname;
	map<string, vector<string>> surnameToNumbers;

	while (true)
	{
		cout << "Input NUMBER and SURNAME for adding new records;" << endl;
		cout << "\tNUMBER for search surnames;" << endl;
		cout << "\tSURNAME for search phone number;" << endl;
		cout << "\t'-1' for exit." << endl;
		cout << "-> ";
		cin >> record;
		if (IsNumber(record))
		{
			map<string, string>::iterator requiredContact = numberToSurname.find(record);
			if (requiredContact != numberToSurname.end())
				cout << requiredContact->second << endl;
			else cout << "There is no such number!" << endl;
		}
		else if (IsSurname(record))
		{
			map<string, vector<string>>::iterator requiredContacts = surnameToNumbers.find(record);
			if (requiredContacts != surnameToNumbers.end())
			{
				for (int i = 0; i < requiredContacts->second.size(); i++)
					cout << requiredContacts->second[i];
			}
			else cout << "There is no such surname!" << endl;
		}
		else if (IsNumberWithSurname(record))
		{
			pair<string, string> ntos(record.substr(0, 8), record.substr(9));
			numberToSurname.insert(ntos);
			map<string, vector<string>>::iterator it = surnameToNumbers.find(ntos.second);
			if (it != surnameToNumbers.end())
			{
				for (int i = 0; i < it->second.size(); i++)
				{
					if (it->second[i] == ntos.first)
						break;
					else if (i < it->second.size() - 1)
						continue;
					else it->second.push_back(record.substr(0, 8));
				}
			}
		}
		else if (record == "-1") break;
		else cout << "Error! Try again!" << endl;
	}
	return 0;
}