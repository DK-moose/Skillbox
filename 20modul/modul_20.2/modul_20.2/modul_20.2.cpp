#include "pch.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
int main()
{
	srand(time(nullptr));
	int width, height;
	cout << "Input width of image: ";
	cin >> width;
	cout << "Input height of image: ";
	cin >> height;
	ofstream file;
	file.open("pic.txt", ios::out);
	if (file.is_open())
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				file << rand() % 2;
			}
			file << "\n";
		}
		cout << "Your image is ready!";
		file.close();
	}
	else cout << "Error: couldn't open this file!" << endl;
	return 0;
}