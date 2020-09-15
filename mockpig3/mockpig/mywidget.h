#ifndef MYCHART_H
#define MYCHART_H
#include <QPushButton>
#include <QWidget>
#include <widget.h>
class mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit mywidget(QWidget *parent = nullptr);
    QPushButton b1;
    Widget s;
signals:

public slots:
};

#endif // MYCHART_H
