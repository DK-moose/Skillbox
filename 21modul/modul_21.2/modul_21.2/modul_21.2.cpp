#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
enum { badroom = 1, kitchen, bathroom, child_room, living_room, garage, barn, bath };
struct Room
{
	double square;
	int typeOfRoom;
};

struct Floor
{
	double height;
	vector<Room> rooms;
};

struct House
{
	double square;
	bool fireplace;
	vector<Floor> floors;
};

struct Building
{
	int typeOfBuilding;
	double square;
	double height;
	bool fireplace;
};

struct District
{
	int number;
	House house;
	vector<Building> buildings;
};

int GetNumberOfBuildings(vector<District> &village)
{
	int n = 0;
	for (int i = 0; i < village.size(); i++)
	{
		District d = village[i];
		n += d.buildings.size();
		n++;
	}
	return n;
}

int GetNumberOfBuildings(vector<District> &village, int type)
{
	int n = 0;
	for (int i = 0; i < village.size(); i++)
	{
		District d = village[i];
		for (int j = 0; j < d.buildings.size(); j++)
		{
			Building b = d.buildings[j];
			if (b.typeOfBuilding == type)
				n++;
		}
	}
	return n;
}

int main()
{
	int n;
	vector<District> village;
	cout << "Please, enter all data about VILLAGE!" << endl;
	while (true)
	{
		cout << "\tInput number of DISTRICT (> 0): ";
		cin >> n;
		if (n < 1) cout << "\tThere must be at least 1 district!" << endl;
		else break;
	}
	for (int i = 0; i < n; i++)
	{
		District district;
		cout << "\n\tWhat number will " << i + 1 << " district have? ";
		cin >> district.number;
		district.number = abs(district.number);

		int countOfBuildings;
		while (true)
		{
			cout << "Ok!\tInput number of BUILDINGS on this district (> 0): ";
			cin >> countOfBuildings;
			if (countOfBuildings < 1)
				cout << "\tThere must be at least 1 buildings!" << endl;
			else break;
		}

		cout << "Input information about HOUSE on the district under the number " << district.number << endl;
		House house;

		cout << "\tInput square of house: ";
		cin >> house.square;
		house.square = abs(house.square);

		char flFP;
		cout << "\tIs there fireplace in this house (y/n)? ";
		cin >> flFP;
		if (flFP == 'y') house.fireplace = true;
		else house.fireplace = false;

		int countOfFloors;
		while (true)
		{
			cout << "\tHow many FLOORS will be in this house? ";
			cin >> countOfFloors;
			if (countOfFloors < 1 || countOfFloors > 3) cout << "Number of floors should be from 1 to 3!" << endl;
			else break;
		}

		for (int j = 0; j < countOfFloors; j++)
		{
			int floorSquare = house.square;
			Floor floor;
			cout << "\tInput height of " << j + 1 << "floor: ";
			cin >> floor.height;

			int countOfRooms;
			while (true)
			{
				cout << "Ok!\tHow many ROOMS will be on the floor " << j + 1 << " in this house? ";
				cin >> countOfRooms;
				if (countOfRooms < 2 || countOfRooms > 4)
					cout << "Number of rooms should be from 2 to 4!" << endl;
				else break;
			}
			for (int k = 0; k < countOfRooms; k++)
			{
				Room room;
				while (true)
				{
					cout << "\tOk!\tChoose type of room: \n\t\t1. Badroom;\n\t\t2. Kitchen;\n\t\t3. Bathroom;\n\t\t4. Child_room';\n\t\t5. Living_room." << endl;
					cout << "Your choice (number): ";
					cin >> room.typeOfRoom;
					if (room.typeOfRoom < 1 || room.typeOfRoom > 5)
						cout << "\t\tInvalid choice! Try again!" << endl;
					else break;
				}

				while (true)
				{
					cout << "\t\tInput square of room: ";
					cin >> room.square;
					room.square = abs(room.square);
					if (floorSquare - room.square < 0)
						cout << "\t\tSquare of floor should be more then square of rooms!" << endl;
					else
					{
						floorSquare -= room.square;
						break;
					}
				}
			}
		}
		district.house = house;
		countOfBuildings--;

		cout << "Input information about other buildings on the district under the number " << district.number << endl;
		for (int i = 0; i < countOfBuildings; i++)
		{
			Building building;
			while (true)
			{
				cout << "\tChoose type of building: \n\t6. Garage;\n\t7. Barn;\n\t8. Bath." << endl;
				cout << "Your choice (number): ";
				cin >> building.typeOfBuilding;
				if (building.typeOfBuilding < 6 || building.typeOfBuilding > 8)
					cout << "\tInvalid choice! Try again!" << endl;
				else break;
			}

			cout << "\tInput square of the building: ";
			cin >> building.square;

			cout << "\tInput height of the building: ";
			cin >> building.height;

			if (building.typeOfBuilding == 8)
			{
				char flFP;
				cout << "\tIs there fireplace in bath (y/n)? ";
				cin >> flFP;
				if (flFP == 'y') house.fireplace = true;
				else house.fireplace = false;
			}
			district.buildings.push_back(building);
		}
		village.push_back(district);
	}

	cout << "\nIn new village " << village.size() << " districts, "
		<< GetNumberOfBuildings(village) << " buildings, "
		<< GetNumberOfBuildings(village, garage) << " garages, "
		<< GetNumberOfBuildings(village, barn) << " barns, "
		<< GetNumberOfBuildings(village, bath) << " baths.";
	//
	return 0;
}