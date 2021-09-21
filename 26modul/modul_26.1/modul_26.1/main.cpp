#include "track.h"
#include "player.h"

using namespace std;

int main()
{
	time_t t = time(nullptr);
	srand(time(nullptr));
	tm* t_obj = localtime(&t);

	Player* player = new Player();
	t_obj->tm_year = 2014;
	t_obj->tm_mon = 5;
	t_obj->tm_mday = 21;
	player->AddRecord(new Track("Baby", t_obj, 124));
	t_obj->tm_year = 2010;
	t_obj->tm_mon = 7;
	t_obj->tm_mday = 12;
	player->AddRecord(new Track("Kosandra", t_obj, 345));
	t_obj->tm_year = 2016;
	t_obj->tm_mon = 8;
	t_obj->tm_mday = 1;
	player->AddRecord(new Track("Rain", t_obj, 232));

	string command;
	string playedTrack = "";

	while (true)
	{
		cout << "Please, input command (play, pause, next, stop) or 'exit': ";
		cin >> command;
		if (command == "play" && playedTrack == "")
		{
			cout << "Please, input name of track: ";
			cin >> playedTrack;
			playedTrack = player->Play(playedTrack);
			if (player->player_c == stop)
			{
				cout << "There is no such track!" << endl;
				playedTrack = "";
			}
		}
		else if (command == "play" && player->player_c == pause)
		{
			playedTrack = player->Play(playedTrack);
		}
		else if (command == "pause")
		{
			player->Pause();
		}
		else if (command == "next")
		{
			playedTrack = player->Next();
		}
		else if (command == "stop")
		{
			player->Stop();
			playedTrack = "";
		}
		else if (command == "exit")
		{
			break;
		}
		else cout << "Invalid command! Try again." << endl;
	}

	player->RemoveRecords();
	delete player;
	return 0;
}
