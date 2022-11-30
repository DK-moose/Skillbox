#include "imagebutton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageButton myButton(nullptr);
    myButton.setFixedSize(80, 80);
    myButton.move(1000, 400);
    QObject::connect(&myButton, &QPushButton::clicked, [](){qDebug() << "clicked\n";});
    myButton.show();
    return a.exec();
}
