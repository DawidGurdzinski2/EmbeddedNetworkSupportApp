#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QObject>
#include <QDebug>
#include <QByteArray>

class HttpClient : public QObject {
    Q_OBJECT

public:
    explicit HttpClient(QObject *parent = nullptr);

    void get(const QUrl &url);
    void post(const QUrl &url, const QByteArray &data);

private slots:
    void onFinished();
    void onReadyRead();
    void onProgress(qint64 bytesSent, qint64 bytesTotal);

private:
    QNetworkAccessManager qnam;
};

#endif // HTTPCLIENT_H
