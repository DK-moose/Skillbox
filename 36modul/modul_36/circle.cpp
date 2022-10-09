#include "circle.h"

Circle::Circle(QWidget *parent) : QWidget(parent)
{

}

void Circle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.setBrush(QBrush(QColor((int)red, (int)green, 0), Qt::SolidPattern));
    int diameter = (this->width() < this->height()) ? this->width() - 2 : this->height() - 2;
    int x = this->width() / 2 - diameter / 2;
    int y = this->height() / 2 - diameter / 2;
    p.drawEllipse(x, y, diameter, diameter);
}

QSize Circle::minimumSizeHint() const
{
    return QSize(100, 100);
}

// По заданию
/*
void Circle::SetColor(int val)
{
    if (val < 33)
    {
        red = 255;
        green = 255;
    }
    else if (val >= 33 && val <= 66)
    {
        red = 0;
        green = 255;
    }
    else
    {
        red = 255;
        green = 0;
    }
    update();
}
*/

// Плавный переход цвета
void Circle::SetColor(int val)
{
    red = 0.102 * std::pow(val - 50, 2);
    if (val > 50)
        green = 255 - 5.1 * (val - 50);
    else green = 255;
    //std::cout << "R: " << red << ", G: " << green << ", Value: " << val << std::endl;
    update();
}
