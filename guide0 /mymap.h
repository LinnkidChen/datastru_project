#ifndef MYMAP_H
#define MYMAP_H

#define MAX_STR_LEN 500
#include<QDebug>
#include<QVector>
#include<QString>
#include <QTextStream>
#include<QFile>


struct Map_node{
    QString name;//one side of arc

    struct Map_node * next_node;//图的下一个顶点
    struct Map_arc * next_arc;//图的第一条边

    bool nav_visited;//dijstra搜索时确定是否确定最短路径
    int number;//节点编号
    int sum_weight;//记录起始节点到每个节点的当前的weight之和
};//无向有权图的顶点
struct Map_arc{
    QString name;//边的另一个顶点
    int  density;//拥挤度
    int  distance;// 距离
    //travel time = density*distance/speed


    struct Map_arc* next_arc;//下一个边
    struct Map_node * arc_node;//当前边指向的顶点地址

    int weight;//用于寻找路径时判断大小的权重
};//无向有权图的边
typedef struct Map_node map_node;
typedef struct Map_arc map_arc;


class mymap
{
public:
    mymap();


    map_node* create_map(int &count,QVector<map_node*> &loc_node);//从“matrix.txt”中读取邻接矩阵并生成邻接表。返回头指针，头指针为空。
    void appendNode(map_node* pcur, QString name);//生成邻接表时，传入当前顶点地址和下一个顶点的名字，生成下一个顶点
    void appendArc(map_node * pcur_node,QTextStream &matrix_stream,const int count,QVector<map_node*> &loc_node);//生成邻接表时，输入当前顶点的地址，读入该顶点的所有边并生成相应的边节点
    //void ReadInDensity();//给定头节点，读入所有边的拥挤度
    void showMap(map_node*head);//打印地图
    void deleteMap(map_node*head);//删除并释放地图
};

#endif // MYMAP_H
