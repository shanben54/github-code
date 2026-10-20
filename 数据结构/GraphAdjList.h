#ifndef GRAPHADJLIST_H
#define GRAPHADJLIST_H

#include<iostream>
#include<cstdlib>
#include<limits>
#include"SqQueue.h"
#include<algorithm>
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
    //Kruskal辅助查找老大函数
    int FindBoss(int x,int parent[]){
        while(x!=parent[x]) x=parent[x];
        return x;
    }
public:
    GraphAdjList(int num);
    ~GraphAdjList();

    void SetVex(int i,VertexType d);
    void AddEdge(int i,int j,EdgeType w);
    void Display()const;
    void DFSTraver();
    void BFSTraver();
    void Dijkstra(int scr,EdgeType dist[],int path[]);
    void Prim(EdgeType lowcost[],int adjvex[]);
    void Kruskal();
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

//Dijkstra算法求最短路径
//每次都寻找路径最短的结点来毕业，根据已毕业的结点不断更新其他结点的路径
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::Dijkstra(int scr,EdgeType dist[],int path[]){
    EdgeType INF=numeric_limits<EdgeType>::max()/2;
    for(int i=0;i<VertexNum;i++){
        visited[i]=0;
        dist[i]=INF;
        path[i]=-1;
    }
    dist[scr]=0;
    for(int i=0;i<VertexNum;i++){
        int n=-1;
        EdgeType m=INF;
        for(int j=0;j<VertexNum;j++){
            if(dist[j]<m&&visited[j]==0){
                n=j;
                m=dist[j];
            }
        }
        if(m==INF) break;
        visited[n]=1;
        EdgeNode* p=vexs[n].first;
        while(p){
            int q=p->adjvex;
            if(dist[n]+p->weight<dist[q]){
                dist[q]=dist[n]+p->weight;
                path[q]=n;
            }
            p=p->next;
        }
    }
}

//Prim算法求最小生成树
//从初始点出发，寻找里当前树最近的结点，然后使其毕业，再更新看看其他结点到树的距离有没有变短
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::Prim(EdgeType lowcost[],int adjvex[]){
    int start=0;
    EdgeType ans=EdgeType();
    EdgeType INF=numeric_limits<EdgeType>::max()/2;
    for(int i=0;i<VertexNum;i++){
        visited[i]=0;
        lowcost[i]=INF;
        adjvex[i]=start;
    }
    visited[start]=1;
    lowcost[start]=0;
    EdgeNode* p=vexs[start].first;
    while(p){
        lowcost[p->adjvex]=p->weight;
        p=p->next;
    }
    for(int i=1;i<VertexNum;i++){
        int n=-1;
        EdgeType m=INF;
        for(int j=0;j<VertexNum;j++){
            if(visited[j]==0&&lowcost[j]<m){
                m=lowcost[j];
                n=j;
            }
        }
        if(m==INF){
            cout<<"图不连通"<<endl;
            return ;
        }
        visited[n]=1;
        ans+=lowcost[n];
        EdgeNode* p=vexs[n].first;
        while(p){
            if((p->weight<lowcost[p->adjvex])&&!visited[p->adjvex]){
                lowcost[p->adjvex]=p->weight;
                adjvex[p->adjvex]=n;
            }
            p=p->next;
        }
    }
    cout<<"总权重为"<<ans<<endl;
}

//Kruskal算法求最小生成树
//先将边进行排序，然后从小到大取边，看看边的两个结点是否在同一个集合内(就是看他们老大是否一样)
//不断取边直到取出v-1条边，判断不生成环的核心就是通过判断结点是否在一个集合内
template<typename VertexType,typename EdgeType>
void GraphAdjList<VertexType,EdgeType>::Kruskal(){
    int* parent=new int[VertexNum];
    struct ks{
        int u,v;
        EdgeType w;
    };
    ks* es=new ks[EdgeNum];//边的集合
    int cnt=0;
    //因为原本邻接表里同一条边被存储了两次，现在重新将边存储起来，左结点更小的时候才存起来，这样边集的数量就是正确的
    for(int i=0;i<VertexNum;i++){
        parent[i]=i;
        EdgeNode* p=vexs[i].first;
        while(p){
            if(i<p->adjvex){
                es[cnt].u=i;
                es[cnt].v=p->adjvex;
                es[cnt].w=p->weight;
                cnt++;
            }
            p=p->next;
        }
    }
    sort(es,es+cnt,[](const ks &a,const ks &b){return a.w<b.w;});
    EdgeType ans=EdgeType();
    int choose=0;//取的边的数量
    for(int n=0;n<cnt&&choose<VertexNum-1;n++){
        int ur=FindBoss(es[n].u,parent);
        int vr=FindBoss(es[n].v,parent);
        if(ur==vr) continue;
        ans+=es[n].w;
        choose++;
        parent[vr]=ur;//将两个集合和为一个集合
    }
    delete[] parent;
    delete[] es;
    if(choose<VertexNum-1){
        cout<<"图未连通"<<endl;
    }else{
        cout<<"总权重为"<<ans<<endl;
    }
}

#endif
