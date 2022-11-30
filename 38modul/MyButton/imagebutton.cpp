#include "imagebutton.h"
#include <QDir>

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Вкл");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mButtonUpPixmap = QPixmap("../MyButton/recourse/imgButton_up.png");
    mButtonDownPixmap = QPixmap("../MyButton/recourse/imgButton_down.png");
    mCurrentButtonPixmap = mButtonUpPixmap;

    QString pathToDir = QDir::currentPath();
    pathToDir = pathToDir.remove(pathToDir.lastIndexOf('/'), pathToDir.length()) + "/MyButton";
    audioClick.setMedia(QUrl::fromLocalFile(pathToDir + "/recourse/click.mp3"));

    setGeometry(mCurrentButtonPixmap.rect());

    connect(this, &QPushButton::clicked, this, &ImageButton::SetDown);
}

ImageButton::~ImageButton()
{
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(80, 80);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e)
{
    SetDown();
}

void ImageButton::SetDown()
{
    audioClick.play();
    mCurrentButtonPixmap = mButtonDownPixmap;
    QTimer::singleShot(150, this, &ImageButton::SetUp);
    update();
}

void ImageButton::SetUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}
