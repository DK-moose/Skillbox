#include "phone.h"

bool Phone::IsDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool Phone::IsNumber(string number)
{
	if (number.length() == 12 && number[0] == '+')
	{
		for (int i = 1; i < number.length(); i++)
			if (!IsDigit(number[i]))
				return false;
		return true;
	}
	return false;
	
}

map<string, string>* Phone::GetDirectory()
{
	return &directory;
}

void Phone::SetDirectory(map<string, string> &directory)
{
	this->directory = directory;
}

void Phone::Add(Record &record)
{	
	for(map<string, string>::iterator it = directory.begin(); it != directory.end(); ++it)
	{
		if (it->first == record.GetNumber() || it->second == record.GetName())
		{
			cout << "This contact already exists!" << endl;
			return;
		}
	}
	pair<string, string> oRec(record.GetNumber(), record.GetName());
	directory.insert(oRec);
}

void Phone::Call(string nameOrPhone)
{
	if (IsNumber(nameOrPhone))
	{
		cout << "CALL " << nameOrPhone << endl;
		return;
	}
	else
	{		
		for(map<string, string>::iterator it = directory.begin(); it != directory.end(); ++it)
		{
			if (it->first == nameOrPhone || it->second == nameOrPhone)
			{
				cout << "CALL " << it->first << endl;
				return;
			}
		}
		cout << "There is no such contact!" << endl;
	}
}

void Phone::Sms(string nameOrPhone)
{
	string sms;
	if (IsNumber(nameOrPhone))
	{
		cout << "Input sms (input '-1' for end): " << endl;
		while (sms != "-1")
		{
			cin >> sms;
		}
		cout << "SENT" << endl;
		return;
	}
	else
	{
		for (map<string, string>::iterator it = directory.begin(); it != directory.end(); ++it)
		{
			if (it->first == nameOrPhone || it->second == nameOrPhone)
			{
				cout << "Input sms: " << endl;
				while (sms != "-1")
				{
					cin >> sms;
				}
				cout << "SENT" << endl;
				return;
			}
		}
		cout << "There is no such contact!" << endl;
	}
}