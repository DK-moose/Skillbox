#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> GetCharContainer(string word)
{
	map<char, int> container;
	for (int i = 0; i < word.length(); i++)
	{
		container.insert(make_pair(word[i], 0));
		container[word[i]]++;
	}
	return container;
}

bool IsAnagram(string first, string second)
{
	if (first.length() != second.length())
		return false;
	if (GetCharContainer(first) != GetCharContainer(second))
		return false;	return true;
}

int main()
{
	string str_first, str_second;
	cout << "Input first string: ";
	cin >> str_first;
	cout << "Input second string: ";
	cin >> str_second;
	if (IsAnagram(str_first, str_second))
		cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	return 0;
}