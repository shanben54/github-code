//unordered_map和map自定义key
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

//自定义的key类型
struct Point{
    int x,y;

    //map需要比较key大小，所以需要定义一个比较函数
    bool operator<(const Point &o)const{//const不能少
        if(x!=o.x) return x<o.x;
        return y<o.y;
    }
    
    //unordered_map需要判断是不是同一个key
    bool operator==(const Point &o)const{
        return x==o.x&&y==o.y;
    }
};

//unordered_map需要使用hash函数来计算桶下标，所以需要自己写一个利用point来计算哈希值的函数
namespace std{
    template<>
    struct hash<Point>{
        size_t operator()(const Point &o) const noexcept{//使hash结构体可以直接当函数来用，noexcept向编译器保证不抛异常
            size_t h1=hash<int>{}(o.x);//利用原来的hash函数来计算，用{}创建一个临时对象然后调用
            size_t h2=hash<int>{}(o.y);
            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));//将h1和h2打乱生成哈希值减少冲突
        }
    };
}

int main(){
    unordered_map<Point,int> mu;
    map<Point,int> mo;

    mu.insert({{3,1},1});
    mo.insert({{3,1},1});
    mu.insert({{7,8},91});
    mo.insert({{7,8},91});
    mu.insert({{9,1},78});
    mo.insert({{9,1},78});
    mu.insert({{6,7},67});
    mo.insert({{6,7},67});
    mu.insert({{3,1},1});
    mo.insert({{3,1},1});
    mu.insert({{5,4},54});
    mo.insert({{5,4},54});
    cout<<"插入后长度 unordered_map:"<<mu.size()<<" map:"<<mo.size()<<endl;
    auto it1=mu.find({3,1});
    auto it2=mu.find({1,3});
    cout<<"查找(3,1):"<<(it1==mu.end()?"没找到":"找到了")<<" 查找(1,3):"<<(it2==mu.end()?"没找到":"找到了")<<endl;
    for(auto x:mo){
        cout<<"("<<x.first.x<<","<<x.first.y<<")  "<<x.second<<endl;
    }
    return 0;
}