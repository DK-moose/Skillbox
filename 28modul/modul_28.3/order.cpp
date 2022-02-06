#include "order.h"

Order::Order(string nameOfDish, int orderStatus)
{
	this->nameOfDish = nameOfDish;
	this->orderStatus = orderStatus;
}

string Order::GetNameOfDish()
{
	return nameOfDish;
}

int Order::GetOrderStatus()
{
	return orderStatus;
}

void Order::SetOrderStatuts(int orderStatus)
{
	this->orderStatus = orderStatus;
}

void Order::GetOrderStatusMessage()
{
	if (orderStatus == 1)
	{
		cout << "The order \"" << nameOfDish << "\" is accepted!" << endl;
	}
	else if (orderStatus == 2)
	{
		cout << "The order \"" << nameOfDish << "\" is being prepared!" << endl;
	}
	else if (orderStatus == 3)
	{
		cout << "The order \"" << nameOfDish << "\" is ready!" << endl;
	}
	else if (orderStatus == 4)
	{
		cout << "The order \"" << nameOfDish << "\" is delivered!" << endl;
	}
	else cout << "Error: invalid order status code!" << endl;
}