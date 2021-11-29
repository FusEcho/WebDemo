#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKit>
#include <QMap>
#include <QDomElement>
#include <QDomNode>
#include <QFile>

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
    void sendstr(QMap<QString, QVariant> object);

public slots:
    void populateJavaScriptWindowObject();
    void setValues(const QString &data1, const QString &data2,
                   const QString &data3, const QString &data4,
                   const QString &data5, const QString &data6,
                   const QString &data7, const QString &data8,
                   const QString &data9);

    void getValues();

private:
    Ui::MainWindow *ui;
    QMap<QString, QVariant> str;
};
#endif // MAINWINDOW_H
