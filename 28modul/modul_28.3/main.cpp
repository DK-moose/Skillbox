#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <thread>
#include <mutex>
#include "order.h"

using namespace std;

enum dishes {pizza = 1, soup, steak, salad, sushi};
vector<Order*> orders;
mutex _accepted;
bool kitchenIsFree = true;
mutex _cooking;
mutex _delivering;

string DishToString(int dishCode)
{
	if (dishCode == 1)
		return "Pizza";
	else if (dishCode == 2)
		return "Soup";
	else if (dishCode == 3)
		return "Steak";
	else if (dishCode == 4)
		return "Salad";
	else if (dishCode == 5)
		return "Sushi";
	else return "";
}

bool OneStatusForAllOrders(int status)
{
	int countOrders = 0;
	for (int i = 0; i < orders.size(); i++)
	{
		if (orders[i]->GetOrderStatus() != status)
			return false;
		else countOrders++;
	}
	if (countOrders < 10)
		return false;
	return true;
}

int SearchAcceptedOrder()
{
	for (int i = 0; i < orders.size(); i++)
		if (orders[i]->GetOrderStatus() == accepted)
			return i;
	return -1;
}

void wait_for_order()
{
	srand(time(nullptr));
	int _orderNumber = 0;
	while (_orderNumber < 10)
	{
		this_thread::sleep_for(chrono::seconds(rand() % 5 + 6));
		int dish = rand() % 5 + 1;
		_accepted.lock();
		orders.push_back(new Order(_orderNumber + 1, DishToString(dish), accepted));
		orders[_orderNumber]->GetOrderStatusMessage();
		_accepted.unlock();
		_orderNumber++;
	} 
}

void wait_for_cooking()
{
	int countReadyOrders = 0;
	int indexAcceptedOrder = 0;
	while(countReadyOrders < 10)
	{		
		_cooking.lock();
		orders[indexAcceptedOrder]->SetOrderStatus(cooking);
		orders[indexAcceptedOrder]->GetOrderStatusMessage();
		_cooking.unlock();
		this_thread::sleep_for(chrono::seconds(rand() % 10 + 6));
		_cooking.lock();
		orders[indexAcceptedOrder]->SetOrderStatus(ready);
		orders[indexAcceptedOrder]->GetOrderStatusMessage();
		countReadyOrders++;		
		_cooking.unlock();
		while(SearchAcceptedOrder() == -1)
			continue;
		_cooking.lock();
		indexAcceptedOrder = SearchAcceptedOrder();
		_cooking.unlock();
	}
}

int main()
{
	thread order_t(wait_for_order); 
	while (orders.size() < 1)
		continue;
	thread cooking_t(wait_for_cooking);
	while (!OneStatusForAllOrders(delivered))
	{
		this_thread::sleep_for(chrono::seconds(30));
		_delivering.lock();
		for (int i = 0; i < orders.size(); i++)
		{
			if (orders[i]->GetOrderStatus() == ready)
			{
				orders[i]->SetOrderStatus(delivered);
				orders[i]->GetOrderStatusMessage();
			}
		}
		_delivering.unlock();
	}
	order_t.join();
	cooking_t.detach();
	return 0;
}
