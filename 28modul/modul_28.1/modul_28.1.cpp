#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "swimmer.h"

using namespace std;

vector<Swimmer*> swimmers(6);
mutex m;

void wait_one_seconds(int index)
{
	this_thread::sleep_for(chrono::seconds(1));
	m.lock();
	if (swimmers[index]->GetDistance() > 100)
		swimmers[index]->SetDistance(100);
	else 
		swimmers[index]->SetDistance(swimmers[index]->GetDistance() + swimmers[index]->GetSpeed());
	swimmers[index]->PrintInfo();
	m.unlock();
}

void SortByFinishTime(vector<Swimmer*> &swimmers)
{
	for (int i = 0; i < swimmers.size() - 1; i++)
	{
		int key = i + 1;
		Swimmer tmp = *swimmers[key];
		for (int j = i + 1; j > 0; j--)
		{
			if (tmp.GetFinishTime() < swimmers[j - 1]->GetFinishTime())
			{
				*swimmers[j] = *swimmers[j - 1];
				key = j - 1;
			}
		}
		*swimmers[key] = tmp;
	}
}

int main()
{
	for (int i = 0; i < swimmers.size(); i++)
	{
		string name;
		cout << "Input name of swimmer " << i + 1 << ": ";
		cin >> name;
		double speed;
		cout << "Input speed of swimmer " << i + 1 << ": ";
		cin >> speed;
		swimmers[i] = new Swimmer(name, speed);
	}

	bool notAllFinished = true;
	cout << "\nStart!" << endl;
	while (notAllFinished)
	{
		cout << endl;
		thread s1(wait_one_seconds, 0);
		thread s2(wait_one_seconds, 1);
		thread s3(wait_one_seconds, 2);
		thread s4(wait_one_seconds, 3);
		thread s5(wait_one_seconds, 4);
		thread s6(wait_one_seconds, 5);

		s1.join();
		s2.join();
		s3.join();
		s4.join();
		s5.join();
		s6.join();

		for (int i = 0; i < swimmers.size(); i++)
		{
			if (swimmers[i]->GetDistance() < 100)
				break;
			notAllFinished = false;
		}
	}

	SortByFinishTime(swimmers);

	cout << endl;
	for (int i = 0; i < swimmers.size(); i++)
	{
		cout << i + 1 << "|\t";
		swimmers[i]->PrintResult();
	}
	return 0;
}
