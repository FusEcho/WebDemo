#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QUrl>
#include <QFrame>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webview->setUrl(QUrl("qrc:/index.html"));

    connect(ui->webview->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()),this,SLOT(populateJavaScriptWindowObject()));
    connect(ui->import_btn,SIGNAL(clicked()),this,SLOT(getValues()));
}


void MainWindow::populateJavaScriptWindowObject()
{
    ui->webview->page()->mainFrame()->addToJavaScriptWindowObject("mainWindow",
                                                                  this);
}

void MainWindow::setValues(const QString &data1, const QString &data2,
                           const QString &data3, const QString &data4,
                           const QString &data5, const QString &data6,
                           const QString &data7, const QString &data8,
                           const QString &data9){

    qDebug() << "data1 : " << data1;
    qDebug() << "data2 : " << data2;
    qDebug() << "data3 : " << data3;
    qDebug() << "data4 : " << data4;
    qDebug() << "data5 : " << data5;
    qDebug() << "data6 : " << data6;
    qDebug() << "data7 : " << data7;
    qDebug() << "data8 : " << data8;
    qDebug() << "data9 : " << data9;

    QDomDocument document;
    //xml头部的<?xml version="1.0" encoding="UTF-8"?>
    QDomProcessingInstruction instruction = document.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    document.appendChild(instruction);
    QDomElement root_node = document.createElement("dataset");//创建根结点
    document.appendChild(root_node);    //添加根结点

//    for (int i = 1; i <= 9;i++) {
//        QDomElement element = document.createElement("data");//创建元素结点
//        element.setAttribute("name", "data1");
//        element.setAttribute("id", "data1");
//        element.setAttribute("data-type", "string");
//        element.setAttribute("value", data1);
//        element.setAttribute("unit", "A");
//        root_node.appendChild(element);//元素结点添加到根结点下
//    }

    QDomElement element1 = document.createElement("data");//创建元素结点
    element1.setAttribute("name", "data1");
    element1.setAttribute("id", "data1");
    element1.setAttribute("data-type", "string");
    element1.setAttribute("value", data1);
    element1.setAttribute("unit", "A");
    root_node.appendChild(element1);//元素结点添加到根结点下

    QDomElement element2 = document.createElement("data");//创建元素结点
    element2.setAttribute("name", "data2");
    element2.setAttribute("id", "data2");
    element2.setAttribute("data-type", "string");
    element2.setAttribute("value", data2);
    element2.setAttribute("unit", "A");
    root_node.appendChild(element2);//元素结点添加到根结点下

    QDomElement element3 = document.createElement("data");//创建元素结点
    element3.setAttribute("name", "data3");
    element3.setAttribute("id", "data3");
    element3.setAttribute("data-type", "string");
    element3.setAttribute("value", data3);
    element3.setAttribute("unit", "A");
    root_node.appendChild(element3);//元素结点添加到根结点下

    QDomElement element4 = document.createElement("data");//创建元素结点
    element4.setAttribute("name", "data4");
    element4.setAttribute("id", "data4");
    element4.setAttribute("data-type", "string");
    element4.setAttribute("value", data4);
    element4.setAttribute("unit", "A");
    root_node.appendChild(element4);//元素结点添加到根结点下

    QDomElement element5 = document.createElement("data");//创建元素结点
    element5.setAttribute("name", "data5");
    element5.setAttribute("id", "data5");
    element5.setAttribute("data-type", "string");
    element5.setAttribute("value", data5);
    element5.setAttribute("unit", "A");
    root_node.appendChild(element5);//元素结点添加到根结点下

    QDomElement element6 = document.createElement("data");//创建元素结点
    element6.setAttribute("name", "data6");
    element6.setAttribute("id", "data6");
    element6.setAttribute("data-type", "string");
    element6.setAttribute("value", data6);
    element6.setAttribute("unit", "A");
    root_node.appendChild(element6);//元素结点添加到根结点下

    QDomElement element7 = document.createElement("data");//创建元素结点
    element7.setAttribute("name", "data7");
    element7.setAttribute("id", "data7");
    element7.setAttribute("data-type", "string");
    element7.setAttribute("value", data7);
    element7.setAttribute("unit", "A");
    root_node.appendChild(element7);//元素结点添加到根结点下

    QDomElement element8 = document.createElement("data");//创建元素结点
    element8.setAttribute("name", "data8");
    element8.setAttribute("id", "data8");
    element8.setAttribute("data-type", "string");
    element8.setAttribute("value", data8);
    element8.setAttribute("unit", "A");
    root_node.appendChild(element8);//元素结点添加到根结点下

    QDomElement element9 = document.createElement("data");//创建元素结点
    element9.setAttribute("name", "data9");
    element9.setAttribute("id", "data9");
    element9.setAttribute("data-type", "string");
    element9.setAttribute("value", data9);
    element9.setAttribute("unit", "A");
    root_node.appendChild(element9);//元素结点添加到根结点下
    //写入文件
    QFile file("data.xml");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        return;
    }
    QTextStream in(&file);
    document.save(in, 4);
    file.close();

}

void MainWindow::getValues(){
    str["data1"] = QVariant("10");
    str["data2"] = QVariant("20");
    str["data3"] = QVariant("30");
    str["data4"] = QVariant("40");
    str["data5"] = QVariant("50");
    str["data6"] = QVariant("60");
    str["data7"] = QVariant("70");
    str["data8"] = QVariant("80");
    str["data9"] = QVariant("90");

    qDebug() << "import_btn clicked";

    emit sendstr(str);
}


MainWindow::~MainWindow()
{
    delete ui;
}

