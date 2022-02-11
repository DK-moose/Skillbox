#include "order.h"

Order::Order(int orderNumber, string nameOfDish, int _orderStatus)
{
	this->orderNumber = orderNumber;
	this->nameOfDish = nameOfDish;
	this->_orderStatus = _orderStatus;
}

string Order::GetNameOfDish()
{
	return nameOfDish;
}

int Order::GetOrderStatus()
{
	return _orderStatus;
}

void Order::SetOrderStatus(int _orderStatus)
{
	this->_orderStatus = _orderStatus;
}

void Order::GetOrderStatusMessage()
{
	if (_orderStatus == 1)
	{
		cout << "The order N"<< orderNumber << " \"" << nameOfDish << "\" is accepted!" << endl;
	}
	else if (_orderStatus == 2)
	{
		cout << "The order N" << orderNumber << " \"" << nameOfDish << "\" is being prepared!" << endl;
	}
	else if (_orderStatus == 3)
	{
		cout << "The order N" << orderNumber << " \"" << nameOfDish << "\" is ready!" << endl;
	}
	else if (_orderStatus == 4)
	{
		cout << "The order N" << orderNumber << " \"" << nameOfDish << "\" is delivered!" << endl;
	}
	else cout << "Error: invalid order status code!" << endl;
}