#pragma once

#include <iostream>
#include <string>

using namespace std;
enum orderStatus {accepted = 1, cooking, ready, delivered};
class Order
{
private:
	int orderNumber;
	string nameOfDish;
	int _orderStatus;

public:
	Order(int orderNumber, string nameOfDish, int _orderStatus);
	string GetNameOfDish();
	int GetOrderStatus();
	void SetOrderStatus(int _orderStatus);
	void GetOrderStatusMessage();
};