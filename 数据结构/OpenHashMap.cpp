//开放地址探测法的哈希表
#include<iostream>
#include<vector>
using namespace std;

template<typename K,typename V>
class OpenHashMap{
private:
    enum State {EMPTY,USED,DELETED};//槽的状态，空，使用，墓碑
    
    //每个槽的结点
    struct Entry{
        K key=K();
        V value=V();
        State state=EMPTY;
    };
    vector<Entry> table;
    size_t cnt;
    
    //计算哈希值，将key值转换成在槽数组的下标
    size_t bucketkey(const K &key)const{
        return std::hash<K>{}(key)% table.size();
    }
public:
    //构造函数
    explicit OpenHashMap(size_t count=17):table(count),cnt(0){}

    void Insert(const K &key,const V &value);
    V* Find(const K &key);
    bool Erase(const K &key);

    size_t Size()const{
        return cnt;
    }
    double factor()const{
        return (double)cnt/table.size();
    }
};

//插入函数，从哈希下标开始探测，找到key值相同的就更改，找到墓碑就标记第一个，到空槽就停止
template<typename K,typename V>
void OpenHashMap<K,V>::Insert(const K &key,const V &value){
    size_t t=bucketkey(key);
    bool isd=false;
    size_t d=0;
    while(!(table[t].state==EMPTY)){
        if(table[t].state==USED&&table[t].key==key){
            table[t].value=value;
            return ;
        }else if(isd==0&&table[t].state==DELETED){
            isd=true;
            d=t;
        }
        t=(t+1)%table.size();
    }
    cnt++;
    //如果有墓碑就使用第一个墓碑
    if(isd){
        table[d].state=USED;
        table[d].key=key;
        table[d].value=value;
    }else{//没有墓碑就使用空槽
        table[t].state=USED;
        table[t].key=key;
        table[t].value=value;
    }
}

//查找函数，遇到墓碑就继续查找直到空位
//这里不能写const，虽然没有改动类的成员，但是要传出数据的指针，外部有可能更改，所以不被允许
//而链式哈希表可以，因为那里的桶数组存储的是指针，const只保护指针不能改动，不保护指针指向的结点的数据
template<typename K,typename V>
V* OpenHashMap<K,V>::Find(const K &key){
    size_t t=bucketkey(key);
    while(table[t].state!=EMPTY){
        if(table[t].state==USED&&table[t].key==key){
            return &table[t].value;
        }
        t=(t+1)%table.size();
    }
    return nullptr;
}

//删除操作，找到键直接把槽改为墓碑
template<typename K,typename V>
bool OpenHashMap<K,V>::Erase(const K &key){
    size_t t=bucketkey(key);
    while(table[t].state!=EMPTY){
        if(table[t].state==USED&&table[t].key==key){
            table[t].state=DELETED;
            cnt--;
            return true;
        }
        t=(t+1)%table.size();
    }
    return false;
}

int main(){
    OpenHashMap<int,int> m;   //默认 17 个桶
    m.Insert(1,100);          //桶 1
    m.Insert(18,200);         //18%17=1，挤到桶 2
    m.Insert(35,300);         //35%17=1，挤到桶 3

    cout<<"Size="<<m.Size()<<"（期望 3)\n";
    cout<<"Find(1)="<<(m.Find(1)?*m.Find(1):-1)<<"（期望 100)\n";

    m.Erase(18);
    cout<<"Find(18)="<<(m.Find(18)?"还在":"已删除")<<"（期望 已删除）\n";
    cout<<"Find(35)="<<(m.Find(35)?*m.Find(35):-1)<<"（期望 300,能绕过墓碑）\n";
    cout<<"Size="<<m.Size()<<"（期望 2)\n";

    m.Insert(52,400);         //52%17=1，应该复用桶 2 的墓碑
    cout<<"Size="<<m.Size()<<"（期望 3) \n";
    cout<<"Find(52)="<<(m.Find(52)?*m.Find(52):-1)<<"（期望 400)\n";

    system("pause");
    return 0;
}