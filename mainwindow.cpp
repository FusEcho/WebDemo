#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QString data1, data2, data3, data4, data5, data6, data7, data8, data9;
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

}

MainWindow::~MainWindow()
{
    delete ui;
}
