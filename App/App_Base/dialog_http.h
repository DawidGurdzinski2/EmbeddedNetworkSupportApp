#ifndef DIALOG_HTTP_H
#define DIALOG_HTTP_H

#include <QDialog>
#include "httpclient.h"

namespace Ui {
class Dialog_http;
}

class Dialog_http : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_http(QWidget *parent = nullptr);
    ~Dialog_http();

private slots:

    void on_get_btn_clicked();

    void on_post_btn_clicked();

private:
    Ui::Dialog_http *ui;
    HttpClient  client;
};

#endif // DIALOG_HTTP_H
