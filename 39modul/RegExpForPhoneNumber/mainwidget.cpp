#include "mainwidget.h"
#include "./ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setFailed();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::checkText(QString text)
{
    QRegularExpression exp("^\\+[0-9]{11}$");
    //QRegularExpression exp("^8[0-9]{10}$");
    //QRegularExpression exp("^\\+7\\([0-9]{3}\\)\\-[0-9]{3}\\-[0-9]{2}\\-[0-9]{2}$");
    if (exp.match(text).hasMatch())
        setOk();
    else
        setFailed();
}

void MainWidget::setOk()
{
    ui->label->setText("Ok");
    ui->label->setStyleSheet("color: green");
}

void MainWidget::setFailed()
{
    ui->label->setText("Failed");
    ui->label->setStyleSheet("color: red");
}
