//链表的cpp实现
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

typedef int ElemType;

class LinkList{
private:
    //定义结点
    struct Node
    {
        ElemType data;
        Node* next;
        Node(ElemType v):data(v),next(nullptr){}//结点的构造函数，初始next为nullptr
    };
    Node* Head;//头结点，next指向第一个结点

public:
    //构造函数，先构造一个头结点出来
    LinkList():Head(new Node(0)){}
    
    //析构函数，清理结点，删除头结点
    ~LinkList(){
        ClearList();
        delete Head;
    }
    
    //获取链表长度，从第一个结点开始遍历然后计数增加
    int GetLength()const{
        Node* p=Head->next;//指向第一个结点
        int n=0;
        while(p!=nullptr){
            p=p->next;
            n++;
        }
        return n;
    }
    
    //获取第i个结点的数据
    bool GetElem(int i,ElemType &e)const{
        if(i<1) return false;//注意i不合理的判别，最开始就忘了写
        Node* p=Head->next;
        int j=1;
        while(p!=nullptr&&j<i){
            p=p->next;
            j++;
        }
        //循环结束后p指向第i个结点
        if(p==nullptr) return false;//长度没有i就报错
        e=p->data;
        return true;
    }
    
    //在第i个位置添加结点
    bool LinkListInsert(int i,ElemType e){
        if(i<1) return false;
        Node* p=Head;
        int j=1;
        while(p!=nullptr&&j<i){
            p=p->next;
            j++;
        }
        //循环结束后p指向第i-1个结点
        if(p==nullptr) return false;
        Node* s=new Node(e);//新建结点
        //将结点链接到链表里
        s->next=p->next;
        p->next=s;
        return true;
    }
    
    //删除第i个结点
    bool LinkListDelete(int i,ElemType &e){
        if(i<1) return false;
        Node* p=Head;
        int j=1;
        while(p!=nullptr&&j<i){
            p=p->next;
            j++;
        }
        if(p==nullptr||p->next==nullptr) return false;
        Node* q=p->next;
        e=q->data;
        p->next=q->next;
        delete q;
        return true;
    }
    
    //头插法
    bool HeadInsert(int n){
        ClearList();
        Node* p=Head->next;//p指向结点第一个数据
        for(int i=0;i<n;i++){
            Node* q=new Node(rand()%100+1);
            q->next=p;
            p=q;
        }
        Head->next=p;//把链表和头结点链接起来
        return true;
    }
    
    //尾插法
    bool TailInsert(int n){
        ClearList();
        Node* p=Head;//p指向结点最后一个数据
        for(int i=0;i<n;i++){
            Node* q=new Node(rand()%100+1);
            p->next=q;
            p=q;
        }
        p->next=nullptr;//封尾
        return true;
    }
    
    //清除链表
    bool ClearList(){
        Node* p=Head->next;
        //遍历所有结点，然后清除
        while(p!=nullptr){
            Node* q=p;
            p=p->next;
            delete q;
        }
        //更新头结点指向
        Head->next=nullptr;
        return true;
    }
};

// 遍历打印整条链
// 类里没有暴露结点，所以只能靠公开接口 GetLength + GetElem 一个个取出来
void PrintList(const LinkList &L){
    cout<<"表长 "<<L.GetLength()<<": ";
    for(int i=1;i<=L.GetLength();i++){
        ElemType e;
        L.GetElem(i,e);
        cout<<e<<" ";
    }
    cout<<endl;
}

int main(){
    srand(time(0));   // 随机种子全程设一次就行

    LinkList L;

    cout<<"=== 1. 尾插法建表 5 个 ==="<<endl;
    L.TailInsert(5);
    PrintList(L);

    cout<<"=== 2. 头插法建表 5 个（会清掉上面那条）==="<<endl;
    L.HeadInsert(5);
    PrintList(L);

    cout<<"=== 3. 插入 ==="<<endl;
    L.LinkListInsert(1,999);                  // 插到最前面
    PrintList(L);
    L.LinkListInsert(L.GetLength()+1,888);    // 插到最后面
    PrintList(L);

    cout<<"=== 4. 取元素 ==="<<endl;
    ElemType e;
    if(L.GetElem(3,e)) cout<<"第 3 个元素: "<<e<<endl;
    if(!L.GetElem(100,e)) cout<<"取第 100 个失败（越界）"<<endl;

    cout<<"=== 5. 删除 ==="<<endl;
    if(L.LinkListDelete(1,e)) cout<<"删掉第 1 个: "<<e<<endl;
    PrintList(L);
    if(!L.LinkListDelete(100,e)) cout<<"删第 100 个失败（越界）"<<endl;

    cout<<"=== 6. 清空 ==="<<endl;
    L.ClearList();
    cout<<"清空后表长: "<<L.GetLength()<<endl;
    PrintList(L);

    system("pause");
    return 0;
}