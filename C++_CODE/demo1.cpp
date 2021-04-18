/*
Created on 12:34
2021.4.16.Friday

@author: tongchen

读入地图->邻接矩阵 生成邻接表 ->在map.h中
实现策略->策略储存为链表中对指针。-> 在strategy.h中


debug:
noerrorlist:
loc_name   
*/

//#include"map.h"
#include"strategy.h"
#include<iostream>
#include<vector>
#include<string>
#include<fstream>

int main (){
    int place_num;//地点的数量
    vector<map_node*>loc_node;//地点的节点地址，用vector类型存储
    map_node* map_head= create_map(place_num,loc_node);//读取文件中的地图 存在邻接表中
    showMap(map_head);//打印地图
    clearStra(map_head);//清除地图中的权重
    //map_head->sum_weight=1;
    //if(!map_head)printf("mapheadisNULL\n");
    nav_node* strategy_path=Min_dis_str(map_head,place_num,loc_node[0],loc_node[2],loc_node);//寻找距离最短的路径，结果是经过的地点的链表，返回链表头
    show_strategy_path(strategy_path);//打印路径
    delete_strategy_path(strategy_path);//删除释放路径
    deleteMap(map_head);//删除释放地图
    return 0;
}
//test