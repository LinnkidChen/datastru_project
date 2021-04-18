#ifndef MAP_H
#define MAP_H

#define MAX_STR_LEN 500
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


struct Map_node{
    string name;//one side of arc
    
    struct Map_node * next_node;//图的下一个顶点
    struct Map_arc * next_arc;//图的第一条边

    bool nav_visited;//dijstra搜索时确定是否确定最短路径
    int number;//节点编号
    int sum_weight;//记录起始节点到每个节点的当前的weight之和
};//无向有权图的顶点
struct Map_arc{
    string name;//边的另一个顶点
    int  density;//拥挤度
    int  distance;// 距离
    //travel time = density*distance/speed


    struct Map_arc* next_arc;//下一个边
    struct Map_node * arc_node;//当前边指向的顶点地址
    
    int weight;//用于寻找路径时判断大小的权重
};//无向有权图的边
typedef struct Map_node map_node;
typedef struct Map_arc map_arc;

map_node* create_map(int &count,vector<map_node*> &loc_node);//从“matrix.txt”中读取邻接矩阵并生成邻接表。返回头指针，头指针为空。
void appendNode(map_node* pcur, string name);//生成邻接表时，传入当前顶点地址和下一个顶点的名字，生成下一个顶点
void appendArc(map_node* head,ifstream &fmatrix,const int count,vector<map_node*> &loc_node);//生成邻接表时，输入当前顶点的地址，读入该顶点的所有边并生成相应的边节点
//void ReadInDensity();//给定头节点，读入所有边的拥挤度
void showMap(map_node*head);//打印地图
void deleteMap(map_node*head);//删除并释放地图

map_node * create_map(int &count,vector<map_node*> &loc_node){
    ifstream fmatrix;
    char tempName[MAX_STR_LEN];//临时储存文件中读出的第一行，即地名
    fmatrix.open("matrix.txt");
    fmatrix.getline(tempName,MAX_STR_LEN);
    
    //处理第一行的地名，并生成顶点节点
    count=0;//地点数量
    //vector<string>loc_name;
    char* token;
    map_node * phead=new map_node;
    map_node * pcur;
    pcur=phead;
    token=strtok(tempName,",");
    while(token){
        
        appendNode(pcur, token);
        pcur=pcur->next_node;
        loc_node.push_back(pcur);
        count++;
        pcur->number=count;
        token=strtok(NULL,",");
    }
    //读入边，并生成边节点
    appendArc(phead,fmatrix,count,loc_node);
    
    /*for(int i=0;i<count;i++){
    cout<<loc_name[i]<<' ';}*/
    pcur=phead->next_node;
    delete phead;
    return pcur;
}

void appendNode(map_node* pcur,string token){
    map_node* ptemp;
    ptemp=new map_node;
    pcur->next_node=ptemp;
    ptemp->name=token;
    ptemp->next_node=NULL;
}

void appendArc(map_node * pcur_node,ifstream &fmatrix,const int count,vector<map_node*> &loc_node){
    
    pcur_node=pcur_node->next_node;
    map_arc * pcur_arc;
    int temp_dist;//临时储存读入的距离
    for(int i=0;i<count;i++){
        pcur_arc=new map_arc;
        pcur_node->next_arc=pcur_arc;
        for(int q=0;q<count;q++){
            fmatrix>>temp_dist;
            if(temp_dist){
                pcur_arc->next_arc=new map_arc;
                pcur_arc=pcur_arc->next_arc;
                
                pcur_arc->distance=temp_dist;
                pcur_arc->next_arc=NULL;
                pcur_arc->name=loc_node[q]->name;
                pcur_arc->arc_node=loc_node[q];

            } 
        }
        map_arc* temp;
        temp=pcur_node->next_arc;
        pcur_node->next_arc=temp->next_arc;//删除空白的头节点arc（可优化？）
        delete temp;

        pcur_node=pcur_node->next_node;
    }
}

void showMap(map_node*head){
    map_arc* temp;
    
    /*cout<<head->name<<' ';
    temp=head->next_arc;
    if(temp)cout<<temp->name<<temp->distance;
    else cout<<"error";*/
    
    while(head){
        cout<<head->name<<' ';
        temp=head->next_arc;
        while(temp){
            cout<<temp->name<<temp->distance<<' ';
            temp=temp->next_arc;
        }
        head=head->next_node;
        cout<<'\n';
    }
    
}
void deleteMap(map_node*head){
    map_node * temp_node;
    map_arc * temp_arc_cur,*temp_arc_next;
    while(head){
    temp_arc_cur=head->next_arc;
        while(temp_arc_cur){
            temp_arc_next=temp_arc_cur->next_arc;
            delete temp_arc_cur;
            temp_arc_cur=temp_arc_next;
        }
    temp_node=head;
    head=head->next_node;
    delete temp_node;
        
    }
}

#endif