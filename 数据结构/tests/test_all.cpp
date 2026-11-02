#include<iostream>
#include<string>
#include<time.h>
using namespace std;

#include"sqlist.h"
#include"linklist.h"
#include"sqstack.h"
#include"sqqueue.h"
#include"bitree.h"

void TestSqList(){
    SqList<string> L;
    L.ListInsert(1,"2025年羽毛球");
    L.ListInsert(2,"世锦赛冠军是");
    L.ListInsert(3,"石宇奇！");
    cout<<L.GetLength()<<endl;
    string s;
    L.GetElem(3,s);
    cout<<s<<endl;
}

void PrintList(const LinkList<int> &L){
    cout<<"表长 "<<L.GetLength()<<": ";
    for(int i=1;i<=L.GetLength();i++){
        int e;
        L.GetElem(i,e);
        cout<<e<<" ";
    }
    cout<<endl;
}

void TestLinkList(){
    srand(time(0));   // 随机种子全程设一次就行

    LinkList<int> L;

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
    int e;
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
}

void TestSqStack(){
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
    if(Si.Pop(ei)==false){
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
}

void TestSqQueue(){
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

    while(Q.Empty()==false){
        Q.DeQueue(e);
    }
    cout<<"全部出队后：";
    Q.Print();  // 空队列

    if(Q.DeQueue(e)==false){
        cout<<"空队列出队失败，符合预期"<<endl;
    }

    // ===== 验证"环形"这件事 =====
    // maxsize 是 1000，但队列最多只能放 999 个元素
    SqQueue<int> R;
    for(int i=1;i<=SqQueue<int>::maxsize-1;i++){  // 从 1 塞到 999
        R.EnQueue(i);
    }
    cout<<"塞满后长度："<<R.GetLength()<<endl;  // 999
    if(R.EnQueue(9999)==false){
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
}

void TestBiTree(){
    BiTree<char> t;
    t.Create("ABC###DE##F##");

    cout<<"先序：";
    t.PreOrder();
    cout<<endl;

    cout<<"中序（递归版）：";
    t.InOrder();
    cout<<endl;

    cout<<"中序（非递归版）：";
    t.InOrderPlus();
    cout<<endl;

    cout<<"后序：";
    t.PostOrder();
    cout<<endl;
}

int main(){
    TestSqList();
    TestLinkList();
    TestSqStack();
    TestSqQueue();
    TestBiTree();
    return 0;
}