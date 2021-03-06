#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void InitRiver(string path)
{
	ofstream river;
	river.open(path, ios::out | ios::app);
	if (river.is_open())
	{
		river << "sunfish" << endl;
		river << "shad" << endl;
		river << "carp" << endl;
		river << "bass" << endl;
		river << "bullhead" << endl;
		river << "carp" << endl;
		river << "walleye" << endl;
		river << "catfish" << endl;
		river << "carp" << endl;
		river.close();
	}
	else
	{
		cout << "Error: couldn't open the file 'river.txt'" << endl;
		return;
	}
}

void CleanFile(string path)
{
	ofstream file;
	file.open(path, ios::out);
	if (file.is_open())
	{
		file << "";
		file.close();
	}
	else
	{
		cout << "Error: couldn't open the file '" << path << "'" << endl;
		return;
	}
}

int main()
{
	ifstream river;
	ofstream basket;
	string typeOfFish;
	char startFlag;
	int countFish = 0;
	CleanFile("river.txt");
	InitRiver("river.txt");
	CleanFile("basket.txt");
	while (true)
	{
		cout << "Do you want to go fishing (y/n)? ";
		cin >> startFlag;
		if (startFlag == 'y')
		{	
			river.open("river.txt", ios::in);
			if (river.is_open())
			{
				cout << endl << "Input type of fish: ";
				cin >> typeOfFish;
			}
			else
			{
				cout << "Error: couldn't open the file 'river.txt'" << endl;
				return 0;
			}
			basket.open("basket.txt", ios::out | ios::app);
			if (basket.is_open())
			{
				while (!river.eof())
				{
					string fish;
					river >> fish;
					if (fish == typeOfFish)
					{
						basket << fish << endl;
						countFish++;
					}
				}
				basket.close();
			}
			{
				cout << "Error: couldn't open the file 'basket.txt'" << endl;
				return 0;
			}
			river.seekg(0);
			river.close();
		}
		else if (startFlag == 'n')
			break;
		else cout << "Invalid command! Try again." << endl;
	}
	cout << "The result of your fishing - " << countFish << " fish." << endl;
	return 0;
}