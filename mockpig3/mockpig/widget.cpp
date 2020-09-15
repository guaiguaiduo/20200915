#include "widget.h"
#include "ui_widget.h"
using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <QPushButton>
#include <QDebug>
#include <mywidget.h>
#define random(a,b) (rand()%(b-a+1))+a
double money=200000;
int isp=0;
int ddays=0;
int psm,pdm;
double pwm;
int saleamount;
double sumprice;
int alldate[13];
int allweight[16];
int allspiece[4];
struct pig{
    int spiece;
    double weight;
    int days;
    pig *next;
    int ipig;
};
class pigcircle{
    private:
        int sum;
        int ifblack;
        int number;
        int is;
    public:
        pig *head;
        pigcircle();
        int getnumber();
        int getsum();
        int getifblack();
        int getis();
        void sendnumber(int i);
        void sendsum(int i);
        void sendifblack(int i);
        void sendis(int i);
        int  searchspiece(int i);
        int  searchdays(int i);
        double searchweight(int i);
        void sale();
        void insert(pig *p);
};
pigcircle::pigcircle()
{
    sum=0;
    ifblack=0;
    number=0;
    is=0;
}
int pigcircle::getsum()
{
    return sum;
 }
int pigcircle::getnumber()
{
    return number;
}
int pigcircle::getifblack()
{
    return ifblack;
}
int pigcircle::getis()
{
    return is;
}
void pigcircle::sendis(int i)
{
    is=i;
}
void pigcircle::sendnumber(int i)
{
    number=i;
}
void pigcircle::sendifblack(int i)
{
    ifblack=i;
}
void pigcircle::sendsum(int i)
{
    sum=i;
}
int pigcircle::searchspiece(int i)
{
    if(i>sum) return -1;
    int j;
    pig *p=head;
    for(j=1;j<i;j++)
    p=p->next;
    return p->spiece;
}
double pigcircle::searchweight(int i)
{
    if(i>sum) return -1;
    int j;
    pig *p=head;
    for(j=1;j<i;j++)
    p=p->next;
    return p->weight;
}
int pigcircle::searchdays(int i)
{
    if(i>sum) return -1;
    int j;
    pig *p=head;
    for(j=1;j<i;j++)
    p=p->next;
    return p->days;
}
void initial(pigcircle pc[])
{
    srand(time(NULL));
    int i,j;
    pig *p,*q;
    for(i=1;i<=100;i++)
    {
        pc[i].head=NULL;
        pc[i].sendsum(5);
        pc[i].sendnumber(i);
        if(i<=30)
        {
            pc[i].sendifblack(1);
            for(j=1;j<=5;j++)
            {
            p=new pig;
            p->spiece=1;
            p->weight=(random(200,500))/10.0;
            p->days=0;
            p->ipig=0;
            p->next=NULL;
            if(pc[i].head==NULL)
            pc[i].head=p;
            else
            q->next=p;
            q=p;
        }
        }
        else
        {
            pc[i].sendifblack(0);
            for(j=1;j<=5;j++)
            {
            p=new pig;
            p->spiece=random(2,3);
            p->weight=(random(200,500))/10.0;
            p->days=0;
            p->next=NULL;
            if(pc[i].head==NULL)
            pc[i].head=p;
            else
            q->next=p;
            q=p;
        }
        }
    }
}
int ba,bba,sba;
int pigcirclestatistics(int t,pigcircle pc[])
{
    int j,t1=0,t2=0;
    pig *p=pc[t].head;
    ba=bba=sba=0;
    int ifblack1=pc[t].getifblack();
    if(ifblack1==1)
    {
    ba=pc[t].getsum();
    return 1;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->spiece==2)
            t1+=1;
            else
            t2+=1;
            p=p->next;
        }
        bba=t1;sba=t2;
        return 2;
    }
}
int amount(pigcircle pc[])
{
    int i,sum=0;
    for(i=1;i<=100;i++)
    {
        sum+=pc[i].getsum();
    }
    return sum;
}
void allmember(pigcircle pc[])
{
    memset(allspiece,0,sizeof(allspiece));
    memset(alldate,0,sizeof(alldate));
    memset(allweight,0,sizeof(allweight));
    int i,sum,j,t;
    for(i=1;i<=100;i++)
    {
        sum=pc[i].getsum();
        for(j=1;j<=sum;j++)
        {
            allspiece[pc[i].searchspiece(j)]++;
            alldate[(pc[i].searchdays(j)/91)]++;
            allweight[int(pc[i].searchweight(j)/31)]++;
        }
    }
}
void randomifs(pigcircle pc[])
{
    if(isp==0) return;
    pig *p1=NULL;
    int sum,is1,is2,is,j,c;
    for(int t=1;t<=100;t++)
    {
        is=pc[t].getis();
        sum=pc[t].getsum();
        if(sum==0||sum==is)  continue;
        else if(is>0)
        {
          p1=pc[t].head;
          for(j=1;j<=sum;j++)
          {
            if(p1->ipig==0)
            {
                c=random(1,100);
                if(c<=50)
                {
                    p1->ipig=1;
                    is++;
                    ++isp;
                }
            }
            p1=p1->next;
          }
        }
        else if(is==0&&sum>0)
        {
            if(t-1>0) is1=pc[t-1].getis();
            else is1=0;
            if(t+1<=100) is2=pc[t+1].getis();
            else is2=0;
            if(is2>0||is1>0)
            {
                p1=pc[t].head;
                for(j=1;j<=sum;j++)
                {
                    c=random(1,100);
                    if(c<=15)
                    {
                        is++;
                        ++isp;
                        p1->ipig=1;
                    }
                        p1=p1->next;
                }
            }
        }
        pc[t].sendis(is);
    }
}
void allupping(pigcircle pc[])
{
    srand(time(NULL));
    int i;
    pig *p;
    for(i=1;i<=100;i++)
    {
    p=pc[i].head;
    while(p!=NULL)
    {
        p->days+=1;
        p->weight+=(random(0,12))/10.0;
        p=p->next;
    }
    }
    if(isp==0) return;
    else
    randomifs(pc);
}
void outFile(pigcircle pc[])
{
    ofstream destFile("pigsmessage.txt",ios::out);
    int i,j,sum;
    pig *p,*p1;
    for(i=1;i<=100;i++)
    {
        p=pc[i].head;
        sum=pc[i].getsum();
        destFile<<pc[i].getnumber()<<endl<<sum<<endl;
        for(j=1;j<=sum;j++)
        {
            destFile<<p->spiece<<' '<<p->weight<<' '<<p->days<<endl;
            p1=p;
            p=p->next;
            delete p1;
        }
        pc[i].head=NULL;
    }
     destFile.close();
}
void inFile(pigcircle pc[])
{

    ifstream srcFile("pigsmessage.txt",ios::in);
    pig *p1,*q;
    int i,j,sum,t;
    for(i=1;i<=100;i++)
    {
        srcFile>>t;
        pc[i].sendnumber(t);
        srcFile>>t;
        sum=t;
        pc[i].sendsum(t);
        for(j=1;j<=sum;j++)
        {
            p1=new pig;
            p1->next=NULL;
            srcFile>>p1->spiece>>p1->weight>>p1->days;
            if(pc[i].head==NULL)  pc[i].head=p1;
            else         q->next=p1;
            q=p1;
        }
        q->next=NULL;
    }
    srcFile.close();
}
void pigcircle::sale()
{
    int i=1,t=0;
    pig *p=head,*p1=NULL,*p2=NULL;
    p1=head;
    if(head==NULL) return;
        for(;i<=sum;i++)
    {
        if(p->weight>75||p->days>360)
        {
            if(p->ipig==1)
            money-=100000;
          if(p->spiece==1)
            sumprice+=p->weight*15;
           else if(p->spiece==2)
           sumprice+=p->weight*7;
           else
           sumprice+=p->weight*6;
           saleamount++;
           if(p==head)
           {
            p=p->next;
            p1=p;
            head=p;
           }
           else
           {
            p2=p;
            p1->next=p->next;
            p=p->next;
            delete p2;
            p2=NULL;
           }
            t++;
        }
        else
        {
         p1=p;
         p=p->next;
        }
    }
    sum-=t;
}
void saleall(pigcircle pc[])
{
    int i;
    saleamount=sumprice=0;
    for(i=1;i<=100;i++)
    pc[i].sale();
    if(saleamount==0) return;
    money+=sumprice;
    ofstream destFile("buyandsale.txt",ios::app);
    destFile<<"sale"<<endl<<' '<<ddays<<endl<<"销售数目为： "<<saleamount<<endl<<"销售总额为： "<<sumprice<<endl;
    destFile.close();
}
int buypigs(pigcircle pc[],int bp,int wp,int sp)
{
    srand(time(NULL));
    ofstream destFile("buyandsale.txt",ios::app);
    destFile<<"买入"<<endl<<"black pig"<<' '<<bp<<endl<<"big white big"<<' '<<wp<<endl<<"samll white pig"<<' '<<sp<<endl;
    destFile.close();
    int i,sum=0,ave,gs,fg,j;
    pig *p=NULL,*np=NULL,*p1=NULL;
    for(i=1;i<31;i++)
    sum+=pc[i].getsum();
    sum+=bp;
    int d;
    if(sum>300) return 0;
    ave=sum/30+1;
    int is;
    for(i=1;i<31&&bp!=0;i++)
    {
        if(sum==0) break;
        gs=pc[i].getsum();
        if(gs>=ave) continue;
        p=pc[i].head;
         for(j=gs+1;j<=ave&&bp!=0;j++)
         {
            np=new pig;
            np->spiece=1;
            np->weight=(random(200,500))/10.0;
            money-=np->weight*15*0.7;
            np->days=0;
            d=random(1,10);
            if(d<=10)
            {
                isp++;
                np->ipig=1;
                is=pc[i].getis();is++;
                pc[i].sendis(is);
            }
            else
            np->ipig=0;
            np->next=NULL;
            if(pc[i].head==NULL)
            {
            pc[i].head=np;
            }
            else
            {
                np->next=pc[i].head;
                pc[i].head=np;
            }
            --bp;
            gs++;
                     }
         pc[i].sendsum(gs);
     }
    for(sum=0,i=31;i<=100;i++)
    sum+=pc[i].getsum();
    sum+=wp+sp;
    int ap=wp+sp;
    if(sum>700) return 0;
    ave=sum/70+1;
    for(i=31;i<=100&&ap!=0;i++)
    {
        if(sum==0) break;
        gs=pc[i].getsum();
        if(gs>=ave) continue;
        p=pc[i].head;
        for(j=1;j<gs;j++)
        p=p->next;
         for(j=gs+1;j<=ave&&ap!=0;j++)
         {
            np=new pig;
            np->spiece=random(2,3);
            np->weight=(random(200,500))/10.0;
            money-=np->weight*7*0.7;
            np->days=0;
            np->next=NULL;
            d=random(1,10);
            if(d<=10)
            {
                isp++;
                np->ipig=1;
                is=pc[i].getis();is++;
                pc[i].sendis(is);
            }
            else
            np->ipig=0;
            if(p==NULL)
            p=np;
            else
            p->next=np;
            p=p->next;
            --ap;
            gs++;
         }
         pc[i].sendsum(gs);
     }
     return 1;
}
int isf(int i,int p,pigcircle pc[])
{
    srand(time(NULL));
     int isamount=1,d=0;
    int j,sum,c,flag,is,is1,is2,t;
    pig *p1;
    p1=pc[i].head;
    sum=pc[i].getsum();
    pc[i].sendis(1);
    int all=amount(pc);
    for(j=1;j<sum;j++)
    {
    p1=p1->next;
    }
    p1->ipig=1;
    int u=all-20;
    while(isamount<u)
    {
    for(t=i;t>=0;t--)
    {
        is=pc[t].getis();
        sum=pc[t].getsum();
        if(sum==0||sum==is)  continue;
        else if(is>0)
        {
          p1=pc[t].head;
          for(j=1;j<=sum;j++)
          {
            if(p1->ipig==0)
            {
                c=random(1,100);
                if(c<=50)
                {
                    p1->ipig=1;
                    is++;
                    isamount++;
                }
            }
            p1=p1->next;
          }
        }
        else if(is==0&&sum>0)
        {
            if(t-1>0) is1=pc[t-1].getis();
            else is1=0;
            is2=pc[t+1].getis();
            if(is2>0||is1>0)
            {
                p1=pc[t].head;
                for(j=1;j<=sum;j++)
                {
                    c=random(1,100);
                    if(c<=15)
                    {
                        is++;
                        isamount++;
                        p1->ipig=1;
                    }
                        p1=p1->next;
                }
            }
        }
        pc[t].sendis(is);
    }
    for(t=i+1;t<=100;t++)
    {
        is=pc[t].getis();
        sum=pc[t].getsum();
        if(sum==0||sum==is)  continue;
        else if(is>0)
        {
          p1=pc[t].head;
          for(j=1;j<=sum;j++)
          {
            if(p1->ipig==0)
            {
                c=random(1,100);
                if(c<=50)
                {
                    p1->ipig=1;
                    is++;
                    isamount++;
                }
            }
            p1=p1->next;
          }
        }
        else if(is==0&&sum>0)
        {
            if(t+1<=100) is2=pc[t+1].getis();
            else is2=0;
            is1=pc[t-1].getis();
            if(is1>0||is2>0)
            {
                p1=pc[t].head;
                for(j=1;j<=sum;j++)
                {
                    c=random(1,100);
                    if(c<=15)
                    {
                        is++;
                        p1->ipig=1;
                        isamount++;
                    }
                        p1=p1->next;
                }
            }
        }
        pc[t].sendis(is);
    }
    d++;
}
return d;
}
int check(pigcircle pc[])
{
    int i,j,sum,is;
    pig *p=NULL,*p1=NULL,*p2=NULL;
    int isp1=isp;
    for(i=1;i<=100&&isp!=0;i++)
    {
        is=pc[i].getis();
        if(is==0) continue;
        p=pc[i].head;
        p1=p;
        for(j=1;j<=sum&&is!=0;j++)
        {
        if(p->ipig==1)
        {
            if(p==pc[i].head)
           {
            p=p->next;
            p1=p;
            pc[i].head=p;
           }
           else
           {
            p2=p;
            p1->next=p->next;
            p=p->next;
            delete p2;
            p2=NULL;
           }
           isp--;
        }
        else
        {
         p1=p;
         p=p->next;
        }
        }

    }
    int all=amount(pc);
    return all*100;
}
pigcircle pc[101];
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap(":/new/prefix1/3d35aae7a10f19ec770314214219ee50.jpg");
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);
    ui->File->hide();ui->in->hide();ui->out->hide();ui->S->hide();ui->s1->hide();ui->s2->hide();
    ui->bs->hide();ui->buy->hide();ui->ing->hide();ui->pushButton->hide();ui->bb->hide();
    ui->sure->hide();ui->textBrowser->show();ui->textBrowser_2->show();ui->textBrowser_3->show();
    ui->b1->show();ui->pp->hide();ui->cd->show();ui->b3->hide();ui->return_2->hide();ui->pushButton_2->hide();ui->textBrowser_4->show();
    connect(ui->pushButton,&QPushButton::clicked,
            [=]()
    {
        ui->textBrowser->setText("成功进入界面中，请在执行操作前，输入相应数据并摁下确认键");
        ui->File->hide();ui->in->hide();ui->out->hide();ui->S->hide();ui->s1->hide();ui->s2->hide();
        ui->bs->hide();ui->buy->hide();ui->ing->hide();ui->pushButton->hide();ui->bb->hide();
        ui->sure->show();ui->textBrowser->show();ui->textBrowser_2->show();ui->textBrowser_3->show();
        ui->b1->hide();ui->pp->show();ui->cd->show();ui->b3->show();ui->return_2->hide();ui->pushButton_2->show();ui->textBrowser_4->show();
    });
    connect(ui->cd,&QPushButton::clicked,
            [=]()
    {
        setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":/new/prefix1/3d35aae7a10f19ec770314214219ee50.jpg");
        palette.setBrush(backgroundRole(),QBrush(pixmap));
        this->setPalette(palette);
        ui->File->show();ui->in->hide();ui->out->hide();ui->S->show();ui->s1->hide();ui->s2->hide();
        ui->bs->show();ui->buy->hide();ui->ing->hide();ui->pushButton->show();ui->bb->show();
        ui->sure->hide();ui->textBrowser->hide();ui->textBrowser_2->hide();ui->textBrowser_3->hide();ui->textBrowser_4->hide();
        ui->b1->hide();ui->pp->hide();ui->cd->hide();ui->b3->hide();ui->return_2->show();ui->pushButton_2->hide();ui->textBrowser_4->hide();
    });

    connect(ui->File,&QPushButton::clicked,
            [=]()
{
        setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":/new/prefix1/3d35aae7a10f19ec770314214219ee50.jpg");
        palette.setBrush(backgroundRole(),QBrush(pixmap));
        this->setPalette(palette);
        ui->textBrowser->setText("成功进入界面中，请在执行操作前，输入相应数据并摁下确认键");
        ui->File->hide();ui->in->show();ui->out->show();ui->S->hide();ui->s1->hide();ui->s2->hide();
        ui->bs->hide();ui->buy->hide();ui->ing->hide();ui->pushButton->hide();ui->bb->hide();
        ui->sure->hide();ui->textBrowser->show();ui->textBrowser_2->show();ui->textBrowser_3->show();
        ui->b1->hide();ui->pp->hide();ui->cd->show();ui->b3->hide();ui->return_2->hide();ui->pushButton_2->hide();ui->textBrowser_4->show();
    });
    connect(ui->bs,&QPushButton::clicked,
            [=]()
    {
        setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":/new/prefix1/3d35aae7a10f19ec770314214219ee50.jpg");
        palette.setBrush(backgroundRole(),QBrush(pixmap));
        this->setPalette(palette);
        ui->textBrowser->setText("成功进入界面中，请在执行操作前，输入相应数据并摁下确认键");
        ui->File->hide();ui->in->hide();ui->out->hide();ui->S->hide();ui->s1->hide();ui->s2->hide();
        ui->bs->hide();ui->buy->show();ui->ing->show();ui->pushButton->hide();ui->bb->hide();
        ui->sure->show();ui->textBrowser->show();ui->textBrowser_2->show();ui->textBrowser_3->show();
        ui->b1->hide();ui->pp->show();ui->cd->show();ui->b3->hide();ui->return_2->hide();ui->pushButton_2->hide();ui->textBrowser_4->show();
    });
    connect(ui->S,&QPushButton::clicked,
            [=]()
    {
        setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":/new/prefix1/3d35aae7a10f19ec770314214219ee50.jpg");
        palette.setBrush(backgroundRole(),QBrush(pixmap));
        this->setPalette(palette);
        ui->textBrowser->setText("成功进入界面中，请在执行操作前，输入相应数据并摁下确认键");
        ui->File->hide();ui->in->hide();ui->out->hide();ui->S->hide();ui->s1->show();ui->s2->show();
        ui->bs->hide();ui->buy->hide();ui->ing->hide();ui->pushButton->hide();ui->bb->hide();
        ui->sure->show();ui->textBrowser->show();ui->textBrowser_2->show();ui->textBrowser_3->show();
        ui->b1->hide();ui->pp->show();ui->cd->show();ui->b3->hide();ui->return_2->hide();ui->pushButton_2->hide();ui->textBrowser_4->show();
    });
    connect(ui->return_2,&QPushButton::clicked,
            [=]()
    {
        ui->textBrowser->setText("成功返回主页面，请选择希望进行的操作");
        ui->File->hide();ui->in->hide();ui->out->hide();ui->S->hide();ui->s1->hide();ui->s2->hide();
        ui->bs->hide();ui->buy->hide();ui->ing->hide();ui->pushButton->hide();ui->bb->hide();
        ui->sure->hide();ui->textBrowser->show();ui->textBrowser_2->show();ui->textBrowser_3->show();ui->pushButton_2->hide();
        ui->b1->show();ui->pp->hide();ui->cd->show();ui->b3->hide();ui->return_2->hide();ui->textBrowser_4->show();
        setAutoFillBackground(true);
        QPalette palette;
        QPixmap pixmap(":/new/prefix1/3d35aae7a10f19ec770314214219ee50.jpg");
        palette.setBrush(backgroundRole(),QBrush(pixmap));
        this->setPalette(palette);
    });
    connect(ui->sure,&QPushButton::clicked,
            [=]()
    {
        ui->textBrowser->setText("输入成功，请点击所需要的按键");
    }
            );
    connect(ui->b1,&QPushButton::clicked,
            [=]()
    {
        initial(pc);
        QString str5;
        int a=amount(pc);
        str5=QString("当前猪数为： %1").arg(a);
        ui->textBrowser_2->setText(str5);
        str5=QString("当前的天数为： %1").arg(ddays);
        ui->textBrowser_3->setText(str5);
        ui->textBrowser->setText("初始化成功\n");
        str5=QString("当前金钱为： %1").arg(money);
        ui->textBrowser_4->setText(str5);
    }
            );
    connect(ui->b3,&QPushButton::clicked,
            [=]()
    {

        int t1=0,t2=0,flag;
        QString str=ui->pp->toPlainText();
        for(int i=0,flag=0;i<str.length();i++)
        {
            if(flag==0&&str.at(i)>='0'&&str.at(i)<='9')
                t1=t1*10+str.at(i).toLatin1()-'0';
            else if(flag==1&&str.at(i)>='0'&&str.at(i)<='9')
            {
                t2=str.at(i).toLatin1()-'0';
            }
              else if(str.at(i)<'0'||str.at(i)>'9')
            {
                      if(flag==0)  flag=1;
                      else break;
            }
        }
         int d=isf(t1,t2,pc);
         str=QString("感染全部的猪所需要的的天数为： %1").arg(d);
         ui->textBrowser->setText(str);
    }
           );
     connect(ui->s2,&QPushButton::clicked,
           [=]()
    {
      int a=0,b=0,flag=0;
      QString str=ui->pp->toPlainText();
      for(int i=0;i<str.length();i++)
      {
          if(str.at(i)<'0'||str.at(i)>'9')
          {
              flag=1;
              continue;
          }
          else if(str.at(i)>='0'&&str.at(i)<='9'&&flag==0)
              {
              a=a*10+str.at(i).toLatin1()-'0';
              }
         else if(str.at(i)>='0'&&str.at(i)<='9'&&flag==1)
          {
              b=b*10+str.at(i).toLatin1()-'0';
          }
      }
      QString str1,str2;
     int d1=pc[a].searchspiece(b);
     double d2=pc[a].searchweight(b);
     int d3=pc[a].searchdays(b);

     if(d1<=0)
     {
     str1=QString("这是一个不合法的输入，请按照规则输入符合的数字\n");
     ui->textBrowser->setText(str1);
     }
     else
     {
       ui->textBrowser->setText("这是一个合法的输入");
       if(d1==1) str2="黑猪";
       else if(d1==2)  str2="大花白猪";
       else  str2="小花白猪";
       str1=QString("这是一个合法的输入，当前搜索的猪信息如下：\n品种为： %1\n体重为： %2\n在猪圈的天数为： %3\n").arg(str2).arg(d2).arg(d3);
       ui->textBrowser->setText(str1);
     }
    }
            );
     connect(ui->s1,&QPushButton::pressed,
             [=]()
     {
         int a=0;
         QString str;
         QString str1;
         str=ui->pp->toPlainText();
         for(int i=0;i<str.length();i++)
         {
             a=str.at(i).toLatin1()-'0'+a*10;
         }
         if(a>100)
         {
             str1=QString("这是一个非法输出，请重新输入希望搜索的猪圈序号\n");
             ui->textBrowser->setText(str1);
         }
         else
         {
         int d=pigcirclestatistics(a,pc);
         if(d==1)
         {
             str1=QString("所搜索的猪圈为黑猪圈\n黑猪的数目为：  %1").arg(ba);
             ui->textBrowser->setText(str1);
         }
         else if(d==2)
         {
             str1=QString("所搜索的猪圈为混合猪圈\n当前大花白猪数目为：  %1\n当前小花白猪的数目为: %2").arg(bba).arg(sba);
             ui->textBrowser->setText(str1);
         }
         }
     }
             );

      connect(ui->out,&QPushButton::clicked,
              [=]()
      {
          ui->textBrowser->setText("将当前猪的信息存入pigsmessage中\n");
          outFile(pc);
      });
      connect(ui->in,&QPushButton::clicked,
              [=]()
      {
          ui->textBrowser->setText("将存储在pigsmessage中取出\n");
          inFile(pc);
      }
              );
      connect(ui->ing,&QPushButton::clicked,
              [=]()
      {
          int d=0;
          QString str=ui->pp->toPlainText();
          for(int i=0;i<str.length();i++)
          {
              d=d*10+str.at(i).toLatin1()-'0';
          }
          for(int i=1;i<=d;i++)
          {
              allupping(pc);
              saleall(pc);
          }
          int e=amount(pc);
          QString str1;
          str1=QString("当前猪数为： %1").arg(e);
          ui->textBrowser_2->setText(str1);
          ddays=ddays+d;
          str1=QString("当前天数为： %1").arg(ddays);
          ui->textBrowser_3->setText(str1);
          if(money<=0)
          {ui->textBrowser->setText("猪猪公司破产了，恭喜你游戏失败^_^\n");
              money=0;
          }
           str=QString("当前金钱为： %1").arg(money);
          ui->textBrowser_4->setText(str);
      }
              );
      connect(ui->buy,&QPushButton::clicked,
              [=]()
      {
           int t1=0,t2=0,t3=0,flag;
           ui->textBrowser->setText("买猪成功");
          QString str=ui->pp->toPlainText();
           for(int i=0,flag=0;i<str.length();i++)
           {
               if(flag==0)
               {
                   if(str.at(i)<'0'||str.at(i)>'9')
                   {
                       flag=1;continue;
                   }
                   t1=t1*10+str.at(i).toLatin1()-'0';
               }
               else if(flag==1)
               {
                   if(str.at(i)<'0'||str.at(i)>'9')
                   {
                       flag=2;continue;
                   }
                   t2=t2*10+str.at(i).toLatin1()-'0';
               }
               else if(flag==2)
               {
                   if(str.at(i)<'0'||str.at(i)>'9') continue;
                   t3=t3*10+str.at(i).toLatin1()-'0';
               }
           }
           str=QString("本次买猪，共买\n黑猪： %1\n大花白猪： %2\n小花白猪： %3\n").arg(t1).arg(t2).arg(t3);
           ui->textBrowser->setText(str);
           buypigs(pc,t1,t2,t3);
           int sum=amount(pc);
           str=QString("当前猪数为： %1").arg(sum);
          ui->textBrowser_2->setText(str);
          if(money<=0)
          {ui->textBrowser->setText("猪猪公司破产了，恭喜你游戏失败^_^\n");
              money=0;
          }
           str=QString("当前金钱为： %1").arg(money);
          ui->textBrowser_4->setText(str);
      });
      h.hide();
      connect(ui->bb,&QPushButton::clicked,
              [=]()
      {
          allmember(pc);
          h.getnumber(allspiece[1],allspiece[2],allspiece[3],alldate,allweight);
          h.show();
      });
      connect(ui->pushButton_2,&QPushButton::clicked,
              [=]()
      {
          int d=check(pc);
          money-=d;
          QString str;
          str=QString("对整个猪圈的猪体检完成\n");
          ui->textBrowser->setText(str);
          if(money<=0)
          {ui->textBrowser->setText("猪猪公司破产了，恭喜你游戏失败^_^\n");
              money=0;
          }
           str=QString("当前金钱为： %1").arg(money);
          ui->textBrowser_4->setText(str);
      });
}
Widget::~Widget()
{
    delete ui;
}
