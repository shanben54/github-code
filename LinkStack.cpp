//链表栈的cpp复现
#include<iostream>
#include<string>
using namespace std;

typedef int Status;
const int ok=1;
const int error=0;

//结点定义
template<typename T>//模板
struct ListNode{
    T data;
    ListNode* next;
    ListNode(const T &v):data(v),next(nullptr){}//构造函数
};

template<typename T>
class ListStack{
private:
    ListNode<T>* top;//栈顶指针
    int count;//栈元素个数
public:
    ListStack();
    ~ListStack();
    Status Push(const T &e);
    Status Pop(T &e);
    Status Empty()const;
    Status GetTop(T &e)const;
    void ClearStack();
    int GetLength()const;
    void Print()const;
};

//栈构造函数
template<typename T>
ListStack<T>::ListStack(){
    top=nullptr;
    count=0;
}

//栈析构函数
template<typename T>
ListStack<T>::~ListStack(){
    ClearStack();
}

//添加元素，头插法，这样方便删除栈顶元素可以直接链接下一个元素
template<typename T>
Status ListStack<T>::Push(const T &e){
    ListNode<T>* p=new ListNode<T>(e);
    p->next=top;
    top=p;
    count++;
    return ok;
}

//取出栈顶元素
template<typename T>
Status ListStack<T>::Pop(T &e){
    if(Empty()==ok) return error;
    ListNode<T>* p=top;
    e=top->data;
    top=top->next;
    delete p;
    count--;
    return ok;
}

//获取栈顶元素，不改动
template<typename T>
Status ListStack<T>::GetTop(T &e)const{
    if(Empty()==ok) return error;
    e=top->data;
    return ok;
}

//判断栈是否为空
template<typename T>
Status ListStack<T>::Empty()const{
    return top==nullptr?ok:error;
}

//获取栈的元素个数
template<typename T>
int ListStack<T>::GetLength()const{
    return count;
}

//清除栈
template<typename T>
void ListStack<T>::ClearStack(){
    while (top!=nullptr)
    {
        ListNode<T>* p=top;
        top=top->next;
        delete p;
    }
    count=0;
}

// 从栈顶到栈底打印（链栈只能顺着 next 走）
template<typename T>
void ListStack<T>::Print()const{
    if(top==nullptr){
        cout<<"空栈"<<endl;
        return;
    }
    ListNode<T>* p=top;
    while(p!=nullptr){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    // 测试 int 栈
    ListStack<int> Si;
    Si.Push(1);
    Si.Push(2);
    Si.Push(3);
    cout<<"int 栈入栈后（栈顶到栈底）：";
    Si.Print();  // 3 2 1

    cout<<"当前长度："<<Si.GetLength()<<endl;  // 3

    int ei;
    Si.GetTop(ei);
    cout<<"栈顶元素："<<ei<<endl;  // 3

    Si.Pop(ei);
    cout<<"出栈元素："<<ei<<"，出栈后：";
    Si.Print();  // 2 1

    // Empty() 返回 Status，error 表示非空
    while(Si.Empty()==error){
        Si.Pop(ei);
    }
    cout<<"全部出栈后：";
    Si.Print();  // 空栈

    // 空栈还去出栈，应该失败
    if(Si.Pop(ei)==error){
        cout<<"空栈出栈失败，符合预期"<<endl;
    }

    // 测试 string 栈
    ListStack<string> Ss;
    Ss.Push("王子");
    Ss.Push("在学");
    Ss.Push("链栈");
    cout<<"string 栈入栈后（栈顶到栈底）：";
    Ss.Print();  // 链栈 在学 王子

    string es;
    Ss.GetTop(es);
    cout<<"栈顶元素："<<es<<endl;  // 链栈

    Ss.Pop(es);
    cout<<"出栈元素："<<es<<"，出栈后：";
    Ss.Print();  // 在学 王子

    Ss.ClearStack();
    cout<<"清空后长度："<<Ss.GetLength()<<endl;  // 0

    system("pause");
    return 0;
}