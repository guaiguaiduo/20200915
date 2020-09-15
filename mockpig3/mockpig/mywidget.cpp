#include "mywidget.h"
#include <widget.h>
mywidget::mywidget(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/3d35aae7a10f19ec770314214219ee50.jpg");
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);
   this->setMaximumHeight(500);
    this->setMaximumWidth(500);
    b1.setMinimumHeight(50);
    b1.setMinimumWidth(100);
    b1.setContentsMargins(50,50,50,50);
    b1.setText("开始养猪吧");
    b1.move(200,200);
    b1.setParent(this);
    connect(&b1,&QPushButton::clicked,
            [=]()
    {
        this->hide();
        s.show();
    });
}
