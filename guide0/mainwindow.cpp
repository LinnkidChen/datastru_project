//#include "mainwindow.h"
//#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "guidescene.h"
#include "ui_guidescene.h"
#include"mymap.h"
#include"strategy.h"
#include<mypushbutton.h>
#include<QPainter>
#include"guidescene.h"
#include<QTimer>
#include<QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,900);//设置大小

    this->setWindowTitle("北京邮电大学导航系统");//设置标题

    this->setWindowIcon(QPixmap(":/Image/bupticon.png"));//设置图标

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/Image/startbutton.png");
    startBtn->setParent(this);
    startBtn->move(550,680);

    //导航界面
    guidescene *Guidescene = new guidescene;
    connect(startBtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=]()
        {

            this->hide();//自身隐藏
            Guidescene->show();//显示导航系统场景
        });
    });

    //点击返回按钮返回主界面
    connect(Guidescene,&guidescene::chooseSceneBack,this,[=](){
        Guidescene->hide();
        this->show();
    });

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/bupt.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
