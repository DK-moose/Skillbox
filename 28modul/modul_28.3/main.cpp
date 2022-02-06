#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "order.h"

using namespace std;

enum dishes {pizza = 1, soup, steak, salad, sushi};

vector<Order*> orders;
mutex accepted;
bool kitchenIsFree = true;
vector<Order*> readyOrders;
mutex cooking;
mutex delivering;

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

bool AllOrdersDelivered()
{
	int countOrders = 0;
	for (int i = 0; i < orders.size() && countOrders < 10; i++)
	{
		if (orders[i]->GetOrderStatus() != DELIVERED)
			return false;
		else countOrders++;
	}
	if (countOrders < 10)
		return false;
	return true;
}

void wait_for_order()
{
	srand(time(nullptr));
	this_thread::sleep_for(chrono::seconds(rand() % 5 + 6));
	int dish = rand() % 5 + 1;
	accepted.lock();
	orders.push_back(new Order(DishToString(dish), ACCEPTED));
	orders[orders.size() - 1]->GetOrderStatusMessage();
	accepted.unlock();
}

void wait_for_cooking()
{
	cooking.lock();
	int i = 0;
	while (orders[i]->GetOrderStatus() != ACCEPTED && i < orders.size())
	{
		i++;
	}
	orders[i]->SetOrderStatuts(COOKING);
	orders[i]->GetOrderStatusMessage();
	this_thread::sleep_for(chrono::seconds(rand() % 10 + 6));
	orders[i]->SetOrderStatuts(READY);
	orders[i]->GetOrderStatusMessage();
	cooking.unlock();
	kitchenIsFree = true;
}

void wait_for_delivery()
{
	this_thread::sleep_for(chrono::seconds(30));

	for (int i = 0; i < orders.size(); i++)
	{
		if (orders[i]->GetOrderStatus() == READY)
		{
			orders[i]->SetOrderStatuts(DELIVERED);
			orders[i]->GetOrderStatusMessage();
		}
	}
}

int main()
{
	while(true)
	{
		thread order_t(wait_for_order);
		order_t.join();
		if (kitchenIsFree)
		{
			kitchenIsFree = false;
			thread cooking_t(wait_for_cooking);
			cooking_t.detach();
		}
		thread delivery_t(wait_for_delivery);
		delivery_t.detach();
		if (AllOrdersDelivered())
			break;
	}
	return 0;
}
