#include "dialog_http.h"
#include "ui_dialog_http.h"

Dialog_http::Dialog_http(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_http)
{
    ui->setupUi(this);
}

Dialog_http::~Dialog_http()
{
    delete ui;
}


void Dialog_http::on_get_btn_clicked()
{
    QUrl url = QUrl(ui->getUrl_lineEdit->text());
    qDebug() << url;
    client.get(url);
}


void Dialog_http::on_post_btn_clicked()
{
    QString url = ui->postUrl_lineEdit->text();
    QByteArray data = ui->postData_lineEdit->text().toUtf8();
    client.post(url, data);
}

