#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
struct Vector
{
	double x;
	double y;
};

Vector GetSum(Vector &a, Vector &b)
{
	Vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

Vector GetDif(Vector &a, Vector &b)
{
	Vector c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

Vector MultiplyVector(Vector &a, int k)
{
	a.x *= k;
	a.y *= k;
	return a;
}

int GetLength(Vector &a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

Vector GetNormalizeVector(Vector &a)
{
	int len = GetLength(a);
	a.x /= len;
	a.y /= len;
	return a;
}

void InitVector(Vector &a, char name)
{
	cout << "Input the coordinats of the vector '" << name << "' separated by a space: ";
	cin >> a.x >> a.y;
}

int main()
{
	string command;
	while (true)
	{
		cout << "Input command (add, substract, scale, length, normalize): ";
		cin >> command;
		if (command != "add" && command != "substract" && command != "scale" && command != "length" && command != "normalize")
			cout << "Invalid command! Try again!" << endl;
		else break;
	}
	Vector a;
	Vector b;
	Vector c;
	if (command == "add")
	{
		InitVector(a, 'A');
		InitVector(b, 'B');
		c = GetSum(a, b);
		cout << "Result: (" << c.x << " ," << c.y << ")." << endl;
	}
	else if (command == "substract")
	{
		InitVector(a, 'A');
		InitVector(b, 'B');
		c = GetDif(a, b);
		cout << "Result: (" << c.x << " ," << c.y << ")." << endl;
	}
	else if (command == "scale")
	{
		InitVector(a, 'A');
		int k;
		cout << "Input multiplier: ";
		cin >> k;
		c = MultiplyVector(a, k);
		cout << "Result: (" << c.x << " ," << c.y << ")." << endl;
	}
	else if (command == "length")
	{
		InitVector(a, 'A');
		cout << "Result: " << GetLength(a) << endl;
	}
	else
	{
		InitVector(a, 'A');
		c = GetNormalizeVector(a);
		cout << "Result: (" << c.x << " ," << c.y << ")." << endl;
	}
	return 0;
}