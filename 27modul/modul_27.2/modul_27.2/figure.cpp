#include "figure.h"

void Figure::SetColor(string color)
{
    if (color != "red" && color != "blue" && color != "green")
        color = "none";
    this->color = color;
}

void Figure::GetDescribedRectangle(double _x, double _y)
{
    Point *a = new Point(center->GetX() - _x, center->GetY() - _y);
    Point *b = new Point(center->GetX() + _x, center->GetY() - _y);
    Point *c = new Point(center->GetX() + _x, center->GetY() + _y);
    Point *d = new Point(center->GetX() - _x, center->GetY() + _y);

    cout << "Described rectangle:" << endl;
    cout << "\tA(" << a->GetX() << ", " << a->GetY() << ");" << endl;
    cout << "\tB(" << b->GetX() << ", " << b->GetY() << ");" << endl;
    cout << "\tC(" << c->GetX() << ", " << c->GetY() << ");" << endl;
    cout << "\tD(" << d->GetX() << ", " << d->GetY() << ");" << endl;

    delete a;
    delete b;
    delete c;
    delete d;
}
