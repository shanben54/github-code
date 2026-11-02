#ifndef SQSTACK_H
#define SQSTACK_H

#include<iostream>

template<typename T>//模板
class SqStack{
private:
    static constexpr int maxsize=1000;
    T data[maxsize];//储存栈的数据
    int top;//栈顶下标，栈空时为-1

public:
    SqStack();
    bool Push(const T &e);
    bool Pop(T &e);
    bool Empty()const;
    bool GetTop(T &e)const;
    int Length()const;
    void ClearStack();
    void Print()const;
};

//栈构造函数
template<typename T>
SqStack<T>::SqStack(){
    top=-1;
}

//添加栈顶元素
template<typename T>
bool SqStack<T>::Push(const T &e){
    if(top==maxsize-1) return false;
    top++;
    data[top]=e;
    return true;
}

//取出栈顶元素
template<typename T>
bool SqStack<T>::Pop(T &e){
    if(top==-1) return false;
    e=data[top];
    top--;
    return true;
}

//判断栈是否为空
template<typename T>
bool SqStack<T>::Empty()const{
    return top==-1?true:false;
}

//获取栈的长度
template<typename T>
int SqStack<T>::Length()const{
    return top+1;
}

//获取栈顶元素，不取出
template<typename T>
bool SqStack<T>::GetTop(T &e)const{
    if(top==-1) return false;
    e=data[top];
    return true;
}

//清理栈
template<typename T>
void SqStack<T>::ClearStack(){
    top=-1;
}

// 从栈底到栈顶打印
template<typename T>
void SqStack<T>::Print()const{
    if(top==-1){
        std::cout<<"空栈"<<std::endl;
        return;
    }
    for(int i=0;i<=top;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}

#endif