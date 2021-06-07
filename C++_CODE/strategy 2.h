#ifndef STRATEGY_H
#define STRATEGY_H

#define INF INT_MAX -1

#include<QDebug>
#include<QVector>
#include<QString>
#include <QTextStream>
#include<QDebug>
#include"mymap.h"


struct Nav_node{
    QString name;
    map_node* cur_node;
    struct Nav_node * next_node;
};
typedef Nav_node nav_node;

class strategy
{
public:
    strategy();

    void clearStra(map_node* head);//使地图中的strategy归零
    nav_node* Min_dis_str(map_node * head,int count,map_node* begin,map_node* end,QVector<map_node*>loc_node);//最短路径算法 使用dijkstra
    nav_node *Min_time_str(map_node * head,int count,map_node* begin,map_node* end,QVector<map_node*>loc_node);//最短时间算法 使用dijkstra
    nav_node * Min_weight_str(map_node * head,int count,map_node* begin,map_node* end,QVector<map_node*>loc_node);
    //void Min_distance_through_node(map_node*head,vector<map_node*>through_node,map_node* begin,map_node* end);//算法已经弄清楚了 实现有点复杂 在后续版本中实现
    nav_node *Min_with_transport(map_node * head,int count,map_node* begin,map_node* end,QVector<map_node*>loc_node);
    map_node * dij_find_next_node(map_node* head);
    void show_strategy_path(nav_node* head);
    void delete_strategy_path(nav_node *head);
};

#endif // STRATEGY_H
