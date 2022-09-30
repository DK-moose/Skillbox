#include <iostream>
#include <string>
#include <map>

using namespace std;

void PrintDB(map<string, int>* shop)
{
	int i = 1;
	for (map<string, int>::iterator it = shop->begin(); it != shop->end(); ++it)
	{
		cout << i << ": " << it->first << " (" << it->second << ")" << endl;
		i++;
	}
}

bool CheckCount(int val, string errorMessage)
{
	if (val < 0)
	{
		throw invalid_argument(errorMessage);
	}
	return true;
}

bool CheckArticleNumber(string articleNumber)
{
	for (int i = 0; i < articleNumber.size(); i++)
	{
		if ((articleNumber[i] < '0' || articleNumber[i] > '9') &&
			(articleNumber[i] < 'A' || articleNumber[i] > 'Z') &&
			(articleNumber[i] < 'a' || articleNumber[i] > 'z') &&
			articleNumber[i] != '-')
		{
			throw invalid_argument("Invalid character in the article number (" + articleNumber + ")!");
			return false;
		}
	}
}

bool CheckArticleNumber(map<string, int>* shop, string articleNumber)
{
	for (int i = 0; i < articleNumber.size(); i++)
	{
		if ((articleNumber[i] < '0' || articleNumber[i] > '9') &&
			(articleNumber[i] < 'A' || articleNumber[i] > 'Z') &&
			(articleNumber[i] < 'a' || articleNumber[i] > 'z') &&
			articleNumber[i] != '-')
		{
			throw invalid_argument("Invalid character in the article number (" + articleNumber + ")!");
			return false;
		}
	}

	for (map<string, int>::iterator it = shop->begin(); it != shop->end(); ++it)
	{
		if (it->first == articleNumber)
		{
			throw runtime_error("This article number already exists!");
			return false;
		}
	}
	return true;
}

int SearchArticleNumber(map<string, int>* shop, string articleNumber)
{
	int i = 0;
	for (map<string, int>::iterator it = shop->begin(); it != shop->end(); ++it)
	{
		if (it->first == articleNumber)
			return i;
		i++;
	}
	return -1;
}

void Add(map<string, int>* shop, string articleNumber, int numberProduct)
{
	int index = SearchArticleNumber(shop, articleNumber);
	if (index == -1)
	{
		throw runtime_error("Not a definite the article number!");
	}
	
	map<string, int>::iterator it = shop->begin();
	advance(it, index);
	it->second += numberProduct;
}

void Remove(map<string, int>* shop, string articleNumber, int numberProduct)
{
	int index = SearchArticleNumber(shop, articleNumber);
	if (index == -1)
	{
		throw runtime_error("Not a definite the article number!");
	}

	map<string, int>::iterator it = shop->begin();
	advance(it, index);
	if (it->second - numberProduct < 0)
	{
		throw runtime_error("The quantity of the product can't be less than 0!");
	}
	it->second -= numberProduct;
}

int main()
{
	map<string, int> shop;
	int countItems;

	// Ввод количества товаров
	cout << "Fill in the shopping cart!" << endl;
	cout << "Input the number of items in the cart: ";
	try
	{
		cin >> countItems;
		CheckCount(countItems, "Number of items can't be less then 0!");
	}
	catch (invalid_argument err)
	{
		cout << "Invalid argument: " << err.what() << endl;
		return 0;
	}

	// Ввод артикулов и количества товара по артикулу
	for (int i = 0; i < countItems; i++)
	{
		string articleNumber;
		int numberProducts;
		cout << "Input the article number: ";
		try
		{
			cin >> articleNumber;
			CheckArticleNumber(&shop, articleNumber);
		}
		catch (invalid_argument err)
		{
			cout << "Invalid argument: " << err.what() << endl;
			i--;
			continue;
		}
		catch (runtime_error err)
		{
			cout << "Runtime error: " << err.what() << endl;
			i--;
			continue;
		}

		cout << "Input number of products: ";
		try
		{
			cin >> numberProducts;
			CheckCount(numberProducts, "Number of products can't be less then 0!");
		}
		catch(invalid_argument err)
		{
			cout << "Invalid argument: " << err.what() << endl;
			i--;
			continue;
		}

		shop.insert(make_pair(articleNumber, numberProducts));
	}

	// Добавить, удалить, выйти
	int command = 0;
	while (command != 3)
	{
		PrintDB(&shop);
		cout << endl;
		cout << "1: Add\n2: Remove\nOther: Exit\n";
		cin >> command;
		string articleNumber;
		int numberProducts;
		if (command == 1 || command == 2)
		{
			cout << "Input the article number: ";
			try
			{
				cin >> articleNumber;
				CheckArticleNumber(articleNumber);
			}
			catch (invalid_argument err)
			{
				cout << "Invalid argument: " << err.what() << endl;
				continue;
			}
			
			cout << "Input number of products: ";
			try
			{
				cin >> numberProducts;
				CheckCount(numberProducts, "Number of products can't be less then 0!");
			}
			catch (invalid_argument err)
			{
				cout << "Invalid argument: " << err.what() << endl;
				continue;
			}

			if (command == 1)
			{
				try
				{
					Add(&shop, articleNumber, numberProducts);
				}
				catch (runtime_error err)
				{
					cout << "Runtime error: " << err.what() << endl;
					continue;
				}
			}
			else
			{
				try
				{
					Remove(&shop, articleNumber, numberProducts);
				}
				catch (runtime_error err)
				{
					cout << "Runtime error: " << err.what() << endl;
					continue;
				}
			}
		}
		else break;
	}
	return 0;
}
