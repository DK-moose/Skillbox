#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <iostream>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QDebug>

class ImageButton : public QPushButton
{
    Q_OBJECT

public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    ~ImageButton();

    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void SetUp();
    void SetDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;

    QMediaPlayer audioClick;
};
#endif // IMAGEBUTTON_H
