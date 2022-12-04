#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

public slots:
    void checkText(QString text);
    void setOk();
    void setFailed();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
