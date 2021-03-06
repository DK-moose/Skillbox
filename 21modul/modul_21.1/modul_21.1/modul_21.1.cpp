#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
struct Record
{
	string name;
	string surname;
	string date;
	long double payment;

	Record() {};	
	Record(string name, string surname, string date, double payment)
	{
		this->name = name;
		this->surname = surname;
		this->date = date;
		this->payment = payment;
	}
};

void AddRecord(Record &rec, string path)
{
	ofstream file(path, ios::out | ios::app);
	if (file.is_open())
	{
		file << rec.name << ' ' << rec.surname << ' ' << rec.date  << ' ' << to_string(rec.payment);
		file.close();
	}
}

vector<Record> GetListRecords(string path)
{
	ifstream file(path, ios::in);
	vector<Record> records;
	if (file.is_open())
	{
		while (!file.eof())
		{
			Record rec;
			file >> rec.name >> rec.surname >> rec.date >> rec.payment;
			records.push_back(rec);
		}
		file.close();
	}
	return records;
}

int main()
{
	string path = "statement.bin";
	vector<Record> records;
	char command = '0';
	while (true)
	{
		while (true)
		{
			cout << "Input:";
			cout << "\t'1', if your want to add new record;" << endl;
			cout << "\t'2', if your want to see all records;" << endl;
			cout << "\t'3', if your want to get out." << endl;
			cout << "Command: ";
			cin >> command;
			if (command != '1' && command != '2'&& command != '3')
				cout << "Invalid command! Try again." << endl;
			else break;
		}
		if (command == '1')
		{
			Record rec;
			cout << "Input name: ";
			cin >> rec.name;
			cout << "\nInput surname: ";
			cin >> rec.surname;
			cout << "\nInput date (DD.MM.YYYY): ";
			cin >> rec.date;
			cout << "\nInput payment: ";
			cin >> rec.payment;
			AddRecord(rec, path);
		}
		else if (command == '2')
		{
			records = GetListRecords(path);
			for (int i = 0; i < records.size(); i++)
			{
				cout << records[i].name << " ";
				cout << records[i].surname << " ";
				cout << records[i].date << " ";
				cout << records[i].payment << endl;
			}
		}
		else
		{
			return 0;
		}
	}
}