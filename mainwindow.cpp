#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebView* WebView= ui->webView;

    connect(WebView->page()->networkAccessManager(),
            SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )),
            this,
            SLOT(handleSslErrors(QNetworkReply*, const QList<QSslError> & ))
            );

    WebView->settings()->setAttribute(QWebSettings::JavaEnabled, true);
    QWebSettings::enablePersistentStorage("./");

    WebView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    WebView->settings()->setAttribute(QWebSettings::JavascriptCanCloseWindows, true);
    WebView->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    WebView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    WebView->settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    WebView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    WebView->load(QUrl("https://webmail.alibaba-inc.com/alimail/"));
}

void MainWindow::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
    qDebug() << "handleSslErrors: ";

    reply->ignoreSslErrors();
}

void MainWindow::onLoadingTips() {
    ui->statusBar->showMessage(tr("Loading"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
