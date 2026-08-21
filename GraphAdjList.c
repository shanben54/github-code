#include<stdio.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535

typedef struct EdgeNode{
    int adjvex;//该结点对应的下标
    EdgeType info;//边的权值
    struct EdgeNode *next;//指向下一个边表结点
}EdgeNode;//边表结点

typedef struct VertexNode{
    VertexType data;//顶点数据
    EdgeNode *firstedge;//指向第一个边表结点
}VertexNode,AdjList[MAXVEX];//顶点表结点

typedef struct{
    AdjList adjList;//顶点表
    int numNodes,numEdges;//结点数和边数
}GraphAdjList;


//建立无向图的邻接表
void CreateALGraph(GraphAdjList *G){
    int i,j,k;
    EdgeNode *e;
    printf("输入顶点数和边数\n");
    scanf("%d,%d",&G->numNodes,&G->numEdges);//读入顶点数和边数

    for(i=0;i<G->numNodes;i++){
        scanf(&G->adjList[i].data);//读入顶点数据
        G->adjList[i].firstedge=NULL;//顶点的边表初始化
    }//对顶点表进行初始化

    for(k=0;k<G->numEdges;k++){
        printf("输入边(vi,vj)上的顶点序号\n");
        scanf("%d,%d",&i,&j);//读入边的两个顶点序号
        //顶点i的边表结点指向j
        e=(EdgeNode *)malloc(sizeof(EdgeNode));//新建一个边表结点
        e->adjvex=j;//下标为j
        e->next=G->adjList[i].firstedge;
        G->adjList[i].firstedge=e;//运用头插法，对顶点i的边表链表添加数据
        //顶点j的边表结点指向i
        e=(EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex=i;
        e->next=G->adjList[j].firstedge;
        G->adjList[j].firstedge=e;//同样的方法对顶点j的边表链表添加数据
    }
}


//邻接表的深度优先遍历
typedef int Boolean;
Boolean visited[MAXVEX];//访问标志数组

//深度优先递归算法
void DFS(GraphAdjList GL,int i){
    EdgeNode *p;
    visited[i]=1;//修改结点访问状态
    printf("%c",GL.adjList[i].data);//打印结点
    p=GL.adjList[i].firstedge;//查询该结点的邻接结点
    while(p){//如果存在邻接结点
        if(!visited[p->adjvex]){
            DFS(GL,p->adjvex);//如未访问则对该结点继续遍历
        }
        p=p->next;//查询下一个邻接结点
    }
}

//深度优先遍历邻接表
void DFSTraverse(GraphAdjList GL){
    int i;
    for(i=0;i<GL.numNodes;i++){
        visited[i]=0;
    }//对所有结点的访问状态初始化
    for(i=0;i<GL.numNodes;i++){//对所有结点调用一下递归算法，防止未连通图，连通图只用调用一次
        if(!visited[i]){
            DFS(GL,i);
        }
    }
}