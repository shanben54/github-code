//顺序队列的cpp复现
#include<iostream>
#include<string>
using namespace std;

typedef int Status;
const int ok=1;
const int error=0;
const int maxsize=1000;

template<typename T>
class SqQueue{
private:
    T s[maxsize];//储存数据的数组
    int front;//头指针，指向队列第一个元素
    int rear;//尾指针，指向队列最后一个元素的下一个位置
    
public:
    SqQueue();
    Status Empty()const;
    Status Full()const;
    Status EnQueue(const T &e);
    Status DeQueue(T &e);
    Status GetFront(T &e)const;
    int GetLength()const;
    void ClearQueue();
    void Print()const;
};

//构造函数，初始化头尾指针都在0
template<typename T>
SqQueue<T>::SqQueue(){
    front=0;
    rear=0;
}

//判断队列是否为空，头尾指针相同为空
template<typename T>
Status SqQueue<T>::Empty()const{
    return front==rear?ok:error;
}

//判断队列是否已满，如果尾指针下一位是头指针就为满，虽然浪费了一个尾指针的空间，但是可以和判空做区分
template<typename T>
Status SqQueue<T>::Full()const{
    return (rear+1)%maxsize==front?ok:error;//取余，因为是在数组里循环
}

//在队尾添加元素
template<typename T>
Status SqQueue<T>::EnQueue(const T &e){
    if(Full()==ok) return error;
    s[rear]=e;
    rear=(rear+1)%maxsize;
    return ok;
}

//取出队首元素
template<typename T>
Status SqQueue<T>::DeQueue(T &e){
    if(Empty()==ok) return error;
    e=s[front];
    front=(front+1)%maxsize;
    return ok;
}

//获取队首元素，不取出
template<typename T>
Status SqQueue<T>::GetFront(T &e)const{
    if(Empty()==ok) return error;
    e=s[front];
    return ok;
}

//获取队列长度
template<typename T>
int SqQueue<T>::GetLength()const{
    return (rear-front+maxsize)%maxsize;//加上数组长度再取余，因为如果减出来是负数取余的话结果是负数
}

//清空队列
template<typename T>
void SqQueue<T>::ClearQueue(){
    rear=0;
    front=0;
}

// 从队头到队尾打印
// 注意不能用 i<rear 当条件，队尾可能已经绕回数组开头了
template<typename T>
void SqQueue<T>::Print()const{
    if(Empty()==ok){
        cout<<"空队列"<<endl;
        return;
    }
    for(int i=front;i!=rear;i=(i+1)%maxsize){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

int main(){
    SqQueue<int> Q;
    int e;

    Q.EnQueue(1);
    Q.EnQueue(2);
    Q.EnQueue(3);
    cout<<"入队 1 2 3 后：";
    Q.Print();  // 1 2 3
    cout<<"当前长度："<<Q.GetLength()<<endl;  // 3

    Q.GetFront(e);
    cout<<"队头元素："<<e<<endl;  // 1

    Q.DeQueue(e);
    cout<<"出队元素："<<e<<"，出队后：";
    Q.Print();  // 2 3

    while(Q.Empty()==error){
        Q.DeQueue(e);
    }
    cout<<"全部出队后：";
    Q.Print();  // 空队列

    if(Q.DeQueue(e)==error){
        cout<<"空队列出队失败，符合预期"<<endl;
    }

    // ===== 验证"环形"这件事 =====
    // maxsize 是 1000，但队列最多只能放 999 个元素
    SqQueue<int> R;
    for(int i=1;i<=maxsize-1;i++){  // 从 1 塞到 999
        R.EnQueue(i);
    }
    cout<<"塞满后长度："<<R.GetLength()<<endl;  // 999
    if(R.EnQueue(9999)==error){
        cout<<"已满，再入队失败，符合预期"<<endl;
    }

    // 出队 5 个，再从队尾塞 5 个 —— 这时 rear 会绕回数组开头
    for(int i=0;i<5;i++){
        R.DeQueue(e);
    }
    for(int i=0;i<5;i++){
        R.EnQueue(1000+i);
    }
    cout<<"绕回一圈后长度："<<R.GetLength()<<endl;  // 还是 999
    R.GetFront(e);
    cout<<"队头元素："<<e<<endl;  // 6（1~5 已经出队了）

    // ===== 换成 string 也一样用 =====
    SqQueue<string> S;
    S.EnQueue("王子");
    S.EnQueue("在学");
    S.EnQueue("循环队列");
    cout<<"string 队列：";
    S.Print();  // 王子 在学 循环队列

    string es;
    S.GetFront(es);
    cout<<"队头元素："<<es<<endl;  // 王子

    S.DeQueue(es);
    cout<<"出队元素："<<es<<"，出队后：";
    S.Print();  // 在学 循环队列

    S.ClearQueue();
    cout<<"清空后长度："<<S.GetLength()<<endl;  // 0

    system("pause");
    return 0;
}