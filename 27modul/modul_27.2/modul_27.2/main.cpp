#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "rectangle.h"
#include <string>

using namespace std;
int main()
{
    string figure;
    while (true)
    {
        cout << "Input \"circle\", \"square\", \"triangle\", \"rectangle\" or \"exit\": ";
        cin >> figure;
        if (figure == "exit") break;
        else if (figure == "circle")
        {
            double x, y, r, s;
            string color;
            cout << "Input coordinates of center and radius (X Y R): ";
            cin >> x >> y >> r;
            cout << "Input color of figure: ";
            cin >> color;
            Circle *circle = new Circle(new Point(x, y), color, r);
            s = circle->GetSquare();
            cout << "Square: " << s << endl;
            circle->GetDescribedRectangle();
            delete circle;
        }
        else if (figure == "square" || figure == "triangle")
        {
            double x, y, w, s;
            string color;
            cout << "Input coordinates of center and edge length (X Y W): ";
            cin >> x >> y >> w;
            cout << "Input color of figure: ";
            cin >> color;
            if (figure == "square")
            {
                Square *square = new Square(new Point(x, y), color, w);
                s = square->GetSquare();
                cout << "Square: " << s << endl;
                square->GetDescribedRectangle();
                delete square;
            }
            else
            {
                Triangle *triangle = new Triangle(new Point(x, y), color, w);
                s = triangle->GetSquare();
                cout << "Square: " << s << endl;
                triangle->GetDescribedRectangle();
                delete triangle;
            }
        }
        else if (figure == "rectangle")
        {
            double x, y, w, h, s;
            string color;
            cout << "Input coordinates of center, width and height (X Y W H): ";
            cin >> x >> y >> w >> h;
            cout << "Input color of figure: ";
            cin >> color;
            Rectangle *rectangle = new Rectangle(new Point(x, y), color, w, h);
            s = rectangle->GetSquare();
            cout << "Square: " << s << endl;
			rectangle->GetDescribedRectangle();
            delete rectangle;
        }
        else cout << "Error: invalid input! Try again." << endl;
    }
    return 0;
}

