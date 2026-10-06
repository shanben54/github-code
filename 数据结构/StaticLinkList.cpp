//静态链表的cpp实现
#include<iostream>
#include<cstdlib>
using namespace std;

const int MAXSIZE=100;
template<typename T>
class StaticLinkList{
private:
    
    //结点数据定义
    struct Component{
        T data;
        int cur;//后继
    };

    Component s[MAXSIZE];
    int length;//链表长度，可以直接判断i的值是否合理
    
    //从空闲链表里申请一个新结点，如果没有空闲位置就返回0
    int Malloc_S(){
        int i=s[0].cur;//指向空闲链表第一个
        if(i!=0){
            s[0].cur=s[i].cur;//将这个结点从空闲链表里划分出去
        }
        return i;
    }
    
    //将结点放入空闲数组
    void Free_S(int i){
        s[i].cur=s[0].cur;
        s[0].cur=i;
    }

public:
    
    //构造函数
    StaticLinkList(){
        //将数组里所有元素都接入空闲链表
        s[0].cur=1;
        for(int i=1;i<MAXSIZE-2;i++){
            s[i].cur=i+1;
        }
        s[MAXSIZE-2].cur=0;//空闲链表的末尾指回0
        s[MAXSIZE-1].cur=0;//数据链表为空
        length=0;//长度为0
    }
    
    //返回链表长度
    int GetLength()const{
        return length;
    }
    
    //获取第i个元素的值
    bool GetElem(int i,T &e)const{
        if(i<1||i>length) return false;
        int k=MAXSIZE-1;//数据链表的头结点
        for(int j=1;j<=i;j++){
            k=s[k].cur;
        }
        //循环结束后k指向第i个元素
        e=s[k].data; 
        return true;
    }
    
    //在第i个位置添加结点
    bool ListInsert(int i,const T &e){
        if(i<1||i>length+1) return false;
        int j=Malloc_S();//申请空闲结点
        if(j==0) return false;//说明没有空闲结点了
        int k=MAXSIZE-1;
        for(int a=1;a<=i-1;a++){
            k=s[k].cur;
        }
        //循环结束后k指向第i-1个结点
        //将j链接进链表
        s[j].data=e;
        s[j].cur=s[k].cur;
        s[k].cur=j;
        length++;//更新长度
        return true;
    }
    
    //删除第i个结点
    bool ListDelete(int i,T &e){
        if(i<1||i>length) return false;
        int k=MAXSIZE-1;
        for(int l=1;l<=i-1;l++){
            k=s[k].cur;
        }
        int j=s[k].cur;//j就是第i个元素
        e=s[j].data;
        s[k].cur=s[j].cur;
        Free_S(j);//将j结点放入空闲链表
        length--;//更新长度
        return true;
    }

    // 打印整表：从数据链表的头结点出发，顺着游标一路走
    void PrintList()const{
        cout<<"表长 "<<length<<": ";
        for(int p=s[MAXSIZE-1].cur;p!=0;p=s[p].cur){
            cout<<s[p].data<<" ";
        }
        cout<<endl;
    }
};

int main(){
    StaticLinkList<int> L;

    for(int v=10;v<=50;v+=10){
        L.ListInsert(L.GetLength()+1,v);   // 尾插
    }
    L.PrintList();

    L.ListInsert(2,15);
    L.PrintList();

    int e;
    if(L.GetElem(3,e)) cout<<"第 3 个元素: "<<e<<endl;

    if(L.ListDelete(1,e)) cout<<"删掉第 1 个: "<<e<<endl;
    L.PrintList();

    system("pause");
    return 0;
}