#ifndef MYMAP_H
#define MYMAP_H

#define MAX_STR_LEN 500
#include <QDebug>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QVector>

struct Map_node {
  QString name; // one side of arc

  struct Map_node *next_node; //图的下一个顶点
  struct Map_arc *next_arc;   //图的第一条边

  bool nav_visited; // dijstra搜索时确定是否确定最短路径
  int number;       //节点编号
  int sum_weight;   //记录起始节点到每个节点的当前的weight之和

  int x;
  int y; //图中的x，y坐标
};       //无向有权图的顶点
struct Map_arc {
  QString name; //边的另一个顶点
  int density;  //拥挤度
  int distance; // 距离
  int bicycle;

  // travel time = density*distance/speed

  struct Map_arc *next_arc;  //下一个边
  struct Map_node *arc_node; //当前边指向的顶点地址

  int weight; //用于寻找路径时判断大小的权重
};            //无向有权图的边
typedef struct Map_node map_node;
typedef struct Map_arc map_arc;

class mymap {
public:
  mymap();

  void init_map(QString Filename);
  map_node *create_map(
      QString
          Filename); //从“matrix.txt”中读取邻接矩阵并生成邻接表。返回头指针，头指针为空。
  void appendNode(
      map_node *pcur,
      QString
          name); //生成邻接表时，传入当前顶点地址和下一个顶点的名字，生成下一个顶点
  void appendArc(
      map_node *
          pcur_node); //生成邻接表时，输入当前顶点的地址，读入该顶点的所有边并生成相应的边节点

  void
  ReadInOption(int type); //读入其他参数。使用type表示类型。1 for density,2 for
                          // avalible for bicycle ;
  void ReadinLoc(int type);       //读入一行坐标，1 for x， 2 for y
  void showMap();                 //打印地图
  void deleteMap(map_node *head); //删除并释放地图

  int place_num;
  QVector<map_node *> loc_node;
  map_node *map_head;
  QTextStream matrix_stream;
};

#endif // MYMAP_H
