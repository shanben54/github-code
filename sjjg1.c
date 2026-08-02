#include<stdio.h>

#define maxsize 20
typedef int ElemType;
//定义线性表，具有两个属性，一个是储存数据的数组，一个是线性表的长度
typedef struct{
    ElemType date[maxsize];
    int length;
}SqList;

#define ok 1
#define error 0
typedef int Status;

//获取线性表第i个元素的函数
Status GetElem(SqList L,int i,ElemType *e){
    if(L.length==0||i<1||i>L.length) return error;//如果线性表为空或者i不合规就报错
    *e=L.date[i-1];//将第i个元素的值赋给指针e,数组是从0开始的，而第几个元素是从1开始的，所有要返回[i-1]的值
    return ok;
}
//在第i个位置添加值为e的元素的函数
Status ListInsert(SqList *L,int i,ElemType e){
    int k;
    if(L->length==maxsize) return error;//如果线性表长度已经最大了就不能添加
    if(i<1||i>L->length+1) return error;//如果i的值不合规也添加不了，这里之所以是length+1,是英文如果i=length+1,说明直接在末尾加入
    if(i<=L->length){
        //把第i个元素之后（包括第i个元素）的元素都向后传递一位
        for(k=L->length-1;k>=i-1;k--){
            L->date[k+1]=L->date[k];
        }
    }//如果i=length+1就不管
    L->date[i-1]=e;//第i个位置赋值e
    L->length++;//线性表长度更新
    return ok;
}

Status ListDelete(SqList *L,int i,ElemType *e){
    int k;
    if(L->length==0) return error;
    if(i<1||i>L->length) return error;
    *e=L->date[i-1];
    if(i<L->length){
        for(k=i;k<L->length;k++){
            L->date[k-1]=L->date[k];
        }
    }
    L->length--;
    return ok;
}