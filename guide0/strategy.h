#ifndef STRATEGY_H
#define STRATEGY_H

#define INF INT_MAX - 1

#include "mymap.h"
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QVector>

struct Nav_node {
  QString name;
  map_node *cur_node;
  map_arc * cur_arc;
  struct Nav_node *next_node;
};
typedef Nav_node nav_node;

class strategy {
public:
  strategy();
  Nav_node*nav_head;//store strategy
  map_node* begin;
  map_node* end;
  int type;

  int SetOption(QString begin,QString end,QVector<map_node *> &loc_node);//设置成功 返回1 否则 返回0；
  void clearStra(map_node *head); //使地图中的strategy归零
void
  Min_dis_str(map_node *head,
              QVector<map_node *> &loc_node); //最短路径算法 使用dijkstra
void
  Min_time_str(map_node *head,
               QVector<map_node *> &loc_node); //最短时间算法 使用dijkstra
 static nav_node* Min_weight_str(map_node *head, int count, map_node *begin,
                           map_node *end, QVector<map_node *>const  &loc_node);
 void Min_with_transport(map_node *head,   QVector<map_node *> const &loc_node);
static  map_node *dij_find_next_node(map_node *head);
  map_node *find_sur(); //小诗写的bfs，查找周边
  void show_strategy_path();
  void delete_strategy_path();
};

#endif // STRATEGY_H
