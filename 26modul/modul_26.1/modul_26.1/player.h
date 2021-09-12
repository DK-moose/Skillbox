#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "track.h"
#define PLAY 1
#define PAUSE 2
#define STOP 0

using namespace std;
class Player
{
private:
	vector<Track> records;

public:
	int playerCondition;
	vector<Track>* GetRecords();
	void SetRecords(vector<Track> &records);
	string Play(string str);
	void Pause();
	string Next();
	void Stop();
};