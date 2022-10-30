#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    bool IsDouble(QString val);

public slots:
    void plus();
    void minus();
    void devide();
    void multiply();
    void printResult();

private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
