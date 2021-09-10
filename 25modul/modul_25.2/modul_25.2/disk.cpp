#include "disk.h"

void Save(vector<int> &vec)
{
    ofstream file(PATH, ios::binary);
    if (file.is_open())
    {
        for (int i = 0; i < vec.size(); i++)
            file.write((char*)&vec[i], sizeof(vec[i]));
        file.close();
    }
}

void Load(vector<int> &vec)
{
    ifstream file(PATH, ios::binary);
    if (file.is_open())
    {
        if (!start) start = true;
        for (int i = 0; i < vec.size(); i++)
            file.read((char*)&vec[i], sizeof(vec[i]));
        file.close();
    }
}
