#include<iostream>
#include<cstdlib>
#include"SqQueue.h"
using namespace std;

template<typename VertexType,typename EdgeType>
class GraphAdjList{
private:
    struct EdgeNode{
        int adjvex;
        EdgeType weight;
        EdgeNode* next;
        EdgeNode(int a,EdgeType w):adjvex(a),weight(w),next(nullptr){}
    };
    struct VexNode{
        VertexType data;
        EdgeNode* first;
        VexNode(VertexType v=0):data(v),first(nullptr){}
    };
    int VertexNum;
    int EdgeNum;
    VexNode* vexs;
public:
    GraphAdjList(int num);
    ~GraphAdjList();

    void SetVex(int i,VertexType d);
    void AddEdge(int i,int j,EdgeType w);
    void Display()const;
};

template<typename VertexType,typename EdgeType>
GraphAdjList<VertexType,EdgeType>::GraphAdjList(int num){
    VertexNum=num;
    EdgeNum=0;
    vexs=new VexNode[VertexNum];
}

template<typename VertexType,typename EdgeType>
GraphAdjList<VertexType,EdgeType>::~GraphAdjList(){
    for(int i=0;i<VertexNum;i++){
        EdgeNode* p=vexs[i].first;
        while(p){
            EdgeNode* q=p;
            p=p->next;
            delete q;
        }
    }
    delete[] vexs;
}

template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::SetVex(int i,VertexType d){
    vexs[i-1].data=d;
}

template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::AddEdge(int i,int j,EdgeType w){
    EdgeNode* p=vexs[i].first;
    while(p){
        p=p->next;
    }
    p=new EdgeNode(j,w);
    p=vexs[j].first;
    while(p){
        p=p->next;
    }
    p=new EdgeNode(i,w);
}

template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::Display()const{
    cout<<"顶点表：";
    for(int i=0;i<VertexNum;i++){
        cout<<vexs[i].data<<" ";
    }
    cout<<"边表：";
    for(int i=0;i<VertexNum;i++){
        EdgeNode* p=vexs[i].first;
        while(p){
            cout<<vexs[i].data<<"->"<<vexs[p->adjvex].data<<": "<<p->weight<<endl;
            p=p->next;
        }
    }
}