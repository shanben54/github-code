//拓扑排序
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


//拓扑排序
Status TopolpgicalSort(GraphAdjList GL){
    EdgeNode *e;
    int i,k,gettop;
    int top=0;//栈指针下标
    int count=0;//输出顶点的个数
    int *stack;//入度为0的顶点栈
    stack=(int *)malloc (GL->numVertexes * sizeof(int));//初始化栈，开辟一块连续的内存，stack指向这堆内存的第一个
    for(i=0;i<GL->numVertexes;i++){
        if(GL->adjList[i].in==0){//寻找入度为0的顶点
            stack[++top]=i;//将顶点下标入栈，注意top初始值是0，所以这里是++top，stack[0]不储存数据
        }
    }
    while(top!=0){
        gettop=stack[top--];//取出数据
        printf("%d -> ",GL->adjList[gettop].data);//打印此顶点
        count++;//计数加1
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){//遍历此顶点的邻接顶点
            k=e->adjvex;
            if(!(-- GL->adjList[k].in)){//将邻接顶点入度-1
                stack[++top]=k;//如果入度为0，将这个顶点入栈
            }
        }
    }
    if(count<GL->numVertexes){//如果count小于顶点数，说明有环
        return error;
    }else{
        return ok;
    }
}