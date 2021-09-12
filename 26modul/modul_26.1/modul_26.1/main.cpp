#include "track.h"
#include "player.h"

using namespace std;

int main()
{
	time_t t = time(nullptr);
	srand(time(nullptr));
	tm* t_obj = localtime(&t);
	Track* track_1 = new Track();
	track_1->SetName("Baby");
	t_obj->tm_year = 2014;
	t_obj->tm_mon = 5;
	t_obj->tm_mday = 21;
	track_1->SetDateOfCreate(*t_obj);
	track_1->SetDuration(124);
	Track* track_2 = new Track();
	track_2->SetName("Rain");
	t_obj->tm_year = 2010;
	t_obj->tm_mon = 7;
	t_obj->tm_mday = 12;
	track_2->SetDateOfCreate(*t_obj);
	track_2->SetDuration(345);
	Track* track_3 = new Track();
	track_3->SetName("Kosandra");
	t_obj->tm_year = 2016;
	t_obj->tm_mon = 8;
	t_obj->tm_mday = 1;
	track_3->SetDateOfCreate(*t_obj);
	track_3->SetDuration(232);
	vector<Track> tracks;
	tracks.push_back(*track_1);
	tracks.push_back(*track_2);
	tracks.push_back(*track_3);

	Player* player = new Player();
	player->SetRecords(tracks);

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
			if (player->playerCondition == STOP)
			{
				cout << "There is no such track!" << endl;
				playedTrack = "";
			}
		}
		else if (command == "play" && player->playerCondition == PAUSE)
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

	delete track_1;
	delete track_2;
	delete track_3;
	delete player;
	return 0;
	return 0;
}
