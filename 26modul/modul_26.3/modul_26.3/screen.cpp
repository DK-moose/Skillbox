#include "screen.h"

Screen::Screen()
{
	width = W_WIDTH;
	height = W_HEIGHT;
	this->InitScreen();
}

Screen::Screen(int width, int height)
{
	this->width = width;
	this->height = height;
	this->InitScreen();
}

void Screen::InitScreen()
{
	visualScreen.resize(height);
	for (int i = 0; i < height; i++)
	{
		visualScreen[i].resize(width);
		for (int j = 0; j < width; j++)
			visualScreen[i][j] = false;
	}
}
int Screen::GetWidth()
{
	return width;
}

int Screen::GetHeight()
{
	return height;
}

vector<vector<bool>>* Screen::GetVsualScreen()
{
	return &visualScreen;
}

void Screen::SetVisualScreen(vector<vector<bool>> &vs)
{
	visualScreen = vs;
}

void Screen::PrintScreen()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << visualScreen[i][j];
		cout << endl;
	}
}