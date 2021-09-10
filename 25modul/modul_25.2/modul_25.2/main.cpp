#include <iostream>
#include <string>
#include "cpu.h"
#include "kbd.h"
#include "ram.h"
#include "disk.h"
#include "gpu.h"

#define SUM "sum"
#define SAVE "save"
#define LOAD "load"
#define INPUT "input"
#define DISPLAY "display"
#define EXIT "exit"

using namespace std;

int main()
{
    string command = "";
    while (true)
    {
		cout << "Input command (input, sum, save, load, display, exit): ";
        cin >> command;
        if (command == SUM && start)
            Compute(buffer);
        else if (command == SAVE && start)
            Save(buffer);
        else if (command == LOAD)
            Load(buffer);
        else if (command == INPUT)
            Write();
        else if (command == DISPLAY && start)
            PrintBuf(buffer);
        else if (command == EXIT)
            break;
        else
            cout << "Error! Not found command" << endl;
    }
    return 0;
}

