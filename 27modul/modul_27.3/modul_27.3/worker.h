#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
class Worker
{
private:
	bool freedom_flag;
	char typeTask;

public:
	Worker();
	Worker(bool freedom_flag);
	bool GetWorkerFlag();
	void SetWorkerFlag(bool freedom_flag);
	char GetTypeTask();
	void SetTypeTask();
};