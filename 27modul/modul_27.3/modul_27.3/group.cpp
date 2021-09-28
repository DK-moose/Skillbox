#include "group.h"

Group::Group(int numberOfWorkers)
{
	this->numberOfWorkers = numberOfWorkers;
	workers.resize(numberOfWorkers);
}

int Group::GetNumberOfWorkers()
{
	return numberOfWorkers;
}

void Group::SetNumberOfWorkers(int numberOfWorkers)
{
	this->numberOfWorkers = numberOfWorkers;
}

vector<Worker*>* Group::GetWorkers()
{
	return &workers;
}

void Group::SetWorkers(vector<Worker*> &workers)
{
	this->workers = workers;
}

Worker* Group::GetWorker(int index)
{
	return workers[index];
}

void Group::SetWorker(Worker *worker, int index)
{
	workers[index] = worker;
}

void Group::InitWorkers()
{
	for (int i = 0; i < numberOfWorkers; i++)
		workers[i] = new Worker();
}

int Group::GetBusyWorkers()
{
	int index = 0;
	while (index < workers.size() && workers[index]->GetWorkerFlag())
		index++;
	return index;
}

void Group::PrintInformation()
{
	cout << "Number of workers - " << numberOfWorkers << endl;
	for (int i = 0; i < numberOfWorkers; i++)
	{
		cout << i + 1 << " worker: ";
		if (this->GetWorker(i)->GetWorkerFlag()) cout << "busy, ";
		else cout << "free, ";
		cout << "type of task - " << this->GetWorker(i)->GetTypeTask() << endl;
	}
	cout << endl;
}