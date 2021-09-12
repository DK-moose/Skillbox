#include "window.h"

using namespace std;
int main()
{
	string command;
	Screen *screen = new Screen();
	Window *window = new Window();
	while (true)
	{
		cout << "Please, input command (move, resize, display) or \"close\" for exit: ";
		cin >> command;
		if (command == "move")
		{
			int x, y;
			cout << "Input displacement vector (coordinates of vector separated by a space): ";
			cin >> x >> y;
			window->Move(x, y);
		}
		else if (command == "resize")
		{
			int w, h;
			cout << "Input new size of the window (width and height separates by a space): ";
			cin >> w >> h;
			window->Resize(w, h);
		}
		else if (command == "display")
		{
			window->WindowToScreen(*screen);
			screen->PrintScreen();
		}

		else if (command == "close")
		{
			delete window;
			delete screen;
			break;
		}
		else cout << "Error! Invalid input" << endl;
	}
	return 0;
}
