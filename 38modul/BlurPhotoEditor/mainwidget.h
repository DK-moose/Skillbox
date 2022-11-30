#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QImage>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QPixmap>
#include <QPainter>
#include <QFileDialog>
#include <QDir>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QString>
#include <QStringList>

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
    void open();
    void save();
    void saveAll();
    void previous();
    void next();
    void setBluredImage(int val);

private:
    Ui::MainWidget *ui;
    QStringList imgPaths;
    int indexActiveImg;
    QImage activeImg;
    QString absPathToDir;
};
#endif // MAINWIDGET_H
