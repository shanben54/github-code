//自制vector数组
#include<iostream>
#include<utility>
using namespace std;;

template<typename T>
class MyVector{
private:
    T* data_;//数据数组
    size_t size_;//数组大小
    size_t capacity_;//数组容量
public:
    MyVector(){
        size_=0;
        capacity_=0;
        data_=nullptr;
    }
    //拷贝构造
    MyVector(const MyVector &o){
        size_=o.size_;
        capacity_=o.size_;
        data_=new T[capacity_];
        for(size_t i=0;i<size_;i++){
            data_[i]=o.data_[i];
        }
    }
    //拷贝赋值
    MyVector& operator=(const MyVector &o){
        MyVector tmp=o;
        swap(tmp.capacity_,capacity_);
        swap(tmp.data_,data_);
        swap(tmp.size_,size_);
        return *this;
    }
    ~MyVector(){
        delete[] data_;
    }
    size_t size()const;
    size_t capacity()const;
    bool empty()const;
    T& operator[](size_t i);
    const T& operator[](size_t i)const;

    void push_back(T t);
    T* begin(){return data_;}
    const T* begin()const;
    T* end(){return data_+size_;}
    const T* end()const; 
};

//返回数组大小
template<typename T>
size_t MyVector<T>::size()const{
    return size_;
}

//返回数组容量
template<typename T>
size_t MyVector<T>::capacity()const{
    return capacity_;
}

//判断非空
template<typename T>
bool MyVector<T>::empty()const{
    return size_==0;
}

//[]重载，两个版本，一个const一个非const
template<typename T>
T& MyVector<T>::operator[](size_t i){
    return data_[i];
}

template<typename T>
const T& MyVector<T>::operator[](size_t i)const{
    return data_[i];
}

//push_back添加函数，如果容量满了就扩容
template<typename T>
void MyVector<T>::push_back(T t){
    if(size_==capacity_){
        size_t newcap=capacity_==0?1:capacity_*2;
        T* p=new T[newcap];
        for(size_t i=0;i<size_;i++){
            p[i]=data_[i];
        }
        delete[] data_;
        data_=p;
        capacity_=newcap;
    }
    data_[size_]=t;
    size_++;
}

//返回第一个元素迭代器，const版本
template<typename T>
const T* MyVector<T>::begin()const{
    return data_;
}

//返回最后一个元素的下一位的迭代器，const版本
template<typename T>
const T* MyVector<T>::end()const{
    return data_+size_;
}

int main(){
    MyVector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
        cout<<v.size()<<" "<<v.capacity()<<endl; 
    }
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    v.push_back(v[0]);
    cout<<v.size()<<" "<<v[9]<<" "<<v[10]<<endl;
    
    MyVector<int> a;
    for(int i=0;i<6;i++){
        a.push_back(i);
    }
    MyVector<int> b=a;
    b.push_back(99);
    cout<<b.size()<<endl;

    MyVector<int> c;
    c=a;
    cout<<c.size()<<endl;

    a=a;
    cout<<a.size()<<endl;

    MyVector<int> empty;
    c=empty;
    cout<<c.size()<<endl;

    return 0;
}