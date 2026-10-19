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
        VexNode(VertexType v=VertexType()):data(v),first(nullptr){}
    };
    int VertexNum;
    int EdgeNum;
    int* visited;
    VexNode* vexs;
    //判断两个结点之间是否存在边的函数
    EdgeNode* Find(int i,int j){
        EdgeNode* p=vexs[i].first;
        while(p){
            if(p->adjvex==j) return p;
            p=p->next;
        }
        return nullptr;
    }
    void DFS(int v);
public:
    GraphAdjList(int num);
    ~GraphAdjList();

    void SetVex(int i,VertexType d);
    void AddEdge(int i,int j,EdgeType w);
    void Display()const;
    void DFSTraver();
    void BFSTraver();
};

//构造函数
template<typename VertexType,typename EdgeType>
GraphAdjList<VertexType,EdgeType>::GraphAdjList(int num){
    VertexNum=num;
    EdgeNum=0;
    vexs=new VexNode[VertexNum];
    visited=new int[VertexNum];
    for(int i=0;i<VertexNum;i++){
        visited[i]=0;
    }
}

//析构函数
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
    delete[] visited;
}

//设置结点
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::SetVex(int i,VertexType d){
    vexs[i].data=d;
}

//新建边
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::AddEdge(int i,int j,EdgeType w){
    if(j==i) return;
    EdgeNode* a=Find(i,j);//判断是否已有这两个结点之间的边
    if(a==nullptr){
        EdgeNode* q=new EdgeNode(j,w);
        q->next=vexs[i].first;
        vexs[i].first=q;
        q=new EdgeNode(i,w);
        q->next=vexs[j].first;
        vexs[j].first=q;
        EdgeNum++;
    }else{
        a->weight=w;
        a=Find(j,i);
        if(a){
            a->weight=w;
        }
    }
}

//打印邻接表
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::Display()const{
    cout<<"顶点表：";
    for(int i=0;i<VertexNum;i++){
        cout<<vexs[i].data<<" ";
    }
    cout<<"边表："<<endl;
    for(int i=0;i<VertexNum;i++){
        EdgeNode* p=vexs[i].first;
        while(p){
            cout<<vexs[i].data<<"->"<<vexs[p->adjvex].data<<": "<<p->weight<<endl;
            p=p->next;
        }
    }
}

//深度优先递归函数
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::DFS(int v){
    if(visited[v]==0){
        cout<<vexs[v].data<<" ";
        visited[v]=1;
        EdgeNode* p=vexs[v].first;
        while(p){
            DFS(p->adjvex);
            p=p->next;
        }
    }
}

//深度优先遍历
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::DFSTraver(){
    for(int i=0;i<VertexNum;i++){
        visited[i]=0;
    }
    for(int i=0;i<VertexNum;i++){
        DFS(i);
    }
}

//广度优先遍历
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::BFSTraver(){
    for(int i=0;i<VertexNum;i++){
        visited[i]=0;
    }
    SqQueue<int> q;
    for(int i=0;i<VertexNum;i++){
        if(visited[i]==0){
            visited[i]=1;
            q.EnQueue(i);
            while(!q.Empty()){
                int p;
                q.DeQueue(p);
                cout<<vexs[p].data<<" ";
                EdgeNode* r=vexs[p].first;
                while(r){
                    int n=r->adjvex;
                    if(visited[n]==0){
                        q.EnQueue(n);
                        visited[n]=1;
                    }
                    r=r->next;
                }
            }
        }
    }
}