#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebChannel>
#include <QWebEngineView>
#include "tinteractobj.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void SigSendMessageToJS(QString data1, QString data2, QString data3, QString data4,
                            QString data5, QString data6, QString data7, QString data8, QString data9);

public slots:
    void OnReceiveMessageFromJS(QString data1, QString data2, QString data3, QString data4,
                                QString data5, QString data6, QString data7, QString data8, QString data9);
    void OnSendMessByInteractObj();
private:
    Ui::MainWindow *ui;

    TInteractObj *pInteractObj;
};
#endif // MAINWINDOW_H
