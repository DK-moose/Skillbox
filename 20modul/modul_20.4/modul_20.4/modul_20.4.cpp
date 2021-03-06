#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define MAX_BANKNOTES 1000
#define COUNT_BILLS 6

using namespace std;
int MaxInATM(int *banknotes, int maxBill)
{
	int max = 0;
	for (int i = 0; i < MAX_BANKNOTES; i++)
		if (banknotes[i] > max && banknotes[i] <= maxBill)
			max = banknotes[i];
	return max;
}

int MaxBillForIssuing(int sum, int *bills)
{
	int index = COUNT_BILLS - 1;
	while (true)
	{
		if (sum / bills[index] != 0)
			return bills[index];
		else index--;
		if (index == -1)
			return index;
	}
}

string WithdrawСash(string path, int* banknotes, int *bills, int sum)
{
	string result = "The ATM issues " + to_string(sum) + " = ";
	vector<int> terms;
	while (sum != 0)
	{
		int maxValForSum = MaxBillForIssuing(sum, bills);
		if (maxValForSum == -1)
		{
			cout << "Error: The operation cannot be performed." << endl;
			for (int i = 0; i < MAX_BANKNOTES && terms.size() > 0; i++)
			{
				if (banknotes[i] == 0)
				{
					banknotes[i] = terms[terms.size() - 1];
					terms.pop_back();
				}
			}
			return "";
		}
		int maxVal = MaxInATM(banknotes, maxValForSum);
		if (maxVal == 0)
		{
			cout << "Error: The operation cannot be performed." << endl;
			for (int i = 0; i < MAX_BANKNOTES && terms.size() > 0; i++)
			{
				if (banknotes[i] == 0)
				{
					banknotes[i] = terms[terms.size() - 1];
					terms.pop_back();
				}
			}
			return "";
		}

		for (int i = 0; i < MAX_BANKNOTES; i++)
		{
			if (banknotes[i] == maxVal)
			{
				banknotes[i] = 0;
				sum -= maxVal;
				terms.push_back(maxVal);
				result += to_string(maxVal) + " + ";
				break;
			}
		}
	}

	ofstream atm(path, ios::binary);
	atm.write((char *)banknotes, MAX_BANKNOTES * sizeof(banknotes[0]));
	atm.close();
	return result.substr(0, result.length() - 3);
}

void DepositСash(string path, int *banknotes, int *bills)
{
	for (int i = 0; i < MAX_BANKNOTES; i++)
		if (banknotes[i] == 0)
			banknotes[i] = bills[rand() % 6];

	ofstream atm(path, ios::binary);
	atm.write((char *)banknotes, MAX_BANKNOTES * sizeof(banknotes[0]));
	atm.close();
}

int main()
{
	int bills[COUNT_BILLS] = { 100, 200, 500, 1000, 2000, 5000 };
	int banknotesInATM[MAX_BANKNOTES];
	string atmPath = "atm.bin";
	string operationFlag;

	while (true)
	{
		cout << "Input operation flag (+/-): ";
		cin >> operationFlag;
		if (operationFlag != "+" && operationFlag != "-")
			cout << "Invalit command. Try again." << endl;
		else break;
	}
	ifstream file(atmPath, ios::binary);
	if (file.is_open())
	{
		file.read((char *)banknotesInATM, sizeof(banknotesInATM));
		file.close();
	}
	else
	{
		for (int i = 0; i < MAX_BANKNOTES; i++)
			banknotesInATM[i] = 0;
	}

	if (operationFlag == "+")
		DepositСash(atmPath, banknotesInATM, bills);
	else
	{
		int sum;
		while (true)
		{
			cout << "Input sum: ";
			cin >> sum;
			if (sum % 100 != 0)
				cout << "Incorrect sum. Try again." << endl;
			else break;
		}

		cout << WithdrawСash(atmPath, banknotesInATM, bills, sum);
	}
	return 0;
}
