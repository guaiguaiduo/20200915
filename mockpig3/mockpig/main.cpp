#include "widget.h"
#include <QApplication>
#include <mywidget.h>
#include <QPushButton>
#include <QDebug>
#include <mywidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mywidget s;
    s.show();
    return a.exec();
}
