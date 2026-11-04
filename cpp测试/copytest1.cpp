#include<iostream>
#include"linklist.h"

int main(){
    LinkList<int> a;
    a.HeadInsert(3);
    LinkList<int> b=a;
    std::cout<<"b的长度"<<a.GetLength()<<std::endl;
    int e;
    b.LinkListDelete(1,e);
    std::cout<<"删除1个结点后a的长度"<<a.GetLength()<<std::endl;
    std::cout<<"b的长度"<<b.GetLength()<<std::endl;
    return 0;
}