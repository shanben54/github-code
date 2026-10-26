//哈希表(散列表)的cpp复现
#include<iostream>
#include<string>
#include<vector>
#include<functional>
using namespace std;

template<typename K,typename V>
class HashMap{
private:
    //结点，记录下键和值
    struct Node{
        K key;
        V value;
        Node* next;
        Node(const K &k,const V &v):key(k),value(v),next(nullptr){}
    };
    vector<Node*> buckets;//桶数组，储存哈希值相同的结点链表
    size_t cnt;//当前哈希表里元素数量
    
    //计算哈希值的函数，将key值转化成桶数组的下标
    size_t bucketkey(const K &key)const{
        return std::hash<K>{}(key)%buckets.size();//hash函数可以将K转化成size_t类型的数，再取模得到哈希值
    }
public:
    //构造函数，根据表长初始化桶数组，explicit禁止隐式转换
    explicit HashMap(size_t bucketcount=17):buckets(bucketcount,nullptr),cnt(0){}
    ~HashMap();
    void Insert(const K &key,const V &value);
    V* Find(const K &key)const;
    bool Erase1(const K &key);
    bool Erase2(const K &key);
    
    //返回哈希表里的元素个数
    size_t size()const{
        return cnt;
    }
    //计算装填因子，元素个数/表长
    double factor()const{
        return (double)cnt / buckets.size();
    }
};

//析构函数
template<typename K,typename V>
HashMap<K,V>::~HashMap(){
    for(size_t i=0;i<buckets.size();i++){
        Node* p=buckets[i];
        while(p){
            Node* q=p;
            p=p->next;
            delete q;
        }
    }
}

//插入键值
template<typename K,typename V>
void HashMap<K,V>::Insert(const K &key,const V &value){
    size_t t=bucketkey(key);
    Node* p=buckets[t];
    //寻找是否已有key键的元素
    while(p){
        if(p->key==key) break;
        p=p->next;
    }
    if(p){
        p->value=value;//找到直接更改值
    }else{//没找到就新建结点，用头插法
        p=new Node(key,value);
        p->next=buckets[t];
        buckets[t]=p;
        cnt++;
    }
}

//寻找键，返回值
template<typename K,typename V>
V* HashMap<K,V>::Find(const K &key)const{
    size_t t=bucketkey(key);
    Node* p=buckets[t];
    while(p){
        if(p->key==key){
            return &p->value;
        }
        p=p->next;
    }
    return nullptr;
}

//删除操作1
//先创建一个头结点再找前驱删除结点
template<typename K,typename V>
bool HashMap<K,V>::Erase1(const K &key){
    size_t t=bucketkey(key);
    Node* head=new Node(K(),V());//新建一个头结点，便于删除第一个元素
    head->next=buckets[t];
    Node* pre=head;//前驱
    Node* p=buckets[t];
    while(p){
        if(p->key==key){
            pre->next=p->next;
            delete p;
            cnt--;
            buckets[t]=head->next;//更新一下桶数组
            delete head;
            return true;
        }
        pre=p;
        p=p->next;
    }
    delete head;
    return false;
}

//删除操作2
//用二级指针，可以直接更改指针指向的结点，不用找前驱就可以直接将结点从链表中取出
template<typename K,typename V>
bool HashMap<K,V>::Erase2(const K &key){
    size_t t=bucketkey(key);
    Node** pp=&buckets[t];
    while(*pp){
        if((*pp)->key==key){
            Node* q=*pp;
            *pp=(*pp)->next;
            delete q;
            cnt--;
            return true;
        }
        pp=&(*pp)->next;
    }
    return false;
}

int main(){
    HashMap<int,int> h(17);
    h.Insert(1,54);
    h.Insert(18,7);
    h.Insert(35,87);

    cout<<h.Erase2(1)<<endl;
    cout<<(h.Find(18)&&*h.Find(18)==7)<<endl;
    cout<<h.size()<<endl;

    cout<<h.Erase1(18)<<endl;
    cout<<(h.Find(35)&&*h.Find(35)==87)<<endl;
    cout<<h.Erase1(35)<<endl;
    cout<<h.size()<<endl;

    return 0;
}