#include<stdio.h>

#define maxsize 1000
typedef int TElemType;
#define ok 1
#define error 0
#define OVERFLOW -2
typedef int Status;


//树的双亲表示法
//每个结点记录双亲的位置，查找双亲时很方便，但是要找到结点的孩子有哪些比较麻烦
typedef struct PTNode{
    TElemType data;//结点数据
    int parent;//结点的双亲数组下标
}PTNode;//每一个结点

typedef struct{
    PTNode nodes[maxsize];//结点数组
    int r,n;//根的位置和结点数
}PTree;


//树的孩子表示法
//每个结点储存孩子的位置，孩子结点用链表方式串联起来，因为每个结点孩子数不一样，这样储存不会浪费空间
typedef struct CTNode{//孩子结点
    int child;//表示这个孩子结点在数组里的下标
    struct CTNode *next;//指向下一个孩子结点
} *ChildPtr;

typedef struct{
    TElemType data;//这个结点的数据
    ChildPtr firstchild;//结点的第一个孩子
}CTBox;

typedef struct{
    CTBox nodes[maxsize];//结点数组
    int r,n;//根的位置和结点数
}CTree;
//这样查找结点的孩子时非常清楚，但是找结点双亲时比较麻烦
//所以可以在结点CTBox里加上一个int parent，表示结点的双亲，这样就是双亲孩子表示法


//树的孩子兄弟表示法
//每个结点只指向第一个孩子和右兄弟，要查询的话就根据这两个数据一直查询，这样把一个正常的图转化成了一个二叉树
typedef struct CSNode{
    TElemType data;//结点的数据
    struct CSNode *firstchild,*rightsib;//这个结点的第一个孩子和右兄弟
}CSNode,*CSTree;