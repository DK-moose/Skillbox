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
			return false;	return true;
}

int main()
{
	string record;
	map<string, string> numberToSurname;
	map<string, vector<string>> surnameToNumber;
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
				numberToSurname.insert(record.substr(0, 8), record.substr(9));
				vector<string> vec;
				vec.push_back(record.substr(9));
				surnameToNumber.insert(pair<string, vector<string>>(record.substr(0, 8), vec));
				for (map<string, vector<string>>::iterator it = surnameToNumber.begin(); it != surnameToNumber.end(); ++it)
				{
					if (it->first == vec[0])
					{
						it->second.push_back(record.substr(0, 8));
						break;
					}
				}
			}
			else if (record.length() == 8)
			{
				cout << numberToSurname[record];
			}
			else cout << "Error!" << endl;
		}
		else if (IsTrueSurname(record))
		{
			for (map<string, vector<string> >::iterator it = surnameToNumber.begin(); it != surnameToNumber.end(); ++it)
			{
				if (it->first == record)
				{
					for (int i = 0; i < it->second.size(); i++)
						cout << it->second[i] << endl;
					break;
				}
			}
		}
		else if (record == "-1")
			break;
		else
			cout << "Error! Try again!" << endl;
	}
	return 0;
}