#include "calculator.h"
#include "./ui_calculator.h"
#include <QDebug>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::plus()
{
    ui->lblAction->setText("+");
    printResult();
}

void Calculator::minus()
{
    ui->lblAction->setText("-");
    printResult();
}

void Calculator::devide()
{
    ui->lblAction->setText("/");
    printResult();
}

void Calculator::multiply()
{
    ui->lblAction->setText("*");
    printResult();
}

void Calculator::printResult()
{
    if (IsDouble(ui->firstLineEdit->text()) && IsDouble(ui->secondLineEdit->text()))
    {
        double first = ui->firstLineEdit->text().toDouble();
        double second = ui->secondLineEdit->text().toDouble();
        if (ui->lblAction->text() == "+")
            ui->lblResult->setText(QString::number(first + second));
        else if (ui->lblAction->text() == "-")
            ui->lblResult->setText(QString::number(first - second));
        else if (ui->lblAction->text() == "/")
            ui->lblResult->setText(QString::number(first / second));
        else if (ui->lblAction->text() == "*")
            ui->lblResult->setText(QString::number(first * second));
    }
    else
        ui->lblResult->setText("ERROR");
}

bool Calculator::IsDouble(QString val)
{
    bool pointExist = false;
    for (int i = 0; i < val.size(); i++)
    {
        if ((val[i] < '0' || val[i] > '9') && val[i] != '.' && val[i] != '-' && val[i] != '+')
        {
            qDebug() << "1" << endl;
            return false;
        }
        if ((val[i] == '-' || val[i] == '+') && i != 0)
        {
            qDebug() << "2" << endl;
            return false;
        }
        if (val[i] == '.' && !pointExist)
        {
            pointExist = true;
        }
        else if (val[i] == '.' && pointExist)
        {
            qDebug() << "3" << endl;
            return false;
        }
    }
    return true;
}

