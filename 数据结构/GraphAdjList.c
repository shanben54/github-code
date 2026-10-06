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


//邻接表的广度优先遍历


//有关于队列的代码，广度优先遍历需要用到队列
#define maxsize 1000
typedef int QElemType;
#define ok 1
#define error 0
typedef int Status;

//循环队列的定义
typedef struct{
    QElemType data[maxsize];
    int front;//头指针
    int rear;//尾指针，指向队尾元素的下一位
}SqQueue;

//初始化一个空队列
Status InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
    return ok;
}

//获取队列的长度
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+maxsize)%maxsize;//计算队列的通用公式，取模是为了防止超出长度
}

//判断队列是否为空
Status QueueEmpty(SqQueue Q){
    if(Q.front==Q.rear){
        return ok;
    }else{
        return error;
    }
}

//在队尾插入元素e
Status EnQueue(SqQueue *Q,QElemType e){
    if((Q->rear+1)%maxsize==Q->front){
        return error;
    }//判断队列是否满，如果尾指针的下一位是头指针队列为空，多空一个出来是为了和队列为空时区分，取模防止溢出
    Q->data[Q->rear]=e;//在队尾添加元素
    Q->rear=(Q->rear+1)%maxsize;//尾指针向后移动一位，若到最后就循环到数组头部
    return ok;
}

//删除队头的元素
Status DeQueue(SqQueue *Q,QElemType *e){
    if(Q->front==Q->rear){
        return error;
    }//判断队列是否为空
    *e=Q->data[Q->front];//将队首元素赋值给e
    Q->front=(Q->front+1)%maxsize;//头指针向后移动一位，到最后就循环到数组头部
    return ok;
}


//对邻接表进行广度优先遍历
void BFSTraverse(GraphAdjList GL){
    int i;
    EdgeNode *p;//新建结点指针
    SqQueue Q;//创建队列
    for(i=0;i<GL.numNodes;i++){
        visited[i]=0;
    }//对所有顶点的访问状态初始化
    InitQueue(&Q);//初始化队列
    for(i=0;i<GL.numNodes;i++){//对所有顶点循环一遍，防止未连通图的情况，若连通图只用循环一遍
        if(!visited[i]){//如果未被访问
            visited[i]=1;//修改访问状态
            printf("%c",GL.adjList[i].data);//打印顶点
            EnQueue(&Q,i);//把当前顶点的序列放入队尾
            while(!QueueEmpty(Q)){//如果队列非空
                DeQueue(&Q,&i);//取出队首的顶点序列，赋值给i
                p=GL.adjList[i].firstedge;//p指向当前顶点的边表结点，也就是要寻找当前顶点i的邻接顶点
                while(p){//如果存在邻接顶点
                    if(!visited[p->adjvex]){//如果没有访问过
                        visited[p->adjvex]=1;//修改访问状态
                        printf("%c",GL.adjList[p->adjvex].data);//打印顶点
                        EnQueue(&Q,p->adjvex);//把这个邻接顶点的序列放入队列
                    }
                    p=p->next;//指向下一个邻接顶点
                }
            }
        }
    }
}