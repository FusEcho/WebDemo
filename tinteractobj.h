#ifndef TINTERACTOBJ_H
#define TINTERACTOBJ_H

#include <QObject>

class TInteractObj : public QObject
{
    Q_OBJECT

public:
    TInteractObj(QObject *parent);
    ~TInteractObj();

    Q_INVOKABLE void JSSendMessage(QString data1, QString data2, QString data3, QString data4,
                                   QString data5, QString data6, QString data7, QString data8, QString data9);

    QString m_value;    //本地保存的数据对象

    signals:
        void SigReceivedMessFromJS(QString data1, QString data2, QString data3, QString data4,
                                   QString data5, QString data6, QString data7, QString data8, QString data9);          //网页调用函数给qt发送该信号
        void SigSendMessageToJS(QString data1, QString data2, QString data3, QString data4,
                                QString data5, QString data6, QString data7, QString data8, QString data9);             //给网页发送数据的信号
};

#endif // TINTERACTOBJ_H
