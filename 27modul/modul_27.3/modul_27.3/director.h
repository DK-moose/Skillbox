#pragma once
#include <iostream>

using namespace std;

class Director
{
private:
	int id_command;
	
public:
	Director();
	int GetIdCommand();
	void SetIdCommand(int id_command);
};