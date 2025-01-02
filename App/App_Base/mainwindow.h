#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog_http.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_httpClientButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog_http *httpDialog;//todo: use smart pointer here

};
#endif // MAINWINDOW_H
