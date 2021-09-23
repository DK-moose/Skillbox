#include "group.h"

using namespace std;
int main()
{
	int numberOfGroups, numberOfWorkersInGroup, command, numberOfTasks;
	Director *director = new Director();
	vector<Group*> groups;
	cout << "Input number of groups: ";
	cin >> numberOfGroups;
	for (int i = 0; i < numberOfGroups; i++)
	{
		cout << "Input number of workers in group " << i + 1 << ": ";
		cin >> numberOfWorkersInGroup;
		Group *group = new Group(numberOfWorkersInGroup);
		group->SetManager(new Manager(i + 1, director));
		group->InitWorkers();		
		groups.push_back(group);
		delete group;
	}

	int full = 0;
	while (true)
	{
		cout << "Input the director's command (integer): ";
		cin >> command;
		for (int i = 0; i < numberOfGroups; i++)
		{
			groups[i]->GetManager()->GetDirector()->SetIdCommand(command); //error
			groups[i]->GetManager()->GetCoreForSrand();
			numberOfTasks = rand() % groups[i]->GetNumberOfWorkers() + 1;
			int start = groups[i]->GetBusyWorkers();
			if (start != groups[i]->GetNumberOfWorkers())
			{
				for (int j = start; j < groups[i]->GetNumberOfWorkers() || numberOfTasks > 0; j++)
				{
					groups[i]->GetWorker(j)->SetWorkerFlag(true);
					groups[i]->GetWorker(j)->SetTypeTask();
					numberOfTasks--;
				}
			}
			else full++;
		}
		if (full == numberOfGroups) break;
	}
	cout << "All workers got a job!" << endl;
	for (int i = 0; i < numberOfGroups; i++)
		groups[i]->PrintInformation();
	delete director;
	return 0;
}
