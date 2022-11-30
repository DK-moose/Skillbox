#include "mainwidget.h"
#include "./ui_mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    ui->sliderBlurRadius->setMaximum(10);
    ui->sliderBlurRadius->setMinimum(0);
    ui->sliderBlurRadius->setValue(0);

    ui->buttonSave->setVisible(false);
    ui->buttonSaveAll->setVisible(false);
    ui->buttonPrevious->setVisible(false);
    ui->buttonNext->setVisible(false);
    ui->sliderBlurRadius->setVisible(false);

    absPathToDir = QDir::currentPath();
    absPathToDir = absPathToDir.left(absPathToDir.lastIndexOf('/') + 1) + "BlurPhotoEditor";
}

MainWidget::~MainWidget()
{
    delete ui;
}

QImage blurImage(QString path, int radius)
{
    QImage source(path);
    if (source.isNull()) {
        qDebug() << "Error: (QImage)source.isNull = true" << endl;
        return QImage();
    }
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(radius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage resultImg(source.size(), QImage::Format_ARGB32);
    resultImg.fill(Qt::transparent);
    QPainter painter(&resultImg);
    scene.render(&painter, QRectF(), QRectF(0, 0, source.width(), source.height()));
    return resultImg;
}

void processSingleImage(QString sourceFile, QString dirPath, int radius)
{
    auto blured = blurImage(sourceFile, radius);
    QString fileName = "blured_" + sourceFile.mid(sourceFile.lastIndexOf('/') + 1);
    if (!blured.save(dirPath + "/" + fileName))
        qDebug() << "Error: file \"" << fileName << "\" not saved!" << endl;
}

void MainWidget::open()
{
    imgPaths = QFileDialog::getOpenFileNames(0, tr("Открыть изображения"), absPathToDir, "*.jpg *.JPG");

    if (imgPaths.length() == 0) {
        ui->labelImage->clear();
        ui->labelImage->setText("Откройте изображение...");
        ui->buttonSave->setVisible(false);
        ui->buttonSaveAll->setVisible(false);
        ui->buttonPrevious->setVisible(false);
        ui->buttonNext->setVisible(false);
        ui->sliderBlurRadius->setVisible(false);
        return;
    }
    if (imgPaths.length() >= 1) {
        ui->buttonSave->setVisible(true);
        ui->sliderBlurRadius->setVisible(true);
    } else {
        ui->buttonSave->setVisible(false);
        ui->sliderBlurRadius->setVisible(false);
    }
    if (imgPaths.length() > 1) {
        ui->buttonSaveAll->setVisible(true);
        ui->buttonPrevious->setVisible(true);
        ui->buttonNext->setVisible(true);
    } else {
        ui->buttonSaveAll->setVisible(false);
        ui->buttonPrevious->setVisible(false);
        ui->buttonNext->setVisible(false);
    }

    absPathToDir = imgPaths[0].left(imgPaths[0].lastIndexOf('/'));
    indexActiveImg = 0;

    setBluredImage(ui->sliderBlurRadius->value());
}

void MainWidget::save()
{
    QString fileName = imgPaths[indexActiveImg];
    QString dirPath = absPathToDir + "/blured_" + QString::number(ui->sliderBlurRadius->value());
    if (!QDir(dirPath).exists())
        QDir().mkdir(dirPath);
    processSingleImage(imgPaths[indexActiveImg], dirPath, ui->sliderBlurRadius->value());
}

void MainWidget::saveAll()
{
    QString dirPath = absPathToDir + "/blured_" + QString::number(ui->sliderBlurRadius->value());
    if (!QDir(dirPath).exists())
        QDir().mkdir(dirPath);
    QList<QFuture<void>> handlers;
    for (auto path : imgPaths) {
        handlers.append(QtConcurrent::run(processSingleImage, path, dirPath, ui->sliderBlurRadius->value()));
    }
    for (auto &h : handlers) {
        h.waitForFinished();
    }
}

void MainWidget::previous()
{
    if (indexActiveImg != 0)
        indexActiveImg--;
    setBluredImage(ui->sliderBlurRadius->value());
}

void MainWidget::next()
{
    if (indexActiveImg != imgPaths.length() - 1)
        indexActiveImg++;
    setBluredImage(ui->sliderBlurRadius->value());
}

void MainWidget::setBluredImage(int val)
{
    activeImg = blurImage(imgPaths[indexActiveImg], val);
    ui->labelImage->setPixmap(QPixmap::fromImage(activeImg).scaled(ui->labelImage->width(), ui->labelImage->height(), Qt::KeepAspectRatio));
}
