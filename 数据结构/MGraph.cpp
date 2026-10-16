//邻接矩阵的cpp复现
#include<iostream>
#include<cstdlib>
#include"SqQueue.h"
using namespace std;

template<typename VertexType,typename EdgeType>
class MGraph{
private:
    int VertexNum;//顶点数
    int EdgeNum;//边数
    VertexType* vexs;//顶点集
    EdgeType** arc;//边集
    EdgeType NoEdge;//边不存在时的值
    int* visited;
    void DFS(int i);
public:
    MGraph(int num,EdgeType NoEdgevalue);
    ~MGraph();

    void SetVertex(int i,VertexType v);
    void AddEdge(int i,int j,EdgeType w);
    void Display()const;
    void DFSTraverse();
    void BFSTraverse();
};

//构造函数
template<typename VertexType,typename EdgeType>
MGraph<VertexType,EdgeType>::MGraph(int num,EdgeType NoEdgevalue){
    EdgeNum=0;
    NoEdge=NoEdgevalue;
    VertexNum=num;
    vexs=new VertexType[VertexNum];//开辟顶点集
    visited=new int[VertexNum];
    arc=new EdgeType*[VertexNum];
    for(int i=0;i<VertexNum;i++){
        arc[i]=new EdgeType[VertexNum];
    }//开辟边集
    //将边集初始化，对角线的边为0
    for(int i=0;i<VertexNum;i++){
        for(int j=0;j<VertexNum;j++){
            if(i==j){
                arc[i][j]=0;
            }else{
                arc[i][j]=NoEdge;
            }
        }
    }
}

//析构函数，注意用delete[]
template<typename VertexType,typename EdgeType>
MGraph<VertexType,EdgeType>::~MGraph(){
    delete[] vexs;
    for(int i=0;i<VertexNum;i++){
        delete[] arc[i];
    }
    delete[] arc;
    delete[] visited;
}

//设置顶点数据
template<typename VertexType,typename EdgeType>
void MGraph<VertexType,EdgeType>::SetVertex(int i,VertexType v){
    vexs[i-1]=v;
}

//添加边的数据
template<typename VertexType,typename EdgeType>
void MGraph<VertexType,EdgeType>::AddEdge(int i,int j,EdgeType w){
    if(arc[i-1][j-1]==NoEdge) EdgeNum++;
    arc[i-1][j-1]=arc[j-1][i-1]=w;
}

//打印邻接矩阵
template<typename VertexType,typename EdgeType>
void MGraph<VertexType,EdgeType>::Display()const{
    cout<<"邻接矩阵: \n";
    cout<<"  ";
    for(int i=0;i<VertexNum;i++){
        cout<<vexs[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<VertexNum;i++){
        cout<<vexs[i]<<" ";
        for(int j=0;j<VertexNum;j++){
            cout<<arc[i][j]<<" ";
        }
        cout<<endl;
    }
}

//深度优先遍历的递归
template<typename VertexType,typename EdgeType>
void MGraph<VertexType,EdgeType>::DFS(int i){
    if(visited[i]==0){
        visited[i]=1;
        cout<<vexs[i]<<" ";
        for(int j=0;j<VertexNum;j++){
            if(arc[i][j]!=NoEdge){
                DFS(j);
            }
        }
    }
}

//深度优先遍历
template<typename VertexType,typename EdgeType>
void MGraph<VertexType,EdgeType>::DFSTraverse(){
    for(int i=0;i<VertexNum;i++){
        visited[i]=0;
    }
    for(int i=0;i<VertexNum;i++){
        DFS(i);
    }
}

//广度优先遍历
template<typename VertexType,typename EdgeType>
void MGraph<VertexType,EdgeType>::BFSTraverse(){
    for(int i=0;i<VertexNum;i++){
        visited[i]=0;
    }
    SqQueue<int> q;
    for(int k=0;k<VertexNum;k++){
        if(visited[k]==0){
            visited[k]=1;
            q.EnQueue(k);
            while(!q.Empty()){
                int i;
                q.DeQueue(i);
                cout<<vexs[i]<<" ";
                for(int j=0;j<VertexNum;j++){
                    if(arc[i][j]!=NoEdge&&visited[j]==0){
                        visited[j]=1;
                        q.EnQueue(j);
                    }
                }
            }
        }
    }
}

int main(){
    MGraph<char, int> g(4, 999);   // 4 个顶点，999 表示"无边"
    g.SetVertex(1, 'A');
    g.SetVertex(2, 'B');
    g.SetVertex(3, 'C');
    g.SetVertex(4, 'D');
    g.AddEdge(1, 2, 1);
    g.AddEdge(1, 3, 2);
    g.AddEdge(2, 3, 3);
    g.AddEdge(3, 4, 4);
    g.AddEdge(1, 2, 5);            // 故意重复加 A-B
    g.Display();
    g.DFSTraverse();
    cout<<endl;
    g.BFSTraverse();
    system("pause");
    return 0;
  }