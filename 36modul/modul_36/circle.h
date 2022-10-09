#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QResizeEvent>
//#include <iostream>
#include <cmath>

class Circle : public QWidget
{
    Q_OBJECT
public:
    explicit Circle(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *e) override;
    QSize minimumSizeHint() const override;

public slots:
    void SetColor(int val);

private:
    double red = 255;
    double green = 255;
};

#endif // RECTANGLE_H
