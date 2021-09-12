#pragma once
#include <iostream>
#include <vector>
#include <string>
#define W_WIDTH 80
#define W_HEIGHT 50

using namespace std;

class Screen
{
private:
	int width;
	int height;
	vector<vector<bool>> visualScreen;
	void InitScreen();

public:
	Screen();
	Screen(int width, int height);
	int GetWidth();
	int GetHeight();
	vector<vector<bool>>* GetVsualScreen();
	void SetVisualScreen(vector<vector<bool>> &vs);
	void PrintScreen();
};