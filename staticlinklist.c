#include<stdio.h>

#define maxsize 100
typedef int ElemType;
#define ok 1
#define error 0
typedef int Status;


typedef struct{
    ElemType data;
    int cur;
}Component,StaticLinkList[maxsize];