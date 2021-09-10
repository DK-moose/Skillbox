#pragma once
#include <iostream>
#include <vector>
#include "kbd.h"

#define BUFFER_SIZE 8

using namespace std;

_declspec(selectany) vector<int> buffer(BUFFER_SIZE);
_declspec(selectany) bool start = false;

void Write();
vector<int>* Read();
