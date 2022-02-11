#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "swimmer.h"

using namespace std;

vector<Swimmer*> swimmers(6);
vector<Swimmer*> swimmersResults;
mutex historySwimming;

void wait_finish(int index)
{
	while (swimmers[index]->GetDistance() < 100)
	{
		this_thread::sleep_for(chrono::seconds(1));
		historySwimming.lock();
		swimmers[index]->SetDistance(swimmers[index]->GetDistance() + swimmers[index]->GetSpeed());
		swimmers[index]->PrintInfo();
		historySwimming.unlock();
	}
	swimmers[index]->SetDistance(100);
	swimmersResults.push_back(swimmers[index]);
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
	
	thread s1(wait_finish, 0);
	thread s2(wait_finish, 1);
	thread s3(wait_finish, 2);
	thread s4(wait_finish, 3);
	thread s5(wait_finish, 4);
	thread s6(wait_finish, 5);
	
	s1.join();
	s2.join();
	s3.join();
	s4.join();
	s5.join();
	s6.join();

	for (int i = 0; i < swimmersResults.size(); i++)
	{
		cout << i + 1 << "|\t";
		swimmersResults[i]->PrintResult();
	}
	return 0;
}
