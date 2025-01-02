#include "httpclient.h"

HttpClient::HttpClient(QObject *parent) : QObject(parent) {}

void HttpClient::get(const QUrl &url) {
    if (!url.isValid())
    {
        qWarning() << "Invalid URL:" << url.toString();
        return;
    }

    QNetworkRequest request(url);
    QNetworkReply *reply = qnam.get(request);

    connect(reply, &QNetworkReply::finished, this, &HttpClient::onFinished);
    connect(reply, &QIODevice::readyRead, this, &HttpClient::onReadyRead);
    connect(reply, &QNetworkReply::downloadProgress, this, &HttpClient::onProgress);
}

void HttpClient::post(const QUrl &url, const QByteArray &data) {
    if (!url.isValid())
    {
        qWarning() << "Invalid URL:" << url.toString();
        return;
    }
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply *reply = qnam.post(request, data);

    connect(reply, &QNetworkReply::finished, this, &HttpClient::onFinished);
    connect(reply, &QIODevice::readyRead, this, &HttpClient::onReadyRead);
    connect(reply, &QNetworkReply::uploadProgress, this, &HttpClient::onProgress);
}

void HttpClient::onFinished() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (!reply) return;

    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Request finished successfully.";
        qDebug() << "Response:" << reply->readAll();
    } else {
        qWarning() << "Request failed:" << reply->errorString();
    }

    reply->deleteLater();
}

void HttpClient::onReadyRead() {
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if (reply) {
        QByteArray data = reply->readAll();
        qDebug() << "Received data chunk:" << data;
    }
}

void HttpClient::onProgress(qint64 bytesSent, qint64 bytesTotal) {
    if (bytesTotal > 0) {
        qDebug() << "Progress:" << (bytesSent * 100) / bytesTotal << "%";
    }
}
