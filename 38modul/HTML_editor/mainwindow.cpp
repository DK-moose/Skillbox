#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    InitParametersWebView();
    InitParametersTextEdit();

    ui->fileName->setText(fileName);
    absPathToFilesDir = QDir::currentPath() + "/htmlFiles";
    if (!QDir(absPathToFilesDir).exists())
        QDir().mkdir(absPathToFilesDir);
}

MainWindow::~MainWindow()
{
    delete wView;
    delete ui;
}

void MainWindow::InitParametersTextEdit()
{
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, [this](){
        wView->setHtml(ui->plainTextEdit->toPlainText());
        if (!updateText) {
            updateText = true;
            ui->fileName->setText(fileName + "*");
        }
    });
}

void MainWindow::InitParametersWebView()
{
    wView = new QWebEngineView(ui->webView);
    wView->setMinimumSize(ui->webView->size());
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    wView->setGeometry(wView->x(), wView->y(), ui->plainTextEdit->width(), ui->plainTextEdit->height());
}

void MainWindow::on_menuOpenFile_triggered()
{
    QString path = QFileDialog::getOpenFileName(nullptr, "Открыть файл", absPathToFilesDir, "*.html");
    if (path != absPathToFile)
    {
        absPathToFile = path;
        QFile file(absPathToFile);
        if (file.open(QIODevice::ReadWrite))
        {
            ui->plainTextEdit->setPlainText(file.readAll());
            fileName = file.fileName().mid(file.fileName().lastIndexOf('/') + 1);
            ui->fileName->setText(fileName);
            updateText = false;
            ui->fileName->setText(fileName);
            file.close();
        }
    }
}

void MainWindow::on_menuSave_triggered()
{
    QFile file(absPathToFile);
    if (!file.exists()) {
        qDebug() << "File '" + fileName + "' not found!";
        return;
    }

    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream writeStream(&file);
        writeStream << ui->plainTextEdit->toPlainText();
        updateText = false;
        ui->fileName->setText(fileName);
        file.close();
    }
}

void MainWindow::on_menuSaveAs_triggered()
{
    absPathToFile = QFileDialog::getSaveFileName(nullptr, "Сохранить файл", absPathToFilesDir + "/" + fileName, "*.html");
    QFile file(absPathToFile);
    if (!file.exists()) {
        if (file.open(QIODevice::WriteOnly)) {
            QTextStream writeStraem(&file);
            writeStraem << ui->plainTextEdit->toPlainText();
            updateText = false;
            ui->fileName->setText(fileName);
            file.close();
        }
    }
}

void MainWindow::on_menuHideEditor_triggered()
{
    if (ui->menuHideEditor->text() == "Скрыть редактор") {
        ui->menuHideEditor->setText("Открыть редактор");
        ui->plainTextEdit->setVisible(false);
        ui->menuHideWebView->setDisabled(true);
    } else {
        ui->menuHideEditor->setText("Скрыть редактор");
        ui->plainTextEdit->setVisible(true);
        ui->menuHideWebView->setDisabled(false);
    }
}

void MainWindow::on_menuHideWebView_triggered()
{
    if (ui->menuHideWebView->text() == "Скрыть WebView") {
        ui->menuHideWebView->setText("Открыть WebView");
        ui->webView->setVisible(false);
        ui->menuHideEditor->setDisabled(true);
    } else {
        ui->menuHideWebView->setText("Скрыть WebView");
        ui->webView->setVisible(true);
        ui->menuHideEditor->setDisabled(false);
    }
}

void MainWindow::on_menuExit_triggered()
{
    close();
}
