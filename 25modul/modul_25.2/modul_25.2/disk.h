#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "ram.h"

#define PATH "data.bin"

using namespace std;

void Save(vector<int> &vec);
void Load(vector<int> &vec);
