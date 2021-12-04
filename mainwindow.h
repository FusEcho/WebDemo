#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKit>
#include <QList>
#include <QDomElement>
#include <QDomNode>
#include <QFile>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signal();
    void sendstr(QVariant object);
    void update();

public slots:
    void populateJavaScriptWindowObject();
//    void setValues(const QString &data1, const QString &data2,
//                   const QString &data3, const QString &data4,
//                   const QString &data5, const QString &data6,
//                   const QString &data7, const QString &data8,
//                   const QString &data9);
    void setValues(QVariant obj);
    void onTime();
    void getValues();

private:
    Ui::MainWindow *ui;
    QVariant str;
    QTimer *timer;
};
#endif // MAINWINDOW_H
