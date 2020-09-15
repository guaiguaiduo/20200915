#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include <QtCharts>
namespace Ui {
class form;
}

class form : public QWidget
{
    Q_OBJECT

public:
    explicit form(QWidget *parent = 0);
    int a, b,c;
    int date[4];
    int weight[5];
    QChartView *chartview;
    QChart *chart;
    void getspiece();
    void getweight();
    void getnumber(int a1,int b1,int c1,int date1[],int weight1[]);
    void getdate();
    ~form();

private:
    Ui::form *ui;

};

#endif // FORM_H
