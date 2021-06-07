#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>

MyPushButton::MyPushButton(QString normalImg, QString pressImg )
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;

    QPixmap pix;
    bool ret = pix.load(normalImg);
    if(!ret)
    {
       qDebug() << "图片加载失败";
       return;
    }

    //设置图片固定大小
    this->setFixedSize( pix.width(),pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "") //传入的按下图片不为空 说明需要有按下状态，切换图片
    {
        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret)
        {
           qDebug() << "图片加载失败";
           return;
        }

        //设置图片固定大小
        this->setFixedSize( pix.width(),pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));

    }

    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "") //传入的按下图片不为空 说明需要有按下状态，切换成初始图片
    {
        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
           qDebug() << "图片加载失败";
           return;
        }

        //设置图片固定大小
        this->setFixedSize( pix.width(),pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));

    }

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);

}
