#pragma once
#include <iostream>
#include <string>

using namespace std;
class ElfHouse
{
private:
    string elfName;
    bool houseEmployed;

public:
    ElfHouse();
    ElfHouse(string elfName);
    void SetConditionOfElfHouse(string name);
    string GetElfName();
    bool GetConditionOfElfHouse();
};
