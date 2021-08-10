#include "pch.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;
bool TrueSurname(string str)
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
	map<string, string> queue;
	while (true)
	{
		cout << "Input surname or 'Next': ";
		cin >> surname;
		if (surname == "Next")
		{
			if (queue.size() > 0)
				queue.erase(queue.begin());
			if (queue.size() == 0)
				break;
			cout << queue.begin()->second << endl;
		}
		else if (TrueSurname(surname))
		{
			queue.insert(pair<string, string>(surname, surname));
		}
	}
	return 0;
}

