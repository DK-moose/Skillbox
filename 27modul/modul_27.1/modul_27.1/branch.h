#pragma once

#include "elfhouse.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#define MAX_DEPTH 2

using namespace std;
class Branch
{
private:
    ElfHouse *elf;
    vector<Branch*> branches;

public:
    bool IsName(string name);
    string InputNewName();
    int GetBranchSize();
    vector<Branch*>* GetBranches();
    Branch* GetBranch(int index);
    void InitBranch(int depth);
    bool ElfOnThisBranch(string name, int depth);
    int GetNumberNeighborsOfElf(int count, int depth);
};
