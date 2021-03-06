#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

bool IsTrueSurname(string str)
{
	if (str[0] < 'A' || str[0] > 'Z')
		return false;
	for (int i = 1; i < str.length(); i++)
		if (str[i] < 'a' || str[i] > 'z')
			return false;
	return true;
}

int main()
{
	string surname;
	int sizeQ = 0;
	map<string, int> queue;
	do
	{
		cout << "Input surname or 'Next': ";
		cin >> surname;
		if (surname == "Next")
		{
			sizeQ--;
			if (sizeQ > 0)
			{
				queue.erase(queue.begin());
				cout << queue.begin()->first << endl;
			}
		}
		else if (IsTrueSurname(surname))
		{
			queue.insert(make_pair<string, int>(surname, sizeQ));
			sizeQ++;
		}
	} while (sizeQ > 0);
	return 0;
}