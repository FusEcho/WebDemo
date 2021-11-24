#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDomElement>
#include <QDomNode>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebChannel *pWebChannel   = new QWebChannel(ui->widget->page());      //为网页视图页面创建通道channel
    pInteractObj = new TInteractObj(this);                   //创建通道对象用于与JS交互
    //"interactObj"为注册名，JS调用的对象名必须和它相同
    pWebChannel->registerObject(QStringLiteral("interactObj"), pInteractObj);//注册通道对象供JS调用
    ui->widget->page()->setWebChannel(pWebChannel);                         //设置通道
    ui->widget->load(QUrl("qrc://html/index.html"));

    //当网页返回数据，则会返回到通道对象pInteractObj中，然后再发送信号到主类OnReceiveMessageFromJS中处理
    connect(pInteractObj, &TInteractObj::SigReceivedMessFromJS, this,&MainWindow::OnReceiveMessageFromJS);
    //向网页发送信号需要利用通道对象pInteractObj的SigSendMessageToJS信号
    connect(this,&MainWindow::SigSendMessageToJS,pInteractObj, &TInteractObj::SigSendMessageToJS);

    connect(ui->import_btn,&QPushButton::clicked,this,&MainWindow::OnSendMessByInteractObj);
}


void MainWindow::OnSendMessByInteractObj(){
    qDebug() << "import_btn clicked";
    // PARSE xml FILE
//    QDomDocument doc;
//    QFile file("qrc://html/data.xml");
//    if (!file.open(QIODevice::ReadOnly))
//        return;

//    if (!doc.setContent(&file)){
//        file.close();
//        return;
//    }

//    file.close();

//    QDomNode

    QString data1="10", data2="20", data3="30", data4="40", data5="50", data6="60", data7="70", data8="80", data9="90";
    emit SigSendMessageToJS(data1, data2, data3, data4, data5, data6, data7, data8, data9);
}



void MainWindow::OnReceiveMessageFromJS(QString data1, QString data2, QString data3, QString data4,
                                        QString data5, QString data6, QString data7, QString data8, QString data9){
    qDebug() << "receive data1 : " << data1 << endl;
    qDebug() << "receive data2 : " << data2 << endl;
    qDebug() << "receive data3 : " << data3 << endl;
    qDebug() << "receive data4 : " << data4 << endl;
    qDebug() << "receive data5 : " << data5 << endl;
    qDebug() << "receive data6 : " << data6 << endl;
    qDebug() << "receive data7 : " << data7 << endl;
    qDebug() << "receive data8 : " << data8 << endl;
    qDebug() << "receive data9 : " << data9 << endl;

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

MainWindow::~MainWindow()
{
    delete ui;
}
