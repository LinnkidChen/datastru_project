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
strategy stra;
stra.clearStra(map1.map_head);
stra.delete_strategy_path();
stra.SetOption("work","home",map1.loc_node);
stra.Min_dis_str(map1.map_head,map1.loc_node);
stra.show_strategy_path();

//    return a.exec();
return 0;
}
