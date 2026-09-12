//哈希表(散列表)查找
#include<stdio.h>

typedef int Status;
#define OK 1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define HSAHSIZE 12//散列表长度
#define NULLKEY -32768

typedef struct{
    int *elem;//储存数据元素，动态分配数组
    int count;//元素个数
}HsahTable;

int m=0;//散列表表长

//初始化散列表
Status InitHsahTable(HsahTable *H){
    int i;
    m=HSAHSIZE;
    H->count=m;
    H->elem=(int *)malloc(m*sizeof(int));//开辟内存，elem指向这块连续内存的首位
    for(i=0;i<m;i++){
        H->elem[i]=NULLKEY;//初始化数组里的值，elem[i]指的是elem指向的第i快内存的数据
    }
    return OK;
}

//散列函数
int Hash(int key){
    return key%m;//取模法
}

//插入关键字进散列表
void InsertHash(HsahTable *H,int key){
    int addr=Hash(key);//计算散列地址
    while(H->elem[addr]!=NULLKEY){//如果地址数据不为空，则冲突
        addr=(addr+1)%m;//开放地址法的线性探测
    }
    H->elem[addr]=key;//有空位就插入关键字
}

//散列表查找关键字
Status SearchHash(HsahTable H,int key,int *addr){
    *addr=Hash(key);//求散列地址
    while(H.elem[*addr]!=key){//如果地址数据不是要查找的关键字，则冲突
        *addr=(*addr+1)%m;//开放地址法的线性探测
        if(H.elem[*addr]==NULLKEY||*addr==Hash(key)){//如果找到了一块空数据或者循环回到原点
            return UNSUCCESS;//说明此关键字不存在
        }
    }
    return SUCCESS;
}