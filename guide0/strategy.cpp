#include"strategy.h"


strategy:: strategy()
{
  nav_head=NULL;

  begin=NULL;
  end=NULL;
  type=0;
}
nav_node* strategy::Min_weight_str(map_node*  head,int count,map_node* begin,map_node* end,QVector<map_node*>const &loc_node){
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
      if(pcur_arc->weight>0){
        cur_weight_sum=pcur_node->sum_weight+pcur_arc->weight;
        if(cur_weight_sum<pcur_arc->arc_node->sum_weight){//如果途经当前节点的路径比原路径更短
          pcur_arc->arc_node->sum_weight=cur_weight_sum;
          temp_path[pcur_arc->arc_node->number]=pcur_node;
        }}
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

  nav_node* temp_n_node;
  map_arc* temp_arc;
  map_node* temp_node;

  temp_n_node=nav_head;
  while(temp_n_node->next_node ){
    temp_node=temp_n_node->cur_node;
    temp_arc=temp_node->next_arc;
    while(temp_arc){
      if(temp_arc->name==temp_n_node->next_node->name){
        temp_n_node->cur_arc=temp_arc;
        break;
      }
      temp_arc=temp_arc->next_arc;
    }
    temp_n_node=temp_n_node  ->next_node;

  }

  return nav_head;
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
void strategy:: Min_dis_str(map_node * head,QVector<map_node*>&loc_node){
    //使weight初始化为distance
    map_arc * temp_arc=NULL;
    map_node * temp_node=NULL;
    temp_node=head;
    int count=loc_node.size();
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
    nav_head=Min_weight_str(head,count,begin,end,loc_node);

}
void strategy::Min_time_str(map_node * head,QVector<map_node*>&loc_node){
    //使weight初始化为distance*density
    map_arc * temp;
    int count=loc_node.size();
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

   nav_head =Min_weight_str(head,count,begin,end,loc_node);

}void strategy::Min_with_transport(map_node *head, QVector<map_node *>const & loc_node){
  int count=loc_node.size();
  map_arc * temp;
  while (head)
  {
    temp=head->next_arc;
    while(temp)
    {
      if(temp->bicycle>0){temp->weight=temp->weight=temp->distance*temp->density;}
      else temp->weight=-1;

      temp=temp->next_arc;
    }
    head->nav_visited=false;
    head=head->next_node;
  }

  nav_head= strategy:: Min_weight_str(head,count,begin,end,loc_node);
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
void strategy::show_strategy_path( ){
  nav_node*  _head=nav_head;
  while(_head->next_node){
//        qDebug()<<head->name<<' ';
qDebug()<<_head->cur_arc->name;
      _head=_head->next_node;
    }
}
void strategy::delete_strategy_path(){
  if(nav_head){
    nav_node* temp;
    temp=nav_head->next_node;
    while(temp){
        delete nav_head;
        nav_head=temp;
        temp=temp->next_node;
    }
    nav_head=NULL;}
}
int strategy::SetOption(QString begin_s,QString end_s,QVector<map_node *> &loc_node){
  begin=NULL;
  end=NULL;
  auto it=loc_node.begin();
  while(it!=loc_node.end()&&(!begin||!end)){
    if((*it)->name==begin_s)begin=*it;
    if((*it)->name==end_s)end=*it;
    it++;
  }

  if(begin&&end)return 1;
  else return 0;

}
