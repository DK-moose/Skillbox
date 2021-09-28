#pragma once
#include "worker.h"
#include <vector>

class Group
{
private:
	int numberOfWorkers;
	vector<Worker*> workers;

public:
	Group(int numberOfWorkers);
	int GetNumberOfWorkers();
	void SetNumberOfWorkers(int numberOfWorkers);
	vector<Worker*>* GetWorkers();
	void SetWorkers(vector<Worker*> &workers);
	Worker* GetWorker(int index);
	void SetWorker(Worker *worker, int index);
	void InitWorkers();
	int GetBusyWorkers();
	void PrintInformation();
};