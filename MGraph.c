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
    printf("%c",G.vexs[i]);//打印顶点
    for(j=0;j<G.numNodes;j++){
        if(G.arc[i][j]==1&&!visited[j]){//寻找和当前结点邻接并且未访问的顶点
            DFS(G,j);//递归调用函数从下一个顶点出发
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
    }//对所有顶点都进行遍历，防止有未连通图的情况，连通图只需要调用一次
}


//邻接矩阵的广度优先遍历


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


//对邻接矩阵进行广度优先遍历
/*广度优先遍历就是一层一层遍历，先打印最开始的顶点，然后打印下一层的结点，把下一层结点放入栈，再依次寻找和下一层结点邻接的顶点
这样就把下下层的结点也找到了，就这样一层一层打印再寻找*/
void BFSTraverse(MGraph G){
    int i,j;

    SqQueue Q;//创建队列
    for(i=0;i<G.numNodes;i++){
        visited[i]=0;
    }//对所有结点的访问状态进行初始化
    InitQueue(&Q);//初始化队列

    for(i=0;i<G.numNodes;i++){//对每一个顶点都循环，防止未联通表，若联通表只需要循环一次
        if(!visited[i]){//如果没有被访问过
            visited[i]=1;//更新访问状态
            printf("%c",G.vexs[i]);//打印顶点
            EnQueue(&Q,i);//在队列末尾插入i
            while(!QueueEmpty(Q)){//如果队列未空
                DeQueue(&Q,&i);//取出队首元素，取值给i
                for(j=0;j<G.numNodes;j++){
                    if(G.arc[i][j]==1&&!visited[j]){//寻炸i顶点未访问的邻接顶点
                        visited[j]=1;
                        printf("%c",G.vexs[j]);
                        EnQueue(&Q,j);//把邻接顶点也放入队列
                    }
                }
            }
        }
    }
}