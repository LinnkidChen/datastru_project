#include "mainwindow.h"
#include"mymap.h"
#include"strategy.h"
#include <QApplication>

int main()
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
mymap map1;
map1.init_map("matrix.txt");
map1.showMap();

//    return a.exec();
return 0;
}
