#include <iostream>
#include "point.h"
#include "instruments.h"

using namespace std;
int main()
{
    Point a, b, c;
    string command = "";
    cout << "Let's start the operation: " << endl;

    InitPoint(a, "first");
    InitPoint(b, "second");
    Scalpel(a, b);

    while (command != "suture")
    {
        cout << "Please, input next command (hemostat, tweezers or suture): ";
        cin >> command;
        if (command == "hemostat")
        {
            InitPoint(c);
            Hemostat(c);
        }
        else if (command == "tweezers")
        {
            InitPoint(c);
            Tweezers(c);
        }
        else if (command == "suture")
        {
            while (true)
            {
                InitPoint(c, "first");
                if (c.x != a.x || c.y != a.y)
                    cout << "The points should be the same as when cutting! Try again." << endl;
                else break;
            }
            while (true)
            {
                InitPoint(c, "second");
                if (c.x != b.x ||c.y != b.y)
                    cout << "The points should be the same as when cutting! Try again." << endl;
                else break;
            }
            Suture(a, b);
        }
        else cout << "Invalid input! Try again." << endl;
    }

    cout << "The operation was perfomed successfully!" << endl;
    return 0;
}

