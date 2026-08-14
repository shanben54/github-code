#include<stdio.h>

#define maxsize 1000
typedef int TElemType;
#define ok 1
#define error 0
#define OVERFLOW -2
typedef int Status;


typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;