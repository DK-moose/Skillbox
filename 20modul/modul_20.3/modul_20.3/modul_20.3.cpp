#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void InitRiver(string path)
{
	ofstream river;
	river.open(path, ios::out | ios::app);
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

void CleanFile(string path)
{
	ofstream file;
	file.open(path, ios::out);
	file << "";
	file.close();
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
			if (!river.is_open())
				river.open("river.txt", ios::in);
			cout << endl << "Input type of fish: ";
			cin >> typeOfFish;

			if (!basket.is_open())
				basket.open("basket.txt", ios::out | ios::app);
			
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
			river.seekg(0);
		}
		else if (startFlag == 'n')
			break;
		else cout << "Invalid command! Try again." << endl;
	}
	if (river.is_open()) river.close();
	if (basket.is_open()) basket.close();
	cout << "The result of your fishing - " << countFish << " fish." << endl;
	return 0;
}