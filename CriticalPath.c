#include<stdio.h>

typedef char VertexType;
typedef int EdgeType;
typedef int Status;
#define MAXVEX 100
#define INFINITY 65535
#define ok 1
#define error 0

typedef struct EdgeNode{
    int adjvex;//该顶点的下标
    int weight;//边的权值
    struct EdgeNode *next;//指向下一个邻接点
}EdgeNode;//边表结点

typedef struct VertexNode{
    int in;//顶点入度
    int data;//顶点数据
    EdgeNode *firstedge;//边表头指针
}VertexNode,AdjList[MAXVEX];//顶点表结点

typedef struct{
    AdjList adjList;
    int numVertexes,numEdges;//图的顶点数和边数
}graphAdjList,*GraphAdjList;


int *etv,*ltv;
int *stack2;
int top2;

//
Status TopologicalSort(GraphAdjList GL){
    EdgeNode *e;
    int i,k,gettop;
    int top=0;
    int count=0;
    int *stack;
    stack=(int *)malloc(GL->numVertexes * sizeof(int));
    for(i=0;i<GL->numVertexes;i++){
        if(GL->adjList[i].in==0){
            stack[++top]=i;
        }
    }
    top2=0;
    etv=(int *)malloc(GL->numVertexes * sizeof(int));
    for(i=0;i<GL->numVertexes;i++){
        etv[i]=0;
    }
    stack2=(int *)maoolc(GL->numVertexes * sizeof(int));
    while(top!=0){
        gettop=stack[top--];
        count++;
        stack2[++top2]=gettop;
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){
            k=e->adjvex;
            if(!(--GL->adjList[k].in)){
                stack[++top]=k;
            }
            if((etv[gettop]+e->weight)>etv[k]){
                etv[k]=etv[gettop]+e->weight;
            }
        }
    }
    if(count<GL->numVertexes){
        return error;
    }else{
        return ok;
    }
}

//
void CriticalPath(GraphAdjList GL){
    EdgeNode *e;
    int i,gettop,j,k;
    int ete,lte;
    TopologicalSort(GL);
    ltv=(int *)malloc(GL->numVertexes * sizeof(int));
    for(i=0;i<GL->numVertexes;i++){
        ltv[i]=etv[GL->numVertexes-1];
    }
    while(top2!=0){
        gettop=stack2[top2--];
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){
            k=e->adjvex;
            if(ltv[k]-e->weight<ltv[gettop]){
                ltv[gettop]=ltv[k]+e->weight;
            }
        }
    }
    for(j=0;j<GL->numVertexes;j++){
        for(e=GL->adjList[j].firstedge;e;e=e->next){
            k=e->adjvex;
            ete=etv[j];
            lte=ltv[k]-e->weight;
            if(ete==lte){
                printf("<v%d - v%d> length: %d\n",GL->adjList[j].data,GL->adjList[k].data,e->weight);
            }
        }
    }
}