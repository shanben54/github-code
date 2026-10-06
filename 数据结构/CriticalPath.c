//求AOE图的关键路径
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


int *etv,*ltv;//事件(顶点)最早发生时间和最迟发生时间
int *stack2;//储存拓扑排序的栈
int top2;//stcak2的指针下标

//拓扑排序
//在拓扑排序的过程中，找到所以顶点的最早发生时间
Status TopologicalSort(GraphAdjList GL){
    EdgeNode *e;
    int i,k,gettop;
    int top=0;//栈指针下标
    int count=0;//统计顶点数
    int *stack;//入度为0的顶点栈
    stack=(int *)malloc(GL->numVertexes * sizeof(int));//初始化开辟内存
    for(i=0;i<GL->numVertexes;i++){
        if(GL->adjList[i].in==0){
            stack[++top]=i;//找到入度为0的顶点入栈
        }
    }
    top2=0;
    etv=(int *)malloc(GL->numVertexes * sizeof(int));//开辟内存
    for(i=0;i<GL->numVertexes;i++){
        etv[i]=0;//初始化为0
    }
    stack2=(int *)maoolc(GL->numVertexes * sizeof(int));
    while(top!=0){
        gettop=stack[top--];//取出栈首顶点
        count++;//计数加1
        stack2[++top2]=gettop;//将取出的顶点加入拓扑排序的栈
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){//遍历当前顶点的邻接点
            k=e->adjvex;
            if(!(--GL->adjList[k].in)){
                stack[++top]=k;//入度为0的顶点加入栈里
            }
            if((etv[gettop]+e->weight)>etv[k]){
                etv[k]=etv[gettop]+e->weight;//某个事件(顶点)的最早发生时间是所有前一个顶点加权值的最大值，找到这个最大值
            }
        }
    }
    if(count<GL->numVertexes){//排序的顶点数少于总顶点数，说明存在环
        return error;
    }else{
        return ok;
    }
}

//求关键路径
/*先求出顶点的最早发生时间和最晚发生时间，边的最早最晚发生时间可以用边的来求得，如果一个边的最早发生时间和最晚发生时间相同，
那这个边就是关键活动，从头遍历所有边，找到所有关键活动，就求得了关键路径*/
void CriticalPath(GraphAdjList GL){
    EdgeNode *e;
    int i,gettop,j,k;
    int ete,lte;//活动(边)最早发生时间和最晚发生时间
    TopologicalSort(GL);//对图进行排序，求出stack2和etv
    ltv=(int *)malloc(GL->numVertexes * sizeof(int));//对ltv开辟内存
    for(i=0;i<GL->numVertexes;i++){
        ltv[i]=etv[GL->numVertexes-1];//对ltv进行初始化
    }
    while(top2!=0){
        gettop=stack2[top2--];//取出栈首顶点，也就是拓扑排序倒着取出顶点
        for(e=GL->adjList[gettop].firstedge;e;e=e->next){//遍历邻接点
            k=e->adjvex;
            if(ltv[k]-e->weight<ltv[gettop]){
                ltv[gettop]=ltv[k]+e->weight;//事件最晚发生时间就是所有邻接点减去权值的最小值，找到最小值
            }
        }
    }

    //求ete,lte和关键活动
    for(j=0;j<GL->numVertexes;j++){
        for(e=GL->adjList[j].firstedge;e;e=e->next){//从头遍历所有的边，j指向k
            k=e->adjvex;
            ete=etv[j];//活动最早发生时间就是头顶点的最早发生时间
            lte=ltv[k]-e->weight;//活动最晚发生时间就是尾顶点最晚发生时间减去权值
            if(ete==lte){//如果最早发生时间等于最晚发生时间，说明这个活动是关键活动
                printf("<v%d - v%d> length: %d\n",GL->adjList[j].data,GL->adjList[k].data,e->weight);//打印数据
            }
        }
    }
}