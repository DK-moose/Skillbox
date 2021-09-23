#include "worker.h"

Worker::Worker()
{
	freedom_flag = false;
	typeTask = ' ';
}

Worker::Worker(bool freedom_flag)
{
	this->freedom_flag = freedom_flag;
	if (freedom_flag) SetTypeTask();
	else typeTask = ' ';
}

bool Worker::GetWorkerFlag()
{
	return freedom_flag;
}

void Worker::SetWorkerFlag(bool freedom_flag)
{
	this->freedom_flag = freedom_flag;
}

char Worker::GetTypeTask()
{
	return typeTask;
}

void Worker::SetTypeTask()
{
	srand(time(nullptr));
	int tt = rand() % 3;
	if (tt == 0) typeTask = 'A';
	else if (tt == 1) typeTask = 'B';
	else typeTask = 'C';
}