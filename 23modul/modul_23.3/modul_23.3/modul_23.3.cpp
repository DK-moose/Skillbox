#include "pch.h"
#include <iostream>
#define SPRING "Spring"
#define SUMMER "Summer"
#define AUTUMN "Autumn"
#define WINTER "Winter"
#define ERROR "Error!"

using namespace std;
int main()
{
#if 1
	cout << SPRING << endl;
	//cout << SUMMER << endl;
	//cout << AUTUMN << endl;
	//cout << WINTER << endl;
#else
	cout << ERROR << endl;
#endif
}
