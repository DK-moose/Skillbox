#include "player.h"

void Player::AddRecord(Track *record)
{
	this->records.push_back(record);
}

string Player::Play(string str)
{
	for (int i = 0; i < records.size(); i++)
	{
		if (records[i]->GetName() == str)
		{
			cout << "PLAY" << endl;
			cout << "Name: \"" << records[i]->GetName() << "\"" << endl;
			cout << "Date of create: " << put_time(records[i]->GetDateOfCreate(), "%y/%m/%d") << endl;
			cout << "Duration: " << records[i]->GetDuration() << endl;
			player_c = play;
			return str;
		}
	}
	return "";
}

void Player::RemoveRecords()
{
	for (int i = 0; i < records.size(); i++)
		delete records[i];
}

void Player::Pause()
{
	if (player_c == play)
	{
		cout << "PAUSE" << endl;
		player_c = pause;
	}
}

string Player::Next()
{
	if ((player_c == play) || (player_c == pause))
		return Play(records[rand() % records.size()]->GetName());
	return "";
}

void Player::Stop()
{
	if ((player_c == play) || (player_c == pause))
	{
		cout << "STOP" << endl;
		player_c = stop;
	}
}