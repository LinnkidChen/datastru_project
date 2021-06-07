#include"strategy.h"


strategy:: strategy()
{

}
void strategy:: clearStra(map_node * head){
    map_arc * temp;
    while (head){
        temp=head->next_arc;
        while(temp){
            temp->weight=0;
            temp=temp->next_arc;
        }
        head->nav_visited=false;
        head->sum_weight=INF;
        head=head->next_node;
    }
}
nav_node * strategy:: Min_dis_str(map_node * head,int count,map_node* begin,map_node* end,QVector<map_node*>loc_node){
    //使weight初始化为distance
    map_arc * temp_arc=NULL;
    map_node * temp_node=NULL;
    temp_node=head;
    while (temp_node){
        temp_arc=temp_node->next_arc;
        while(temp_arc){
            temp_arc->weight=temp_arc->distance;
            temp_arc=temp_arc->next_arc;
        }
        temp_node->nav_visited=false;
        temp_node=temp_node->next_node;
    }
        //return NULL;
     return Min_weight_str(head,count,begin,end,loc_node);

}
nav_node * strategy::Min_time_str(map_node * head,int count,map_node* begin,map_node* end,QVector<map_node*>loc_node){
    //使weight初始化为distance*density
    map_arc * temp;
    while (head)
    {
        temp=head->next_arc;
        while(temp)
        {
            temp->weight=temp->distance*temp->density;
            temp=temp->next_arc;
        }
        head->nav_visited=false;
        head=head->next_node;
    }

    return  Min_weight_str(head,count,begin,end,loc_node);

}
nav_node * strategy::Min_weight_str(map_node * head,int count,map_node* begin,map_node* end,QVector<map_node*>loc_node){
    nav_node* nav_head;
    nav_head = new nav_node;//记录路径返回
    map_node* temp_path[1000];//记录每个起始节点到每个其他节点的路径

    //dijstra
    map_node* pcur_node;
    map_arc* pcur_arc;
    int cur_weight_sum;
    pcur_node=end;
    end->sum_weight=0;

    for(int i=0;i<count;i++){
        pcur_arc=pcur_node->next_arc;

        while(pcur_arc){

            cur_weight_sum=pcur_node->sum_weight+pcur_arc->weight;
            if(cur_weight_sum<pcur_arc->arc_node->sum_weight){//如果途经当前节点的路径比原路径更短
                pcur_arc->arc_node->sum_weight=cur_weight_sum;
                temp_path[pcur_arc->arc_node->number]=pcur_node;
            }
            pcur_arc=pcur_arc->next_arc;
        }
        pcur_node->nav_visited=true;
        pcur_node=dij_find_next_node(head);
        if(pcur_node==begin)break;
    }

    nav_head->name=begin->name;
    nav_head->cur_node=begin;

    nav_node *pcur_nav_node;
    pcur_nav_node=nav_head;
    for(int i=0;(i<count&&temp_path[pcur_nav_node->cur_node->number]!=end);i++){//防止死循环
        pcur_nav_node->next_node=new nav_node;
        pcur_nav_node->next_node->cur_node=temp_path[pcur_nav_node->cur_node->number];
        pcur_nav_node=pcur_nav_node->next_node;
        pcur_nav_node->name=pcur_nav_node->cur_node->name;
    }
    pcur_nav_node->next_node=new nav_node;
    pcur_nav_node->next_node->name=end->name;
    pcur_nav_node->next_node->cur_node=end;
    pcur_nav_node->next_node->next_node=NULL;

    return nav_head;
}
map_node * strategy::dij_find_next_node(map_node* head){
    map_node* temp;
    int min_weight;
    if(head)min_weight=head->sum_weight;
    //cout<<"111\n";
    temp=head;

    while(head){
        if(head->sum_weight<min_weight&&head->nav_visited==false){
            temp=head;
            min_weight=head->sum_weight;
        }
        head=head->next_node;
    }
    return temp;
}
void strategy::show_strategy_path(nav_node* head){
    while(head){
        qDebug()<<head->name<<' ';
        head=head->next_node;
    }
}
void strategy::delete_strategy_path(nav_node *head){
    nav_node* temp;
    temp=head->next_node;
    while(temp){
        delete head;
        head=temp;
        temp=temp->next_node;
    }
}
