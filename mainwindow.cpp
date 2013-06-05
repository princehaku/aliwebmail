#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebView* WebView= ui->webView;

    //WebView->page()->setNetworkAccessManager(own);
    connect(WebView->page()->networkAccessManager(),
            SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )),
            this,
            SLOT(handleSslErrors(QNetworkReply*, const QList<QSslError> & ))
            );
    connect(WebView, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
    connect(WebView, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));

    WebView->settings()->setAttribute(QWebSettings::JavaEnabled, true);

    WebView->settings()->enablePersistentStorage("./");
    WebView->settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
    WebView->settings()->setAttribute(QWebSettings::JavascriptCanCloseWindows, true);
    WebView->settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
    WebView->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    // 打开后可以使用系统的flash等扩展目测和ime部分时候有冲突
    // WebView->settings()->setAttribute(QWebSettings::PluginsEnabled, true);

    WebView->load(QUrl("https://webmail.alibaba-inc.com/alimail/auth/login"));
}

void MainWindow::handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors)
{
    reply->ignoreSslErrors();
}

void MainWindow::finishLoading(bool is_finished) {
    if (is_finished) {
        QWebFrame* frame = ui->webView->page()->mainFrame();
        frame->evaluateJavaScript("./loadcomplete.js");
        qDebug() <<  frame->url();
    }
}

void MainWindow::setProgress(int p)
{
    ui->statusBar->showMessage(QString("%1 (%2%)").arg("Loading").arg(p), 1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
