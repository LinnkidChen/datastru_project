#include "guidescene.h"
#include "ui_guidescene.h"
#include"mainwindow.h"
#include"ui_mainwindow.h"
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>

guidescene::guidescene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guidescene)
{
    ui->setupUi(this);
    this->setFixedSize(1200,900);//设置大小

    this->setWindowTitle("北京邮电大学导航系统");//设置标题

    this->setWindowIcon(QPixmap(":/Image/bupticon.png"));//设置图标

    //设置返回按钮
    MyPushButton * backbtn = new MyPushButton(":/Image/backbutton.png",":/Image/backbutton1.png");
    backbtn->setStyleSheet("QPushButton{border:0px;}");
    backbtn->setParent(this);
    backbtn->move(900,800);

    //点击返回
    connect(backbtn,&MyPushButton::clicked,[=](){
        //延时返回
        QTimer::singleShot(500,this,[=](){
        emit this->chooseSceneBack();

        });
    });
    QDateTime curDateTime=QDateTime::currentDateTime();
    ui->dateTimeEdit->setTime(curDateTime.time());
}

guidescene::~guidescene()
{
    delete ui;
}

void guidescene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/map.png");
    painter.drawPixmap(0,0,this->width()*0.7,this->height(),pix);
//    QPainter painter1(this);
//    painter1.setPen(QPen(Qt::red,7));
//    painter1.drawLine(900,300,900,500);
}





