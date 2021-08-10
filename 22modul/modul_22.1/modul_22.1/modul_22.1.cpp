#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;
bool IsDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool IsTruePhoneNumber(string number)
{
	if (number.length() != 8)
		return false;
	for (int i = 0; i < number.length(); i++)
		if (!IsDigit(number[i]) || !IsDigit(number[i + 1]) ||
			(number[i + 2] != '\0' && number[i + 2] != '-'))
			return false;
	return true;
}

bool IsTrueSurname(string surname)
{
	if (surname[0] < 'A' || surname[0] > 'Z')
		return false;
	for (int i = 0; i < surname.length(); i++)
		if (surname[i] < 'a' || surname[i] > 'z')
			return false;
	return true;
}

int main()
{
	string record;
	map<string, string> directory;
	while (true)
	{
		cout << "Input NUMBER and SURNAME for adding new records;" << endl;
		cout << "\tNUMBER for search surnames;" << endl;
		cout << "\tSURNAME for search phone number;" << endl;
		cout << "\t'-1' for exit.";
		cout << "-> ";
		cin >> record;
		if (IsTruePhoneNumber(record.substr(0, 8)))
		{
			if (record.length() > 8 && IsTrueSurname(record.substr(9)))
			{
				directory.insert(record.substr(0, 8), record.substr(9));
			}
			else if (record.length() == 8)
			{
				cout << directory[record];
			}
			else cout << "Error!" << endl;
		}
		else if (IsTrueSurname(record))
		{			
			for (map<string, string>::iterator it = directory.begin(); it != directory.end(); ++it)
			{
				if (it->second == record)
					cout << it->first << endl;
			}
		}
		else if (record == "-1") break;
		else cout << "Error! Try again!" << endl;
	}
	return 0;
}