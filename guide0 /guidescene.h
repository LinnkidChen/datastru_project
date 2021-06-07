#ifndef GUIDESCENE_H
#define GUIDESCENE_H

#include <QMainWindow>

namespace Ui {
class guidescene;
}

class guidescene : public QMainWindow
{
    Q_OBJECT

public:
    explicit guidescene(QWidget *parent = 0);
    ~guidescene();

    void paintEvent(QPaintEvent *);//重写绘图，设置背景

private:
    Ui::guidescene *ui;
signals:
    //写一个自定义信号,点击返回
    void chooseSceneBack();
};

#endif // GUIDESCENE_H
