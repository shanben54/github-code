#include<stdio.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

//图的邻接矩阵结构定义
typedef struct{
    VertexType vexs[MAXVEX];//顶点表
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
    int numNodes,numEdges;//顶点数和边数
}MGraph;

//建立无向图的邻接矩阵
void CreateMGraph(MGraph *G){
    int i,j,k,w;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d",&G->numNodes,&G->numEdges);
    for(i=0;i<G->numNodes;i++){
        sacnf(&G->vexs[i]);
    }//读入顶点数据
    for(i=0;i<G->numNodes;i++){
        for(j=0;j<G->numNodes;j++){
            G->arc[i][j]=INFINITY;//邻接矩阵初始化
        }
    }
    for(k=0;k<G->numEdges;k++){
        printf("输入边(vi,vj)上的下标i,下标j和权w:\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j]=w;//读入边，建立邻接矩阵
        G->arc[j][i]=w;//无向图具有对称性
    }
}


//邻接矩阵的深度优先遍历
typedef int Boolean;
Boolean visited[MAXVEX];//访问标志数组，0表示未访问，1表示已访问

//深度优先递归算法
void DFS(MGraph G,int i){
    int j;
    visited[i]=1;//修改这个结点的访问状态
    printf("%c",G.vexs[i]);//打印结点
    for(j=0;j<G.numNodes;j++){
        if(G.arc[i][j]==1&&!visited[j]){//寻找和当前结点邻接并且未访问的结点
            DFS(G,j);//递归调用函数从下一个结点出发
        }
    }
}

//深度优先遍历邻接矩阵
void DFSTraverse(MGraph G){
    int i;
    for(i=0;i<G.numNodes;i++){
        visited[i]=0;
    }//对所有顶点的访问状态初始化
    for(i=0;i<G.numNodes;i++){
        if(!visited[i]){
            DFS(G,i);
        }
    }//对所有结点都进行遍历，防止有未连通图的情况，连通图只需要调用一次
}