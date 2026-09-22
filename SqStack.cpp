//顺序栈的cpp复现
#include<iostream>
#include<string>
using namespace std;

typedef int Status;
const int maxsize=1000;
const int error=0;
const int ok=1;

template<typename T>//模板
class SqStack{
private:
    T data[maxsize];//储存栈的数据
    int top;//栈顶下标，栈空时为-1

public:
    SqStack();
    Status Push(const T &e);
    Status Pop(T &e);
    bool Empty()const;
    Status GetTop(T &e)const;
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
Status SqStack<T>::Push(const T &e){
    if(top==maxsize-1) return error;
    top++;
    data[top]=e;
    return ok;
}

//取出栈顶元素
template<typename T>
Status SqStack<T>::Pop(T &e){
    if(top==-1) return error;
    e=data[top];
    top--;
    return ok;
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
Status SqStack<T>::GetTop(T &e)const{
    if(top==-1) return error;
    e=data[top];
    return ok;
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
        cout<<"空栈"<<endl;
        return;
    }
    for(int i=0;i<=top;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}

int main(){
    // 测试 int 栈
    SqStack<int> Si;
    Si.Push(1);
    Si.Push(2);
    Si.Push(3);
    cout<<"int 栈入栈后：";
    Si.Print();  // 1 2 3

    cout<<"当前长度："<<Si.Length()<<endl;  // 3

    int ei;
    Si.GetTop(ei);
    cout<<"栈顶元素："<<ei<<endl;  // 3

    Si.Pop(ei);
    cout<<"出栈元素："<<ei<<"，出栈后：";
    Si.Print();  // 1 2

    // Empty() 现在返回 bool，直接取非就行
    while(!Si.Empty()){
        Si.Pop(ei);
    }
    cout<<"全部出栈后：";
    Si.Print();  // 空栈

    // 空栈还去出栈，应该失败
    if(Si.Pop(ei)==error){
        cout<<"空栈出栈失败，符合预期"<<endl;
    }

    // 测试 string 栈
    SqStack<string> Ss;
    Ss.Push("王子");
    Ss.Push("在学");
    Ss.Push("数据结构");
    cout<<"string 栈入栈后：";
    Ss.Print();  // 王子 在学 数据结构

    string es;
    Ss.GetTop(es);
    cout<<"栈顶元素："<<es<<endl;  // 数据结构

    Ss.Pop(es);
    cout<<"出栈元素："<<es<<"，出栈后：";
    Ss.Print();  // 王子 在学

    Ss.ClearStack();
    cout<<"清空后长度："<<Ss.Length()<<endl;  // 0

    system("pause");
    return 0;
}