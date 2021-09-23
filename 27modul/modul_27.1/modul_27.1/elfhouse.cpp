#include "elfhouse.h"

ElfHouse::ElfHouse()
{
    elfName = "";
    houseEmployed = false;
}

ElfHouse::ElfHouse(string elfName)
{
    this->elfName = elfName;
    SetConditionOfElfHouse(elfName);
}

void ElfHouse::SetConditionOfElfHouse(string name)
{
    if (name == "") houseEmployed = false;
    else houseEmployed = true;
}

string ElfHouse::GetElfName()
{
    return elfName;
}

bool ElfHouse::GetConditionOfElfHouse()
{
    return houseEmployed;
}
