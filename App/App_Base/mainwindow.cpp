#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_httpClientButton_clicked()
{
    // Dialog_http dialogHttp;
    // dialogHttp.setModal(true);
    // dialogHttp.exec();
    httpDialog = new Dialog_http(this);
    httpDialog->show();
}

