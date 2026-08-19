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