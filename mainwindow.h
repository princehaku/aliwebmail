#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow* ui;

private slots:
    void setProgress(int p);
    void finishLoading(bool is_finished);
    void handleSslErrors(QNetworkReply* reply, const QList<QSslError> &errors);
};

#endif // MAINWINDOW_H
