#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#define WIDTH 3
#define HEIGHT 3

using namespace std;

class Fish
{
private:
	string name = "FISH";

public:
	string ResultMessage()
	{
		return "You caught a " + name + "! You won!";
	};
};

class Boot
{
private:
	string name = "BOOT";

public:
	string ResultMessage()
	{
		return "You caught a " + name + "! You lose!";
	};
};

class Sector
{
private:
	Fish* fish;
	Boot* boot;

public:
	bool IsEmpty()
	{
		if (fish == nullptr && boot == nullptr)
			return true;
		return false;
	};

	void SetFish(Fish* fish)
	{
		this->fish = fish;
	};

	bool SetBoot(Boot* boot)
	{
		if (this->IsEmpty())
		{
			this->boot = boot;
			return true;
		}
		return false;
	};

	Fish* GetFish()
	{
		return this->fish;
	};

	Boot* GetBoot()
	{
		return this->boot;
	};
};

bool CheckIndex(int index)
{
	if (index < 0 || index > 9)
	{
		throw invalid_argument("The sector number must be from 0 to 8!");
		return false;
	}
	return true;
}

template<typename T>
bool CheckSector(T* obj)
{
	if (obj != nullptr)
	{
		throw runtime_error(obj->ResultMessage());
		return true;
	}
	return false;
};

int main()
{
	srand(time(nullptr));
	vector<Sector*> field;
	for (int i = 0; i < WIDTH * HEIGHT; i++)
		field.push_back(new Sector());

	field[rand() % 9]->SetFish(new Fish());
	int countBoots = 3;
	while (countBoots)
	{
		if (field[rand() % 9]->SetBoot(new Boot()))
			countBoots--;
	}

	int index;
	while (true)
	{
		while (true)
		{
			try
			{
				cout << "Input number of sector: ";
				cin >> index;
				if (CheckIndex(index))
					break;
			}
			catch (invalid_argument err)
			{
				cout << "Invalid argument: " << err.what() << endl;
				cout << "Try again!";
			}
		}

		try
		{
			if (!(CheckSector(field[index]->GetFish()) ||
				CheckSector(field[index]->GetBoot())))
			{
				cout << "Try again!" << endl;
				continue;
			}
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl;
			return 0;
		}
	}
	return 0;
}
