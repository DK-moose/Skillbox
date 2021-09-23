#include "branch.h"

int Branch::GetBranchSize()
{
    return branches.size();
}

vector<Branch*>* Branch::GetBranches()
{
    return &branches;
}

bool Branch::IsName(string name)
{
    if (name[0] < 'A' || name[0] > 'Z')
        return false;
    for (int i = 1; i < name.size(); i++)
        if (name[i] < 'a' || name[i] > 'z')
            return false;
    return true;
}

string Branch::InputNewName()
{
    string name;
    cout << "Input the name of new elf: ";
    cin >> name;
    return name;
}

Branch* Branch::GetBranch(int index)
{
    return branches[index];
}

void Branch::InitBranch(int depth)
{
   if (depth == 0)
   {
       this->elf = new ElfHouse();
       this->branches.resize(rand() % 3 + 3);
       for (int i = 0; i < this->branches.size(); i++)
       {
           Branch *newBranch = new Branch();
           newBranch->InitBranch(depth + 1);
           this->branches[i] = newBranch;
           delete newBranch;
       }
       //return this;
   }
   else if (depth > 0 && depth < MAX_DEPTH)
   {
       this->elf = new ElfHouse(InputNewName());
       this->branches.resize(rand() % 2 + 2);
       for (int i = 0; i < this->branches.size(); i++)
       {
           Branch *newBranch = new Branch();
           newBranch->InitBranch(depth + 1);
           this->branches[i] = newBranch;
           delete newBranch;
       }
       //return this;
   }
   else
   {
       this->elf = new ElfHouse(InputNewName());
       this->branches.resize(0);
       //return this;
   }
}

bool Branch::ElfOnThisBranch(string name, int depth)
{
    if (this->elf->GetElfName() == name)
        return true;
    for (int i = 0; i < this->branches.size(); i++)
    {
        Branch *checkedBranch = this->branches[i];
        if (depth < MAX_DEPTH)
           return checkedBranch->ElfOnThisBranch(name, depth + 1);
    }
    return false;
}

int Branch::GetNumberNeighborsOfElf(int count, int depth)
{
    if (this->elf->GetElfName() != "")
        count++;
    for (int i = 0; i < this->branches.size(); i++)
    {
        Branch *checkedBranch = this->branches[i];
        if (depth < MAX_DEPTH)
           count = checkedBranch->GetNumberNeighborsOfElf(count, depth + 1);
    }
    return count;
}
