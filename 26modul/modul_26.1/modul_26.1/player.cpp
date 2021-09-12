#include "player.h"

vector<Track>* Player::GetRecords()
{
	return &records;
}

void Player::SetRecords(vector<Track> &records)
{
	this->records = records;
}

string Player::Play(string str)
{
	for (int i = 0; i < records.size(); i++)
	{
		if (records[i].GetName() == str)
		{
			cout << "PLAY" << endl;
			cout << "Name: \"" << records[i].GetName() << "\"" << endl;
			cout << "Date of create: " << put_time(records[i].GetDateOfCreate(), "%y/%m/%d") << endl;
			cout << "Duration: " << records[i].GetDuration() << endl;
			playerCondition = PLAY;
			return str;
		}
	}
	return "";
}

void Player::Pause()
{
	if (playerCondition & PLAY)
	{
		cout << "PAUSE" << endl;
		playerCondition = PAUSE;
	}
}

string Player::Next()
{
	if ((playerCondition & PLAY) || (playerCondition & PAUSE))
		return Play(records[rand() % records.size()].GetName());
	return "";
}

void Player::Stop()
{
	if ((playerCondition & PLAY) || (playerCondition & PAUSE))
	{
		cout << "STOP" << endl;
		playerCondition = STOP;
	}
}