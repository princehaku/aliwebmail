#ifndef MYQNETWORKACCESSMANAGER_H
#define MYQNETWORKACCESSMANAGER_H

#include <QNetworkAccessManager>
#include <QNetworkReply>

class myQNetworkAccessManager : public QNetworkAccessManager
{

public:
    myQNetworkAccessManager();

private slots:
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &error);
};

#endif // MYQNETWORKACCESSMANAGER_H
