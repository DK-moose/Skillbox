#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;
void InitImage(int w, int h, int** image)
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			image[i][j] = rand() % 2;
}

int main()
{
	srand(time(nullptr));
	int width, height;
	cout << "Input width of image: ";
	cin >> width;
	cout << "Input height of image: ";
	cin >> height;
	int** image = new int* [height];
	for (int i = 0; i < height; i++)
		image[i] = new int[width];
	InitImage(width, height, image);
	ofstream file;
	file.open("pic.txt", ios::out);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file << image[i][j];
		}
		file << "\n";
	}
	cout << "Your image is ready!";
	file.close();
	return 0;
}