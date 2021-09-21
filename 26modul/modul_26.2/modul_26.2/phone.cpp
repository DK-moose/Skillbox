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

void Phone::RemoveDir()
{
	for (int i = 0; i < directory.size(); i++)
		delete directory[i];
}

void Phone::Add(Record *record)
{	
	for(int i = 0; i < directory.size(); i++)
	{
		if (directory[i]->GetNumber() == record->GetNumber() || directory[i]->GetName() == record->GetName())
		{
			cout << "This contact already exists!" << endl;
			return;
		}
	}
	directory.push_back(record);
}

void Phone::Call(string nameOrPhone)
{
	for (int i = 0; i < directory.size(); i++)
	{
		if (directory[i]->GetNumber() == nameOrPhone || directory[i]->GetName() == nameOrPhone)
		{
			cout << "CALL " << directory[i]->GetName() << endl;
			return;
		}
	}
	if (IsNumber(nameOrPhone))
		cout << "CALL " << nameOrPhone << endl;
	else
		cout << "Invalid number!" << endl;
}

void Phone::Sms(string nameOrPhone)
{
	string sms;
	for (int i = 0; i < directory.size(); i++)
	{
		if (directory[i]->GetNumber() == nameOrPhone || directory[i]->GetName() == nameOrPhone)
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
		cout << "Invalid number!" << endl;

}