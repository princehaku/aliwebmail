#include "myqnetworkaccessmanager.h"
#include <QSettings>
#include <QSslCertificate>
#include <QSslError>
#include <qDebug>

myQNetworkAccessManager::myQNetworkAccessManager()
{
    connect(this, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError>&)),
                SLOT(sslErrors(QNetworkReply*, const QList<QSslError>&)));
}

void myQNetworkAccessManager::sslErrors(QNetworkReply *reply, const QList<QSslError> &error)
{
    qDebug() << "handleSslErrors: ";
        reply->ignoreSslErrors();
}
