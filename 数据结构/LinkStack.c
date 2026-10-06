#include<stdio.h>

#define maxsize 1000
typedef int SElemType;
#define ok 1
#define error 0
typedef int Status;

//链式结构的栈
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct{
    LinkStackPtr top;
    int count;
}LinkStack;

//判断栈是否为空的函数
Status StackEmpty(LinkStack S){
    if(S.count==0) return ok;
    else return error;
}

//在栈顶插入元素e
//和顺序链表不同，栈顶是头结点，然后依次链接下去
Status Push(LinkStack *S,SElemType e){
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));//新建一个结点用于储存元素e
    s->data=e;
    s->next=S->top;//top相当于头结点，是链表的开始
    S->top=s;//更新top指向的结点
    S->count++;//栈的长度增加
    return ok;
}

//删除栈顶的元素
Status Pop(LinkStack *S,SElemType *e){
    LinkStackPtr p;
    if(StackEmpty(*S)){
        return error;
    }//如果栈是空的就报错
    *e=S->top->data;//把栈顶元素的值赋给e
    p=S->top;
    S->top=S->top->next;//更新栈顶的元素，即原本栈顶的下一位
    free(p);//把原本栈顶的结点释放
    S->count--;//栈的长度减小
    return ok;
}