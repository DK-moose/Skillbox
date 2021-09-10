#include "cpu.h"

void Compute(vector<int> &vec)
{
    int result = 0;
    for(int i = 0; i < vec.size(); i++)
        result += vec[i];
    cout << result << endl;
}
