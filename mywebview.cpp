#include "mywebview.h"

MyWebView::MyWebView(QWidget *parent)
{
    view = new QWebEngineView(this);
    view->load(QUrl("http://www.baidu.com"));
    view->show();
}

MyWebView::~MyWebView(){
    delete view;
}


