#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QDir>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitParametersTextEdit();
    void InitParametersWebView();

public slots:
    void resizeEvent(QResizeEvent *e);

private slots:
    void on_menuOpenFile_triggered();
    void on_menuSave_triggered();
    void on_menuSaveAs_triggered();
    void on_menuHideEditor_triggered();
    void on_menuHideWebView_triggered();
    void on_menuExit_triggered();

private:
    Ui::MainWindow *ui;
    QWebEngineView *wView;

    QString fileName = "test.html";
    QString absPathToFilesDir;
    QString absPathToFile;

    bool updateText = false;
};
#endif // MAINWINDOW_H
