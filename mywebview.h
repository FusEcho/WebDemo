#ifndef MYWEBVIEW_H
#define MYWEBVIEW_H

#include <QWidget>
#include <QWebEngineView>

class MyWebView : public QWidget
{
    Q_OBJECT

public:
    explicit MyWebView(QWidget *parent = 0);
    ~MyWebView();

    QWebEngineView *view;
};

#endif // MYWEBVIEW_H
