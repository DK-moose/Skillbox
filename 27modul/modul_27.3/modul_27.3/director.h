#pragma once
#include <iostream>
#include <vector>
#include "manager.h"

using namespace std;

class Director
{
private:
	int id_command;
	vector<Manager*> managers;

public:
	Director();
	int GetIdCommand();
	void SetIdCommand(int id_command);
	Manager* GetManager(int index);
	void SetManagers(vector<Manager*> &managers);
};