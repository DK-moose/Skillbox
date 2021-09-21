#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "track.h"
enum player_condition{ stop = 0, play, pause};

using namespace std;
class Player
{
private:
	vector<Track*> records;

public:
	int player_c;
	void AddRecord(Track *records);
	void RemoveRecords();
	string Play(string str);
	void Pause();
	string Next();
	void Stop();
};