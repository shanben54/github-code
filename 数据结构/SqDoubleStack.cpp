//顺序栈的两栈共享空间的Cpp复现
#include<iostream>
#include<string>
using namespace std;

typedef int Status;
const int maxsize=1000;
const int ok=1;
const int error=0;

template<typename T>
class SqDoubleStack{
private:
    T data[maxsize];//数据空间
    int top1;//栈1头指针，-1时为空
    int top2;//栈2头指针，maxsize时为空
public:
    SqDoubleStack();
    Status Push(const T &e,int StackNumber);
    Status Pop(T &e,int StackNumber);
    Status GetTop(T &e,int StackNumber)const;
    Status Empty(int StackNumber)const;
    Status Length(int &l,int StackNumber)const;
    Status Clear(int StackNumber);
    void Print(int StackNumber)const;
};

//构造函数，初始化两个栈的头指针
template<typename T>
SqDoubleStack<T>::SqDoubleStack(){
    top1=-1;
    top2=maxsize;
}

//在栈首添加元素
template<typename T>
Status SqDoubleStack<T>::Push(const T &e,int StackNumber){
    if(top1+1==top2) return error;//栈满
    if(StackNumber==1){
        data[++top1]=e;//注意是先增再添加数据
    }else if(StackNumber==2){
        data[--top2]=e;
    }else{
        return error;
    }
    return ok;
}

//取出栈首元素
template<typename T>
Status SqDoubleStack<T>::Pop(T &e,int StackNumber){
    if(StackNumber==1){
        if(top1==-1) return error;
        e=data[top1--];//这里是先取出元素再减
    }else if(StackNumber==2){
        if(top2==maxsize) return error;
        e=data[top2++];
    }else{
        return error;
    }
    return ok;
}

//获取栈首元素，不取出
template<typename T>
Status SqDoubleStack<T>::GetTop(T &e,int StackNumber)const{
    if(StackNumber==1){
        if(top1==-1) return error;
        e=data[top1];
    }else if(StackNumber==2){
        if(top2==maxsize) return error;
        e=data[top2];
    }else{
        return error;
    }
    return ok;
}

//判断栈是否为空
template<typename T>
Status SqDoubleStack<T>::Empty(int StackNumber)const{
    if(StackNumber==1){
        return top1==-1?ok:error;
    }else if(StackNumber==2){
        return top2==maxsize?ok:error;
    }
    else{
        return error;
    }
}

//获取栈的长度
template<typename T>
Status SqDoubleStack<T>::Length(int &l,int StackNumber)const{
    if(StackNumber==1){
        l=top1+1;
    }
    else if(StackNumber==2){
        l=maxsize-top2;
    }else{
        return error;
    }
    return ok;
}

//清空栈
template<typename T>
Status SqDoubleStack<T>::Clear(int StackNumber){
    if(StackNumber==1){
        top1=-1;
    }else if(StackNumber==2){
        top2=maxsize;
    }else{
        return error;
    }
    return ok;
}

// 从栈底到栈顶打印
// 栈1 顺着数组往右走；栈2 是往左长的，所以要倒着走
template<typename T>
void SqDoubleStack<T>::Print(int StackNumber)const{
    if(StackNumber==1){
        if(top1==-1){
            cout<<"栈1空"<<endl;
            return;
        }
        for(int i=0;i<=top1;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }else if(StackNumber==2){
        if(top2==maxsize){
            cout<<"栈2空"<<endl;
            return;
        }
        for(int i=maxsize-1;i>=top2;i--){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    SqDoubleStack<int> S;
    int e, len1, len2;

    // ===== 两个栈各用各的 =====
    S.Push(1, 1);
    S.Push(2, 1);
    S.Push(3, 1);
    S.Push(100, 2);
    S.Push(200, 2);
    cout<<"栈1（从底到顶）：";
    S.Print(1);  // 1 2 3
    cout<<"栈2（从底到顶）：";
    S.Print(2);  // 100 200

    S.Length(len1, 1);
    S.Length(len2, 2);
    cout<<"栈1长度："<<len1<<"，栈2长度："<<len2<<endl;  // 3 和 2

    S.GetTop(e, 1);
    cout<<"栈1栈顶："<<e<<endl;  // 3
    S.GetTop(e, 2);
    cout<<"栈2栈顶："<<e<<endl;  // 200

    // 栈1出栈 —— 验证 if(top1==-1) 那处改动
    S.Pop(e, 1);
    cout<<"栈1出栈："<<e<<"，出栈后：";
    S.Print(1);  // 1 2

    // 栈2出到空
    S.Pop(e, 2);
    S.Pop(e, 2);
    if(S.Pop(e, 2)==error){
        cout<<"栈2空了，再出栈失败，符合预期"<<endl;
    }

    // ===== 关键：两个栈共用一个数组，能一起把数组塞满 =====
    // 500 + 500 = 1000，正好用满，不像单栈那样要浪费一个格子
    SqDoubleStack<int> R;
    for(int i=0;i<500;i++){
        R.Push(i, 1);
    }
    for(int i=0;i<500;i++){
        R.Push(i, 2);
    }
    R.Length(len1, 1);
    R.Length(len2, 2);
    cout<<"塞满后 栈1长度："<<len1<<"，栈2长度："<<len2<<endl;  // 500 500

    if(R.Push(9999, 1)==error){
        cout<<"两个栈加起来正好填满数组，再入栈失败，符合预期"<<endl;
    }

    // 从栈2腾一个位置出来，栈1立刻就能用（这块空间是两端抢的）
    R.Pop(e, 2);
    if(R.Push(9999, 1)==ok){
        cout<<"栈2出栈一个后，栈1又能入栈了"<<endl;
    }

    // 非法编号
    if(R.Push(1, 3)==error){
        cout<<"非法栈号 3 被拒绝了"<<endl;
    }

    // 清空栈1后再看长度 —— 验证 top1=-1 那处改动
    R.Clear(1);
    R.Length(len1, 1);
    cout<<"清空栈1后长度："<<len1<<endl;  // 0

    // ===== 换成 string =====
    SqDoubleStack<string> Q;
    Q.Push("王子", 1);
    Q.Push("在学", 1);
    Q.Push("共享栈", 2);
    Q.Push("很有意思", 2);
    cout<<"string 栈1：";
    Q.Print(1);  // 王子 在学
    cout<<"string 栈2：";
    Q.Print(2);  // 共享栈 很有意思

    string es;
    Q.Pop(es, 2);
    cout<<"栈2出栈："<<es<<"，出栈后：";
    Q.Print(2);  // 共享栈

    while(Q.Empty(1)==error){
        Q.Pop(es, 1);
    }
    cout<<"栈1全部出栈后：";
    Q.Print(1);  // 栈1空

    system("pause");
    return 0;
}