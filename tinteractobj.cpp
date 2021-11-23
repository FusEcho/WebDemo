#include "tinteractobj.h"

TInteractObj::TInteractObj(QObject *parent)
{

}

TInteractObj::~TInteractObj(){}

void TInteractObj::JSSendMessage(QString data1, QString data2, QString data3, QString data4,
                                 QString data5, QString data6, QString data7, QString data8, QString data9){

    emit SigReceivedMessFromJS(data1, data2, data3, data4, data5, data6, data7, data8, data9);
}
