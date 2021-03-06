#include "pch.h"
#include <iostream>
#include <vector>

#define FOR(n) for (int i = 0; i < n; i++)
#define NUMBER_RAILCARS 10
#define OPTIMAL_VALUE 20
#define GET_RESULT(a, b) a ## _ ## b

using namespace std;
void Crowded_railcars(vector<int> &railcars)
{
	cout << "CROWDED RAILCARS:" << endl;
	FOR(NUMBER_RAILCARS)
		if (railcars[i] > OPTIMAL_VALUE)
		{
			int extra_p = railcars[i] - OPTIMAL_VALUE;
			cout << "In " << i + 1 << " railcar " << extra_p << " extra ";
			if (extra_p == 1) cout << "passanger!" << endl;
			else cout << "passengers!" << endl;
		}
	cout << endl;
}

void Unfilded_railcars(vector<int> &railcars)
{
	cout << "UNFILDED RAILCARS:" << endl;
	FOR(NUMBER_RAILCARS)
		if (railcars[i] < OPTIMAL_VALUE)
		{
			int free_p = OPTIMAL_VALUE - railcars[i];
			cout << "In " << i + 1 << " railcar " << free_p << " free ";
			if (free_p == 1) cout << "place!" << endl;
			else cout << "places!" << endl;
		}
	cout << endl;
}

void Number_passengers(vector<int> &railcars)
{
	cout << "NUMBER OF PASSENGERS: ";
	int n = 0;
	FOR(NUMBER_RAILCARS)
		n += railcars[i];
	cout << n;
	cout << endl << endl;
}

int main()
{
	vector<int> railcars(NUMBER_RAILCARS);
	FOR(NUMBER_RAILCARS)
	{
		cout << "Input number of passengers in " << i + 1 << " railcar: ";
		cin >> railcars[i];
	}
	cout << endl;
	GET_RESULT(Crowded, railcars)(railcars);
	GET_RESULT(Unfilded, railcars)(railcars);
	GET_RESULT(Number, passengers)(railcars);
	return 0;
}

