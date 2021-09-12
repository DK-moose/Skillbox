#include "window.h"

Window::Window()
{
	start = Point(0, 0);
	width = 0;
	height = 0;
}

Window::Window(Point start, int width, int height)
{
	if (start.GetX() < 0)
		this->start.SetX(0);
	else if (start.GetX() > W_WIDTH)
		this->start.SetX(W_WIDTH);
	else this->start.SetX(start.GetX());

	if (start.GetY() < 0)
		this->start.SetY(0);
	else if (start.GetY() > W_HEIGHT)
		this->start.SetY(W_WIDTH);
	else this->start.SetY(start.GetY());

	if (width < 0) this->width = 0;
	else this->width = width;

	if (height < 0) this->height = 0;
	else this->height = height;
}

void Window::WindowToScreen(Screen &screen)
{
	vector<vector<bool>> *vs = screen.GetVsualScreen();
	for (int i = 0; i < screen.GetHeight(); i++)
	{
		vector<bool> vec = vs->at(i);
		for (int j = 0; j < screen.GetWidth(); j++)
		{
			if ((((i >= start.GetY() && i - start.GetY() < height) && (j >= start.GetX() && j - start.GetX() < width)) && !vec[j]) ||
				 ((i < start.GetY() || i - start.GetY() >= height) || (j < start.GetX() || j - start.GetX() >= width)) && vec[j])
				vec[j] = !vec[j];
		}
		vs->at(i) = vec;
	}
	screen.SetVisualScreen(*vs);
}

void Window::Move(int x, int y)
{
	int X = start.GetX() + x;
	if (X >= 0 && X < W_WIDTH) start.SetX(X);
	int Y = start.GetY() + y;
	if (Y >= 0 && Y < W_HEIGHT) start.SetY(Y);
	cout << "New coordinates of the window: " << start.GetX() << ", " << start.GetY() << endl;
}

void Window::Resize(int w, int h)
{
	if (w < 0) width = 0;
	else width = w;

	if (h < 0) height = 0;
	else height = h;

	cout << "New size of the window: " << w << "x" << h << endl;
}