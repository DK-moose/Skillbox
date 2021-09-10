#include "ram.h"

void Write()
{
    cout << "Input values to buffer: " << endl;
    Input(buffer);
    start = true;
}

vector<int>* Read()
{
    return &buffer;
}
