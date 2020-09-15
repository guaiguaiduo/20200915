#include "form.h"
#include "ui_form.h"
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
form::form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form)
{
    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/345687ef6377499d26d491c8d27aa839.jpg");
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,
            [=]()
    {
        getspiece();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,
            [=]()
    {
        getweight();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,
            [=]()
    {
        getdate();
    });
}
void form::getnumber(int a1, int b1, int c1, int date1[], int weight1[])
{
    a=a1;b=b1;c=c1;
    int i;
    for(i=0;i<4;i++)
    {
        date[i]=date1[i];
    }
    for(i=0;i<5;i++)
    {
        weight[i]=weight1[i];
    }
}
void form::getspiece()
{
    if(chartview!=NULL)
    {
        delete chartview;
        chartview=NULL;
    }
    double t1,t2,t3;
    t1=a/((a+b+c)*1.0);
    t2=b/((a+b+c)*1.0);
    t3=c/((a+b+c)*1.0);
    QPieSlice *slice_1 = new QPieSlice(QStringLiteral("黑猪"), t1, this);
    slice_1->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_1->setBrush(Qt::green);
    QPieSlice *slice_2 = new QPieSlice(QStringLiteral("大白花猪"), t2, this);
    slice_2->setLabelVisible(true);
    slice_2->setBrush(Qt::blue);
    QPieSlice *slice_3 = new QPieSlice(QStringLiteral("大白花猪"), t3, this);
    slice_3->setLabelVisible(true);
    slice_3->setBrush(Qt::yellow);
    // 将两个饼状分区加入series
    QPieSeries *series = new QPieSeries(this);
    series->append(slice_1);
    series->append(slice_2);
    series->append(slice_3);
    chart= new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::AllAnimations); // 设置显示时的动画效果
   chartview = new QChartView(this);
    chartview->show();
    chartview->setChart(chart);
    ui->verticalLayout->insertWidget(0, chartview);
}
void form::getweight()
{
    if(chartview!=NULL)
    {
        delete chartview;
        chartview=NULL;
    }
    double t1,t2,t3,t4,t0;
    double sum=0;
    for(int i=0;i<5;i++)
    {
        sum+=weight[i];
    }
    t0=weight[0]/sum;
    t1=weight[1]/sum;
    t2=weight[2]/sum;
    t3=weight[3]/sum;
    t4=weight[4]/sum;
    QPieSlice *slice_0 = new QPieSlice(QStringLiteral("0至30"), t0, this);
    slice_0->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_0->setBrush(Qt::green);
    QPieSlice *slice_1 = new QPieSlice(QStringLiteral("30至60"), t1, this);
    slice_1->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_1->setBrush(Qt::blue);
    QPieSlice *slice_2 = new QPieSlice(QStringLiteral("60至90"), t2, this);
    slice_2->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_2->setBrush(Qt::yellow);
    QPieSlice *slice_3 = new QPieSlice(QStringLiteral("90至120"), t3, this);
    slice_3->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_3->setBrush(Qt::black);
    QPieSlice *slice_4 = new QPieSlice(QStringLiteral("120至150"), t4, this);
    slice_4->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_4->setBrush(QColor(200,10,10));
    QPieSeries *series = new QPieSeries(this);
    series->append(slice_1);
    series->append(slice_2);
    series->append(slice_3);
    series->append(slice_0);
    series->append(slice_4);
    chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::AllAnimations); // 设置显示时的动画效果
    chartview = new QChartView(this);
    chartview->show();
    chartview->setChart(chart);
    ui->verticalLayout->insertWidget(0, chartview);
}
void form::getdate()
{
    if(chartview!=NULL)
    {
        delete chartview;
        chartview=NULL;
    }
    double t0,t1,t2,t3;
    int sum=0;
    for(int i=0;i<4;i++)
        sum+=date[i];
    t0=date[0]/sum;
    t1=date[1]/sum;
    t2=date[2]/sum;
    t3=date[3]/sum;
    QPieSlice *slice_0 = new QPieSlice(QStringLiteral("第一季度"), t0, this);
    slice_0->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_0->setBrush(Qt::green);
    QPieSlice *slice_1 = new QPieSlice(QStringLiteral("第二季度"), t1, this);
    slice_1->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_1->setBrush(Qt::red);
    QPieSlice *slice_2 = new QPieSlice(QStringLiteral("第三季度"), t2, this);
    slice_2->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_2->setBrush(Qt::blue);
    QPieSlice *slice_3 = new QPieSlice(QStringLiteral("第四季度"), t3, this);
    slice_3->setLabelVisible(true); // 显示饼状区对应的数据label
    slice_3->setBrush(Qt::yellow);
    QPieSeries *series = new QPieSeries(this);
    series->append(slice_1);
    series->append(slice_2);
    series->append(slice_3);
    series->append(slice_0);
    chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::AllAnimations); // 设置显示时的动画效果
    chartview = new QChartView(this);
    chartview->show();
    chartview->setChart(chart);
    ui->verticalLayout->insertWidget(0, chartview);
}
form::~form()
{
    delete ui;
}
