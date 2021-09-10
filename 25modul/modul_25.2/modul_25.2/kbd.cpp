#include "kbd.h"

void Input(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "\t" << i + 1 << " -> ";
        cin >> vec[i];
    }
}
