#include "director.h"

using namespace std;
int main()
{
	int numberOfGroups, numberOfWorkersInGroup, command, numberOfTasks;
	Director *director = new Director();
	cout << "Input number of groups: ";
	cin >> numberOfGroups;
	vector<Manager*> managers;
	for (int i = 0; i < numberOfGroups; i++)
	{
		cout << "Input number of workers in group " << i + 1 << ": ";
		cin >> numberOfWorkersInGroup;
		Group *group = new Group(numberOfWorkersInGroup);
		group->InitWorkers();
		managers.push_back(new Manager(i + 1, group));			
	}
	director->SetManagers(managers);

	int full;
	while (true)
	{
		full = 0;
		cout << "Input the director's command (integer): ";
		cin >> command;
		director->SetIdCommand(command);
		for (int i = 0; i < numberOfGroups; i++)
		{
			srand(command + director->GetManager(i)->GetSerialNumber());
			Group *group = director->GetManager(i)->GetGroup();
			numberOfTasks = rand() % group->GetNumberOfWorkers() + 1;
			int start = group->GetBusyWorkers();
			if (start != group->GetNumberOfWorkers())
			{
				for (int j = start; j < group->GetNumberOfWorkers() && numberOfTasks > 0; j++)
				{
					group->GetWorker(j)->SetWorkerFlag(true);
					group->GetWorker(j)->SetTypeTask();
					numberOfTasks--;
				}
			}
			if (group->GetBusyWorkers() == group->GetNumberOfWorkers())
				full++;
		}
		for (int i = 0; i < numberOfGroups; i++)
		{
			cout << "Director command - " << director->GetIdCommand() << endl;
			cout << "Manager serial number - " << director->GetManager(i)->GetSerialNumber() << endl;
			director->GetManager(i)->GetGroup()->PrintInformation();
		}
		if (full == numberOfGroups) break;
	}
	cout << "All workers got a job!" << endl;
	for (int i = 0; i < numberOfGroups; i++)
	{
		delete director->GetManager(i)->GetGroup();
		delete director->GetManager(i);
	}
	delete director;
	return 0;
}
