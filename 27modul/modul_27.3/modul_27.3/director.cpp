#include "director.h"

Director::Director()
{
	id_command = 0;
}

int Director::GetIdCommand()
{
	return id_command;
}

void Director::SetIdCommand(int id_command)
{
	this->id_command = id_command;
}