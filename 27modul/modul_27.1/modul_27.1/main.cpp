#include <iostream>
#include "branch.h"

using namespace std;

int main()
{
    Branch *tree = new Branch();
    cout << "Populate the tree!" << endl;
    tree->InitBranch(0);
    string name;
    cout << "Input name for search: ";
    cin >> name;
    for (int i = 0; i < tree->GetBranchSize(); i++)
    {
        Branch *branch = tree->GetBranch(i);
        if (branch->ElfOnThisBranch(name, 0))
        {
            cout << "On branch " << i + 1 << ", " << name << " has " << branch->GetNumberNeighborsOfElf(0, 0) << " neighbors." << endl;
        }
    }
    delete tree;
    return 0;
}

