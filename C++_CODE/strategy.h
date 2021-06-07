/*struct Map_node{
    string name;//one side of arc

    struct Map_node * next_node;
    struct Map_arc * next_arc;

    struct Map_node * next_node_nav;//用于储存导航策略的下一个节点

};
struct Map_arc{
    string name;//the other side of arc
    int  density;
    int  distance;// travel time = density*distance/speed


    struct Map_arc* next_arc;

    int weight;
};
typedef struct Map_node map_node;
typedef struct Map_arc map_arc;*/
#ifndef STRATEGY_H
#define STRATEGY_H
#include "map.h"

#define INF INT_MAX - 1

//约定：当某条边因为某种原因不参与最短权重的路径搜索（如不能通自行车），weight设置为0（或者INF？）,

struct Nav_node {
  string name;
  map_node *cur_node;
  unsigned int time_to_next_node;
  struct Nav_node *next_node;
}; //用于储存策略路径的链表结构
typedef Nav_node nav_node;

void clearStra(map_node *head); //使地图中的strategy有关部分恢复默认值
//或许不同策略的算法选择可以优化为使用switch和枚举的分支结构
nav_node *Min_dis_str(map_node *head, int count, map_node *begin, map_node *end,
                      vector<map_node *> loc_node); //最短路径算法 使用dijkstra
nav_node *Min_time_str(map_node *head, int count, map_node *begin,
                       map_node *end,
                       vector<map_node *> loc_node); //最短时间算法 使用dijkstra
// void
// Min_distance_through_node(map_node*head,vector<map_node*>through_node,map_node*
// begin,map_node* end);//算法已经弄清楚了 实现有点复杂 在后续版本中实现
nav_node *Min_with_transport(
    map_node *head, int count, map_node *begin, map_node *end,
    vector<map_node *> loc_node); //最短骑单车的距离算法，使用dijkstra

nav_node *Min_weight_str(
    map_node *head, int count, map_node *begin, map_node *end,
    vector<map_node *> loc_node); //通过weight值来寻找weight_sum最短的路径
map_node *dij_find_next_node(
    map_node *
        head); // dijstra算法中，寻找没访问过的，且目前从起点到该点距离最短的点。
void show_strategy_path(nav_node *head);   //打印策略路径
void delete_strategy_path(nav_node *head); //删除释放策略路径
void clearStra(map_node *head) {
  map_arc *temp;
  while (head) {
    temp = head->next_arc;
    while (temp) {
      temp->weight = 0;
      temp = temp->next_arc;
    }
    head->nav_visited = false;
    head->sum_weight = INF;
    head = head->next_node;
  }
}
nav_node *Min_dis_str(map_node *head, int count, map_node *begin, map_node *end,
                      vector<map_node *> loc_node) {
  //使weight初始化为distance
  map_arc *temp_arc = NULL;
  map_node *temp_node = NULL;
  temp_node = head;
  while (temp_node) {
    temp_arc = temp_node->next_arc;
    while (temp_arc) {
      temp_arc->weight = temp_arc->distance;
      temp_arc = temp_arc->next_arc;
    }
    temp_node->nav_visited = false;
    temp_node = temp_node->next_node;
  }
  // return NULL;
  return Min_weight_str(head, count, begin, end, loc_node);
}
nav_node *Min_time_str(map_node *head, int count, map_node *begin,
                       map_node *end, vector<map_node *> loc_node) {
  //使weight初始化为distance*density
  map_arc *temp;
  while (head) {
    temp = head->next_arc;
    while (temp) {
      temp->weight = temp->distance * temp->density;
      temp = temp->next_arc;
    }
    head->nav_visited = false;
    head = head->next_node;
  }

  return Min_weight_str(head, count, begin, end, loc_node);
}
nav_node *Min_weight_str(map_node *head, int count, map_node *begin,
                         map_node *end, vector<map_node *> loc_node) {
  nav_node *nav_head;
  nav_head = new nav_node; //记录路径返回

  map_node *temp_path[count]; //记录每个起始节点到每个其他节点的路径

  // dijstra
  map_node *pcur_node;
  map_arc *pcur_arc;
  int cur_weight_sum;
  pcur_node = end;
  end->sum_weight = 0;

  for (int i = 0; i < count; i++) {
    pcur_arc = pcur_node->next_arc;

    while (pcur_arc) {

      cur_weight_sum = pcur_node->sum_weight + pcur_arc->weight;
      if ((cur_weight_sum < pcur_arc->arc_node->sum_weight) &&
          pcur_arc != 0) { //如果途经当前节点的路径比原路径更短
        pcur_arc->arc_node->sum_weight = cur_weight_sum;
        temp_path[pcur_arc->arc_node->number] = pcur_node;
      }
      pcur_arc = pcur_arc->next_arc;
    }
    pcur_node->nav_visited = true;
    pcur_node = dij_find_next_node(head);
    if (pcur_node == begin)
      break;
  }

  nav_head->name = begin->name;
  nav_head->cur_node = begin;

  nav_node *pcur_nav_node;
  pcur_nav_node = nav_head;
  for (int i = 0;
       (i < count && temp_path[pcur_nav_node->cur_node->number] != end);
       i++) { //防止死循环
    pcur_nav_node->next_node = new nav_node;
    pcur_nav_node->next_node->cur_node =
        temp_path[pcur_nav_node->cur_node->number];
    pcur_nav_node = pcur_nav_node->next_node;
    pcur_nav_node->name = pcur_nav_node->cur_node->name;
  }
  pcur_nav_node->next_node = new nav_node;
  pcur_nav_node->next_node->name = end->name;
  pcur_nav_node->next_node->cur_node = end;
  pcur_nav_node->next_node->next_node = NULL;

  return nav_head;
}
map_node *dij_find_next_node(map_node *head) {
  map_node *temp;
  int min_weight;
  if (head)
    min_weight = head->sum_weight;
  // cout<<"111\n";
  temp = head;

  while (head) {
    if (head->sum_weight < min_weight && head->nav_visited == false) {
      temp = head;
      min_weight = head->sum_weight;
    }
    head = head->next_node;
  }
  return temp;
}
void show_strategy_path(nav_node *head) {
  while (head) {
    cout << head->name << ' ';
    head = head->next_node;
  }
}
void delete_strategy_path(nav_node *head) {
  nav_node *temp;
  temp = head->next_node;
  while (temp) {
    delete head;
    head = temp;
    temp = temp->next_node;
  }
}

#endif