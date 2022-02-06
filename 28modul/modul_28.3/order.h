#pragma once

#include <iostream>
#include <string>

#define ACCEPTED 1
#define COOKING 2
#define READY 3
#define DELIVERED 4

using namespace std;
class Order
{
private:
	string nameOfDish;
	int orderStatus;

public:
	Order(string nameOfDish, int orderStatus);
	string GetNameOfDish();
	int GetOrderStatus();
	void SetOrderStatuts(int orderStatus);
	void GetOrderStatusMessage();
};