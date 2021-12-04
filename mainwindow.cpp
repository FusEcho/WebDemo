#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QUrl>
#include <QFrame>
#include <QDebug>
#include "QJsonDocument.h"
#include "QJsonArray.h"
#include "QJsonObject.h"
#include "QJsonValue.h"
#include "QJsonParseError.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webview->setUrl(QUrl("qrc:/index.html"));

    QTimer *timer = new QTimer(this);
    timer->setInterval(500);

    connect(timer,SIGNAL(timeout()), this, SLOT(onTime()));
    timer->start();

    connect(ui->webview->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()),this,SLOT(populateJavaScriptWindowObject()));
    connect(ui->import_btn,SIGNAL(clicked()),this,SLOT(getValues()));
}

void MainWindow::onTime(){
    qDebug() << "timer called";
    emit update();
}

void MainWindow::populateJavaScriptWindowObject()
{
    ui->webview->page()->mainFrame()->addToJavaScriptWindowObject("mainWindow",
                                                                  this);
}

void MainWindow::setValues(QVariant obj){
    QString jo = obj.toString();
    qDebug() << jo;
}

void MainWindow::getValues(){
    QVariantMap map;
    map.insert("data1","10");
    map.insert("data2","20");
    map.insert("data3","30");
    map.insert("data4","40");
    map.insert("data5","50");
    map.insert("data6","60");
    map.insert("data7","70");
    map.insert("data8","80");
    map.insert("data9","90");

    QJsonDocument doc = QJsonDocument::fromVariant(map);
    qDebug() << "import_btn clicked";

    emit sendstr(QVariant(QString::fromUtf8(doc.toJson())));
}


MainWindow::~MainWindow()
{
    delete ui;
}

