#include "mymap.h"

mymap::mymap()
{

}

void mymap:: init_map(QString Filename)
{
    map_head=create_map( Filename);
}
map_node* mymap::create_map(QString Filename){
    QFile fmatrix(":/"+Filename);
    QString tempName;//临时储存文件中读出的第一行，即地名
    //fmatrix.open("matrix.txt");
    if(fmatrix.exists())qDebug()<<"fmatrix exists";
    else qDebug()<<"fmatrix not exist";
    fmatrix.open(QFile::ReadOnly);
    matrix_stream.setDevice(&fmatrix);
    matrix_stream.readLineInto(&tempName,MAX_STR_LEN);
    //处理第一行的地名，并生成顶点节点
    place_num=0;//地点数量
    //vector<string>loc_name;
    map_node * phead=new map_node;
    map_node * pcur;
    pcur=phead;
    QStringList name_l;
    name_l=tempName.split(',',Qt::SkipEmptyParts);
    for(int i=0;i<name_l.size();i++){

        appendNode(pcur, name_l.at(i));
        pcur=pcur->next_node;
        loc_node.push_back(pcur);
        place_num++;
        pcur->number=place_num;

    }
    ReadinLoc(1);//读入X坐标
    ReadinLoc(2);//读入Y坐标

    //读入边，并生成边节点
    appendArc(phead);
    ReadInOption(1);//readinDensity
    ReadInOption(2);
    /*for(int i=0;i<place_num;i++){
    cout<<loc_name[i]<<' ';}*/
    pcur=phead->next_node;
    delete phead;
    return pcur;
}

void mymap:: appendNode(map_node* pcur,QString token){
    map_node* ptemp;
    ptemp=new map_node;
    pcur->next_node=ptemp;
    ptemp->name=token;
    ptemp->next_node=NULL;
}

void mymap:: appendArc(map_node * pcur_node){

    pcur_node=pcur_node->next_node;
    map_arc * pcur_arc;
    int temp_dist;//临时储存读入的距离
    for(int i=0;i<place_num;i++){
        pcur_arc=new map_arc;
        pcur_node->next_arc=pcur_arc;
        for(int q=0;q<place_num;q++){
            matrix_stream>>temp_dist;
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

void mymap:: showMap(){
  map_node* head=map_head;
  map_arc* temp;

    /*cout<<head->name<<' ';
    temp=head->next_arc;
    if(temp)cout<<temp->name<<temp->distance;
    else cout<<"error";*/
  qDebug()<<"name   distance  density  bicycle";
    while(head){
      qDebug()<<head->name<<' '<<head->x<<" "<<head->y;
        temp=head->next_arc;
        while(temp){
          qDebug()<<temp->name<<temp->distance<<' '<<temp->density<<' '<<temp->bicycle<<" ";
            temp=temp->next_arc;
        }
        head=head->next_node;
        qDebug()<<'\n';
    }

}
void mymap:: deleteMap(map_node*head){
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

void mymap::ReadInOption(int type){
    int temp_input;
    QVector<map_node*>::iterator it;
    it=loc_node.begin();
    map_arc* cur_arc;

    while(it!=loc_node.end()){
      cur_arc=(*it)->next_arc;
      for(int i=0;i< place_num &&cur_arc!=NULL;i++){
        matrix_stream>>temp_input;
        if(temp_input!=0){
          if(type==1)//density
          {
            cur_arc->density=temp_input;
          }
          if(type==2)//bicycle
          {
            cur_arc->bicycle=temp_input;
          }
          cur_arc=cur_arc->next_arc;
        }
      }
      it++;
    }

}
void mymap:: ReadinLoc(int type){
  QVector<map_node*>::iterator it;
  int temp_input;
  it=loc_node.begin();
  while(it!=loc_node.end()){
    matrix_stream>>temp_input;
    if(type==1)(*it)->x=temp_input;
    if(type==2)(*it)->y=temp_input;

    it++;
  }
}
