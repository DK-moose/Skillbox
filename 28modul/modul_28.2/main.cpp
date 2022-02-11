#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "train.h"

using namespace std;

vector<Train*> trains(3);
mutex _station;
mutex _output;
bool stationIsFree = true;

void wait_for_depart(int index)
{
	this_thread::sleep_for(chrono::seconds(trains[index]->GetTravelTime()));	
	if (!stationIsFree)
	{
		_output.lock();
		cout << "\nTrain " << trains[index]->GetName() << " is waiting for an empty seat!" << endl;
		_output.unlock();
	}
	_station.lock();
    stationIsFree = false;
	string commandForTrain;

	while (true)
	{
		_output.lock();
		cout << "Train " << trains[index]->GetName() << " has arrived and ready to depart!" << endl;
		cout << "Input command 'depart' to release the station!" << endl;
		_output.unlock();
		cin >> commandForTrain;
		if (commandForTrain != "depart")
		{
			_output.lock();
			cout << "Invalid command! Try again" << endl;
			_output.unlock();
		}
		else
		{
			_output.lock();
			stationIsFree = true;
			cout << "\nThe train " << trains[index]->GetName() << " left the station!" << endl;
			_output.unlock();
			break;
		}
	}
	_station.unlock();
}

int main()
{
	int travelTime;
	for (int i = 0; i < trains.size(); i++)
	{
		cout << "Input travel time for the train " << (char)(65 + i) << ": ";
		cin >> travelTime;
		trains[i] = new Train(65 + i, travelTime);
	}

	thread t1(wait_for_depart, 0);
	thread t2(wait_for_depart, 1);
	thread t3(wait_for_depart, 2);

	t1.join();
	t2.join();
	t3.join();

	cout << "All trains left the station!" << endl;
	return 0;
}
