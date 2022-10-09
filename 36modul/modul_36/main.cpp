#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QSlider>
#include <circle.h>

using namespace std;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget *mainWindow = new QWidget;
    mainWindow->setMinimumSize(200, 250);

    Circle *circle = new Circle;
    QSlider *slider = new QSlider(Qt::Horizontal);

    auto *mainLayout = new QVBoxLayout(mainWindow);
    mainLayout->addWidget(circle);
    mainLayout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, circle, &Circle::SetColor);

    mainWindow->show();
    return app.exec();
}
